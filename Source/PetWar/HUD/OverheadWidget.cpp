// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString txtDisplay)
{
	if (displayTxt != nullptr) {
		displayTxt->SetText(FText::FromString(txtDisplay));
	}
}

void UOverheadWidget::ShowPlayerLocalNetworkRole(APawn* inPawn)
{
	ENetRole localRole = inPawn->GetLocalRole();
	FString roleName;
	if (localRole == ENetRole::ROLE_Authority) {
		roleName = FString("Authority");
	}
	else if (localRole == ENetRole::ROLE_AutonomousProxy) {
		roleName = FString("AutonomousProxy");
	}
	else if (localRole == ENetRole::ROLE_MAX) {
		roleName = FString("MAX");
	}
	else if (localRole == ENetRole::ROLE_None) {
		roleName = FString("None");
	}
	else if (localRole == ENetRole::ROLE_SimulatedProxy) {
		roleName = FString("SimulatedProxy");
	}
	else {
		roleName = FString("Error");
	}
	FString localRoleName = FString::Printf(TEXT("Local Role is: %s"), *roleName);
	SetDisplayText(localRoleName);
}

void UOverheadWidget::ShowPlayerRemoteNetworkRole(APawn* inPawn)
{
	ENetRole remoteRole = inPawn->GetRemoteRole();
	FString roleName;
	if (remoteRole == ENetRole::ROLE_Authority) {
		roleName = FString("Authority");
	}
	else if (remoteRole == ENetRole::ROLE_AutonomousProxy) {
		roleName = FString("AutonomousProxy");
	}
	else if (remoteRole == ENetRole::ROLE_MAX) {
		roleName = FString("MAX");
	}
	else if (remoteRole == ENetRole::ROLE_None) {
		roleName = FString("None");
	}
	else if (remoteRole == ENetRole::ROLE_SimulatedProxy) {
		roleName = FString("SimulatedProxy");
	}
	else {
		roleName = FString("Error");
	}
	FString remoteRoleName = FString::Printf(TEXT("Remote Role is: %s"), *roleName);
	SetDisplayText(remoteRoleName);
}

void UOverheadWidget::OnLevelRemovedFromWorld(ULevel* level, UWorld* world)
{
	RemoveFromParent();
	Super::OnLevelRemovedFromWorld(level, world);
}
