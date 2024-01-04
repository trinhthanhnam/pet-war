// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuLobby.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSESSION_API UMenuLobby : public UUserWidget
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable)
	void MenuSetup(int32 numOfConnection = 4, FString theMatchType = FString(TEXT("FreeForAll")), FString path = FString(TEXT("/Game/ThirdPerson/Maps/Lobby")));


protected:
	virtual bool Initialize() override;
	virtual void OnLevelRemovedFromWorld(ULevel* inLevel, UWorld* world) override;

	// callback for custom delegates on UGBSMultiplayerSubsystem
	// UFUNCTION is needed for dynamic multicast function
	UFUNCTION()
	void OnCreateSession(bool bWasSuccessful);
	void OnFindSession(const TArray<FOnlineSessionSearchResult>& sessionResults, bool bWasSuccessful);
	void OnJoinSession(EOnJoinSessionCompleteResult::Type results);
	UFUNCTION()
	void OnDestroySession(bool bWasSuccessful);
	UFUNCTION()
	void OnStartSession(bool bWasSuccessful);

private:
	// NOTE: variable name must be the same between C++ and Blueprint
	UPROPERTY(meta = (BindWidget))
	class UButton* HostBtn;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinBtn;

	UFUNCTION()
	void HostBtnClick();

	UFUNCTION()
	void JoinBtnClick();

	void MenuDismiss();

	// pointer to the subsystem handle all online session fuctionality
	class UGBSMultiplayerSubsystem* multiplayerSessionSubsystem;

	// global management variables
	int32 numPublicConnection{10};
	FString matchType{TEXT("GBSDemoFreeForAll")};
	FString lobbyPath{TEXT("/Game/Maps/Lobby")};
};
