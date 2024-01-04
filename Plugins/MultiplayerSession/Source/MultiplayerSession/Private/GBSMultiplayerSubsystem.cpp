// Fill out your copyright notice in the Description page of Project Settings.


#include "GBSMultiplayerSubsystem.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

UGBSMultiplayerSubsystem::UGBSMultiplayerSubsystem():
	createSessionCompleteDelegate	(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateSessionComplete)),
	findSessionCompleteDelegate		(FOnFindSessionsCompleteDelegate::CreateUObject(this, &ThisClass::OnFindSessionComplete)),
	joinSessionCompleteDelegate		(FOnJoinSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnJoinSessionComplete)),
	startSessionCompleteDelegate	(FOnStartSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnStartSessionComplete)),
	destroySessionCompleteDelegate	(FOnDestroySessionCompleteDelegate::CreateUObject(this, &ThisClass::OnDestroySessionComplete))
{	
	IOnlineSubsystem* subsystem = IOnlineSubsystem::Get();
	if (subsystem != nullptr) {
		sessionInterface = subsystem->GetSessionInterface();
	}
}

void UGBSMultiplayerSubsystem::CreateSession(int32 numPulicConnection, FString matchType)
{
	bool alert = true;

	if (sessionInterface.IsValid()) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Orange,
				FString(TEXT("CreateSession: Session already exits! Destroy now!"))
			);
		}
		auto existingSession = sessionInterface->GetNamedSession(NAME_GameSession);
		if (existingSession != nullptr) {
			bCreateSessionOnDestroy = true;
			lastNumPublicConnection = numPulicConnection;
			lastMatchType = matchType;
			DestroySession();
		}
	}
	else {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Orange,
				FString(TEXT("CreateSession: Session created now!"))
			);
		}
	}

	// store the delegate in concrete delegate handle so we can later remove it from the delegate list
	createSessionCompleteDelegateHandle = sessionInterface->AddOnCreateSessionCompleteDelegate_Handle(createSessionCompleteDelegate);

	lastSessionSettings = MakeShareable(new FOnlineSessionSettings());
	lastSessionSettings->bIsLANMatch = IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true : false;
	lastSessionSettings->NumPublicConnections = numPulicConnection;
	lastSessionSettings->bAllowJoinInProgress = true;
	lastSessionSettings->bAllowJoinViaPresence = true;
	lastSessionSettings->bShouldAdvertise = true;
	lastSessionSettings->bUsesPresence = true;
	lastSessionSettings->bUseLobbiesIfAvailable = true;	// must have for UE5.0
	lastSessionSettings->Set(FName("matchType"), matchType, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
	lastSessionSettings->BuildUniqueId = 1;

	const ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();

	bool result = sessionInterface->CreateSession(*localPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *lastSessionSettings);
	if (result == false) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("CreateSession: Session can not created!"))
			);
		}
		sessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(createSessionCompleteDelegateHandle);
		// broacast our own custom delegates
		multiplayerOnCreateSessionComplete.Broadcast(false);
	}
	else {
		if (GEngine && alert) {
			FString tmp = FString::FromInt(numPulicConnection);
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString::Printf(TEXT("CreateSession: Session created successful with connection limit is: %s"), *tmp)
			);
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				matchType
			);
		}
	}
}

void UGBSMultiplayerSubsystem::FindSession(int32 maxSearchResults)
{
	bool alert = true;
	if(sessionInterface.IsValid() == false) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("FindSession: Session interface is invalid! Stop now!"))
			);
		}
		return;
	}
	findSessionCompleteDelegateHandle = sessionInterface->AddOnFindSessionsCompleteDelegate_Handle(findSessionCompleteDelegate);

	lastSessionSearch = MakeShareable(new FOnlineSessionSearch());
	lastSessionSearch->MaxSearchResults = maxSearchResults;
	lastSessionSearch->bIsLanQuery = IOnlineSubsystem::Get()->GetSubsystemName() == "NULL" ? true : false;
	lastSessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

	const ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	bool isValid = sessionInterface->FindSessions(*localPlayer->GetPreferredUniqueNetId(), lastSessionSearch.ToSharedRef());
	if (isValid == false) {
		// clear delegate from list
		sessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(findSessionCompleteDelegateHandle);
		multiplayerOnFindSessionComplete.Broadcast(TArray<FOnlineSessionSearchResult>(), false);

		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("FindSession: Session search result is empty! Stop now!"))
			);
		}
		return;
	}
	else {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("FindSession: Session found! Process to join!"))
			);
			
			FString length;
			length = FString::FromInt(lastSessionSearch->SearchResults.Num());
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				length
			);
		}
	}
}

void UGBSMultiplayerSubsystem::JoinSession(const FOnlineSessionSearchResult& sessionResult)
{
	bool alert = true;
	if (sessionInterface.IsValid() == false) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("JoinSession: sessionInterface is invalid! Stop now!"))
			);
		}
		multiplayerOnJoinSessionComplete.Broadcast(EOnJoinSessionCompleteResult::UnknownError);
		return;
	}

	joinSessionCompleteDelegateHandle = sessionInterface->AddOnJoinSessionCompleteDelegate_Handle(joinSessionCompleteDelegate);
	const ULocalPlayer* localPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	bool isValid = sessionInterface->JoinSession(*localPlayer->GetPreferredUniqueNetId(), NAME_GameSession, sessionResult);
	if (isValid == false) {
		sessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(joinSessionCompleteDelegateHandle);
		multiplayerOnJoinSessionComplete.Broadcast(EOnJoinSessionCompleteResult::UnknownError);
	}
	else {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("JoinSession: Joining session proccessing ..."))
			);
		}
	}
}

void UGBSMultiplayerSubsystem::StartSession()
{
}

void UGBSMultiplayerSubsystem::DestroySession()
{
	bool alert = true;
	if (sessionInterface.IsValid()) {
		destroySessionCompleteDelegateHandle = sessionInterface->AddOnDestroySessionCompleteDelegate_Handle(destroySessionCompleteDelegate);
		bool valid = sessionInterface->DestroySession(NAME_GameSession);
		if (valid == false) {
			if (GEngine && alert) {
				GEngine->AddOnScreenDebugMessage(
					-1, 150.f, FColor::Red,
					FString(TEXT("DestroySession: Failed to destroy session!"))
				);
			}
			sessionInterface->ClearOnDestroySessionCompleteDelegate_Handle(destroySessionCompleteDelegateHandle);
			multiplayerOnDestroySessionComplete.Broadcast(false);
		}
		else {
			if (GEngine && alert) {
				GEngine->AddOnScreenDebugMessage(
					-1, 150.f, FColor::Green,
					FString(TEXT("DestroySession: Destroy session successful!"))
				);
			}
		}
	}
	else {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("DestroySession: sessionInterface is invalid!"))
			);
		}
		multiplayerOnDestroySessionComplete.Broadcast(false);
		return;
	}
}

void UGBSMultiplayerSubsystem::OnCreateSessionComplete(FName sessionName, bool bWasSuccessful)
{
	bool alert = true;
	if (GEngine && alert) {
		GEngine->AddOnScreenDebugMessage(
			-1, 150.f, FColor::Orange,
			FString(TEXT("OnCreateSessionComplete is called!"))
		);
	}
	if (sessionInterface != nullptr) {
		sessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(createSessionCompleteDelegateHandle);
	}
	if (bWasSuccessful == true) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("OnCreateSessionComplete: Create session complete!"))
			);
		}
	}
	else
	{
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("OnCreateSessionComplete: Create session failed!"))
			);
		}
	}
	multiplayerOnCreateSessionComplete.Broadcast(bWasSuccessful);
}

void UGBSMultiplayerSubsystem::OnFindSessionComplete(bool bWasSuccessful)
{
	if (sessionInterface != nullptr) {
		sessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(findSessionCompleteDelegateHandle);
	}
	if (lastSessionSearch->SearchResults.Num() <= 0) {
		// there no result
		multiplayerOnFindSessionComplete.Broadcast(TArray<FOnlineSessionSearchResult>(), false);
	}
	else {
		multiplayerOnFindSessionComplete.Broadcast(lastSessionSearch->SearchResults, bWasSuccessful);
	}
}

void UGBSMultiplayerSubsystem::OnJoinSessionComplete(FName sessionName, EOnJoinSessionCompleteResult::Type result)
{
	bool alert = true;
	if (sessionInterface != nullptr) {
		sessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(joinSessionCompleteDelegateHandle);
	}
	
	if (result != EOnJoinSessionCompleteResult::UnknownError) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("OnJoinSessionComplete: Join session complete!"))
			);
		}
	}
	else
	{
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("OnJoinSessionComplete: Join session failed!"))
			);
		}
	}
	multiplayerOnJoinSessionComplete.Broadcast(result);
}

void UGBSMultiplayerSubsystem::OnStartSessionComplete(FName sessionName, bool bWasSuccessful)
{
}

void UGBSMultiplayerSubsystem::OnDestroySessionComplete(FName sessionName, bool bWasSuccessful)
{
	if (sessionInterface.IsValid()) {
		sessionInterface->ClearOnDestroySessionCompleteDelegate_Handle(destroySessionCompleteDelegateHandle);
	}
	if (bWasSuccessful && bCreateSessionOnDestroy) {
		// complete destroy session successful, then create new one
		bCreateSessionOnDestroy = false;
		CreateSession(lastNumPublicConnection, lastMatchType);
		multiplayerOnDestroySessionComplete.Broadcast(bWasSuccessful);
	}
}
