// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverheadWidget.generated.h"

/**
 * 
 */
UCLASS()
class PETWAR_API UOverheadWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* displayTxt;

	void SetDisplayText(FString txtDisplay);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerLocalNetworkRole(APawn* inPawn);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerRemoteNetworkRole(APawn* inPawn);

protected:
	virtual void OnLevelRemovedFromWorld(ULevel* level, UWorld* world) override;


private:



};
