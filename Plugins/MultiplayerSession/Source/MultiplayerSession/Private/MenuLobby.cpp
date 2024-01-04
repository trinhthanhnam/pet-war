// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuLobby.h"
#include "Components/Button.h"
#include "GBSMultiplayerSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"

void UMenuLobby::MenuSetup(int32 numOfConnection, FString theMatchType, FString path)
{
	AddToViewport();
	SetVisibility(ESlateVisibility::Visible);
	bIsFocusable = true;
	lobbyPath = FString::Printf(TEXT("%s?listen"), *path);
	UWorld* world = GetWorld();
	if (world != nullptr) {
		APlayerController* playerController = world->GetFirstPlayerController();
		if (playerController != nullptr) {
			FInputModeUIOnly inputModeData;
			inputModeData.SetWidgetToFocus(TakeWidget());
			inputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			playerController->SetInputMode(inputModeData);
			playerController->SetShowMouseCursor(true);
		}
	}

	UGameInstance* gameInstance = GetGameInstance();
	if (gameInstance != nullptr) {
		multiplayerSessionSubsystem = gameInstance->GetSubsystem<UGBSMultiplayerSubsystem>();
	}
	// binding dynamic delegates
	if (multiplayerSessionSubsystem != nullptr) {
		multiplayerSessionSubsystem->multiplayerOnCreateSessionComplete.AddDynamic(this, &ThisClass::OnCreateSession);
		multiplayerSessionSubsystem->multiplayerOnFindSessionComplete.AddUObject(this, &ThisClass::OnFindSession);
		multiplayerSessionSubsystem->multiplayerOnJoinSessionComplete.AddUObject(this, &ThisClass::OnJoinSession);
		multiplayerSessionSubsystem->multiplayerOnDestroySessionComplete.AddDynamic(this, &ThisClass::OnDestroySession);
		multiplayerSessionSubsystem->multiplayerOnStartSessionComplete.AddDynamic(this, &ThisClass::OnStartSession);
	}
}

bool UMenuLobby::Initialize()
{
	if (Super::Initialize() == false) {
		return false;

	}
	if (HostBtn != nullptr) {
		HostBtn->OnClicked.AddDynamic(this, &ThisClass::HostBtnClick);
	}
	if (JoinBtn != nullptr) {
		JoinBtn->OnClicked.AddDynamic(this, &ThisClass::JoinBtnClick);
	}
	return true;
}

void UMenuLobby::OnLevelRemovedFromWorld(ULevel* inLevel, UWorld* world)
{
	MenuDismiss();
	Super::OnLevelRemovedFromWorld(inLevel, world);
}

void UMenuLobby::OnCreateSession(bool bWasSuccessful)
{
	bool alert = true;
	if (bWasSuccessful) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("OnCreateSession is called!"))
			);
		}

		UWorld* world = GetWorld();
		if (world != nullptr) {
			if (GEngine && alert) {
				GEngine->AddOnScreenDebugMessage(
					-1, 150.f, FColor::Green,
					FString(TEXT("OnCreateSession: World pointer is valid, travel to the lobby path!"))
				);
			}
			world->ServerTravel(lobbyPath);
		}
		else {
			if (GEngine && alert) {
				GEngine->AddOnScreenDebugMessage(
					-1, 150.f, FColor::Red,
					FString(TEXT("OnCreateSession: World pointer is null"))
				);
			}
			HostBtn->SetIsEnabled(true);
		}
	}
	else {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("OnCreateSession: Failed to create session!"))
			);
		}
		HostBtn->SetIsEnabled(true);
	}
}

void UMenuLobby::OnFindSession(const TArray<FOnlineSessionSearchResult>& sessionResults, bool bWasSuccessful)
{
	bool alert = true;
	FString length;
	if (multiplayerSessionSubsystem == nullptr) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("OnFindSession: multiplayerSessionSubsystem is null, stop now!"))
			);
		}
		return;
	}
	else {
		length = FString::FromInt(sessionResults.Num());
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Orange,
				FString(TEXT("OnFindSession is called!"))
			);
			
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Orange,
				length
			);
			
		}
	}

	if (bWasSuccessful == false || sessionResults.Num() <= 0) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("OnFindSession: OnFindSessionComplete return false or empty, stop now!"))
			);
		}
		JoinBtn->SetIsEnabled(true);
		return;
	}

	for (auto result : sessionResults) {
		FString settingValue;
		result.Session.SessionSettings.Get(FName("matchType"), settingValue);
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Orange,
				settingValue
			);
		}
		if (settingValue == matchType) {
			if (GEngine && alert) {
				GEngine->AddOnScreenDebugMessage(
					-1, 150.f, FColor::Green,
					FString(TEXT("OnFindSession: Found this session for joining ->"))
				);
				GEngine->AddOnScreenDebugMessage(
					-1, 150.f, FColor::Green,
					FString(result.Session.GetSessionIdStr())
				);
			}
			multiplayerSessionSubsystem->JoinSession(result);
			// player just join only one session , so exit now!
			return;
		}
		else {
			if (GEngine && alert) {
				GEngine->AddOnScreenDebugMessage(
					-1, 150.f, FColor::Red,
					FString(TEXT("OnFindSession: Not found any session for joining!"))
				);
			}
			return;
		}
	}
	if (GEngine && alert) {
		GEngine->AddOnScreenDebugMessage(
			-1, 150.f, FColor::Red,
			FString(TEXT("OnFindSession: The loop do not found any session for joining!"))
		);
	}
}

void UMenuLobby::OnJoinSession(EOnJoinSessionCompleteResult::Type results)
{
	bool alert = true;
	GEngine->AddOnScreenDebugMessage(
		-1, 150.f, FColor::Green,
		FString(TEXT("OnJoinSession: the join session is called!"))
	);
	IOnlineSubsystem* subsystem = IOnlineSubsystem::Get();
	if (subsystem != nullptr) {
		IOnlineSessionPtr menuSessionInterface = subsystem->GetSessionInterface();
		if (menuSessionInterface.IsValid()) {
			FString address;
			menuSessionInterface->GetResolvedConnectString(NAME_GameSession, address);

			APlayerController* playerController = GetGameInstance()->GetFirstLocalPlayerController();
			if (playerController) {
				playerController->ClientTravel(address, ETravelType::TRAVEL_Absolute);
			}
		}
	}
	if (results != EOnJoinSessionCompleteResult::Success) {
		JoinBtn->SetIsEnabled(true);
	}
}

void UMenuLobby::OnDestroySession(bool bWasSuccessful)
{
}

void UMenuLobby::OnStartSession(bool bWasSuccessful)
{
}

void UMenuLobby::HostBtnClick()
{
	HostBtn->SetIsEnabled(false);
	bool alert = true;
	if (GEngine && alert) {
		GEngine->AddOnScreenDebugMessage(
		-1, 150.f, FColor::Orange,
			FString(TEXT("HostBtnClick: Host Button Clicked!"))
		);
	}

	if (multiplayerSessionSubsystem != nullptr) {
		GEngine->AddOnScreenDebugMessage(
			-1, 150.f, FColor::Orange,
			FString(TEXT("HostBtnClick: Begin create session!"))
		);
		multiplayerSessionSubsystem->CreateSession(numPublicConnection, matchType);
	}
}

void UMenuLobby::JoinBtnClick()
{
	JoinBtn->SetIsEnabled(false);
	bool alert = true;
	if (GEngine && alert) {
		GEngine->AddOnScreenDebugMessage(
			-1, 150.f, FColor::Orange,
			FString(TEXT("JoinBtnClick: Join Button Clicked!"))
		);
	}

	if (multiplayerSessionSubsystem != nullptr) {
		GEngine->AddOnScreenDebugMessage(
			-1, 150.f, FColor::Orange,
			FString(TEXT("JoinBtnClick: Begin find session!"))
		);
		multiplayerSessionSubsystem->FindSession(1000);
	}
	else {
		GEngine->AddOnScreenDebugMessage(
			-1, 150.f, FColor::Red,
			FString(TEXT("JoinBtnClick: multiplayerSessionSubsystem is invalid!"))
		);
	}
}

void UMenuLobby::MenuDismiss()
{
	RemoveFromParent();
	UWorld* world = GetWorld();
	if (world != nullptr) {
		APlayerController* playerController = world->GetFirstPlayerController();
		if (playerController != nullptr) {
			FInputModeGameOnly inputMode;
			playerController->SetInputMode(inputMode);
			playerController->SetShowMouseCursor(false);
		}
	}
}
