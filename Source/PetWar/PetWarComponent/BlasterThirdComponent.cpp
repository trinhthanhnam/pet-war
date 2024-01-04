// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterThirdComponent.h"

UBlasterThirdComponent::UBlasterThirdComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UBlasterThirdComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UBlasterThirdComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

