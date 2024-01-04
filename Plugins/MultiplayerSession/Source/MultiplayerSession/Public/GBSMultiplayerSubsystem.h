// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "GBSMultiplayerSubsystem.generated.h"


// declareing our custom delegates for menu class to bind callbacks with GBSMultiplayerSubsystem
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnCreateSessionComplete, bool, bWasSuccessful);
DECLARE_MULTICAST_DELEGATE_TwoParams(FMultiplayerOnFindSessionComplete, const TArray<FOnlineSessionSearchResult>& sessionResults, bool bWasSuccessful);
DECLARE_MULTICAST_DELEGATE_OneParam(FMultiplayerOnJoinSessionComplete, EOnJoinSessionCompleteResult::Type results);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnDestroySessionComplete, bool, bWasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMultiplayerOnStartSessionComplete, bool, bWasSuccessful);

UCLASS()
class MULTIPLAYERSESSION_API UGBSMultiplayerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UGBSMultiplayerSubsystem();
	// handle session, include: create, find, join, start, destroy
	void CreateSession	(int32 numPulicConnection, FString matchType);
	void FindSession	(int32 maxSearchResults);
	void JoinSession	(const FOnlineSessionSearchResult& sessionResult);
	void StartSession	();
	void DestroySession	();

	// custom delegates for menu class to bind callbacks
	FMultiplayerOnCreateSessionComplete		multiplayerOnCreateSessionComplete;
	FMultiplayerOnFindSessionComplete		multiplayerOnFindSessionComplete;
	FMultiplayerOnJoinSessionComplete		multiplayerOnJoinSessionComplete;
	FMultiplayerOnDestroySessionComplete	multiplayerOnDestroySessionComplete;
	FMultiplayerOnStartSessionComplete		multiplayerOnStartSessionComplete;

protected:
	// internal callback for session delegate list, this dont need to be call outsite this class
	void OnCreateSessionComplete	(FName sessionName, bool bWasSuccessful);
	void OnFindSessionComplete		(bool bWasSuccessful);
	void OnJoinSessionComplete		(FName sessionName, EOnJoinSessionCompleteResult::Type result);
	void OnStartSessionComplete		(FName sessionName, bool bWasSuccessful);
	void OnDestroySessionComplete	(FName sessionName, bool bWasSuccessful);

private:
	// pointer list
	IOnlineSessionPtr					sessionInterface;
	TSharedPtr<FOnlineSessionSettings>	lastSessionSettings;
	TSharedPtr<FOnlineSessionSearch>	lastSessionSearch;

	// delegate and handle list for session status
	FOnCreateSessionCompleteDelegate	createSessionCompleteDelegate;
	FDelegateHandle						createSessionCompleteDelegateHandle;
	bool								bCreateSessionOnDestroy{false};

	FOnFindSessionsCompleteDelegate		findSessionCompleteDelegate;
	FDelegateHandle						findSessionCompleteDelegateHandle;

	FOnJoinSessionCompleteDelegate		joinSessionCompleteDelegate;
	FDelegateHandle						joinSessionCompleteDelegateHandle;

	FOnStartSessionCompleteDelegate		startSessionCompleteDelegate;
	FDelegateHandle						startSessionCompleteDelegateHandle;

	FOnDestroySessionCompleteDelegate	destroySessionCompleteDelegate;
	FDelegateHandle						destroySessionCompleteDelegateHandle;

	// session status
	int32								lastNumPublicConnection;
	FString								lastMatchType;
};
