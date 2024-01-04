// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterSecondComponent.h"

UBlasterSecondComponent::UBlasterSecondComponent()
{
	PrimaryComponentTick.bCanEverTick = true;


}

void UBlasterSecondComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UBlasterSecondComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

