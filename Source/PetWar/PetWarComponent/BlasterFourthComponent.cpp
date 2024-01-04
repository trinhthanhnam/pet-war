// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterFourthComponent.h"

UBlasterFourthComponent::UBlasterFourthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UBlasterFourthComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UBlasterFourthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

