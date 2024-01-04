// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* newPlayer)
{
	Super::PostLogin(newPlayer);
	int32 numOfPlayer = 0;
	numOfPlayer = GameState.Get()->PlayerArray.Num();
	bool alert = true;
	if (numOfPlayer >= 2) {
		// when number of players gather enough to an certain number, all will move the match level
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Orange,
				FString(TEXT("PostLogin: Enough players to begin the match! Let's go!"))
			);
		}
		UWorld* world = GetWorld();
		if (world != nullptr) {
			bUseSeamlessTravel = true;
			// if map do not include in package build, player will return to startup map
			world->ServerTravel(FString("/Game/Maps/MatchDemo?listen"));
		}
	}
	else {
		FString tmp = FString::FromInt(numOfPlayer);
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString::Printf(TEXT("PostLogin: Do not enough players to begin the match! Please wait for more! Current players: %s"), *tmp)
			);
		}
	}
}
