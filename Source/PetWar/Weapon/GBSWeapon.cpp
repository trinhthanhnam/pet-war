// Fill out your copyright notice in the Description page of Project Settings.


#include "GBSWeapon.h"
#include "GBSWeaponEnum.h"
#include "UObject/Object.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "PetWar/Character/BlasterCharacter.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AGBSWeapon::AGBSWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
	// setup weapon mesh
	weaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	weaponMesh->SetupAttachment(RootComponent);
	// weaponMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);	//do not work
	SetRootComponent(weaponMesh);
	// setup weapon mesh collision rule
	weaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	weaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
	weaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	// setup weapon mesh area
	areaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaSphere"));
	areaSphere->SetupAttachment(RootComponent);
	// areaSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);	//do not work
	// setup weapon mesh area overlap coliision
	areaSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	areaSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	// setup pickup widget
	pickupWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickupWidget"));	// must exacly PickupWidget or error
	pickupWidget->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AGBSWeapon::BeginPlay()
{
	Super::BeginPlay();
	bool alert = true;
	if (GetLocalRole() == ENetRole::ROLE_Authority) {
		areaSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		areaSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
		areaSphere->OnComponentBeginOverlap.AddDynamic(this, &AGBSWeapon::OnSphereOverlap);
		areaSphere->OnComponentEndOverlap.AddDynamic(this, &AGBSWeapon::OnSphereEndOverlap);
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("BeginPlay: Weapon Overlap being set!"))
			);
		}
	}
	else {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("BeginPlay: Player is client and have no authority to pickup weapon! Waiting for RPC call to host ..."))
			);
		}
	}
	
	if (pickupWidget != nullptr) {
		pickupWidget->SetVisibility(false);
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("BeginPlay: Weapon PickupWidget text is hidden!"))
			);
		}
	}
	else {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("BeginPlay: pickupWidget is null!"))
			);
		}
	}
	
}

// Called every frame
void AGBSWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGBSWeapon::OnSphereOverlap(
	UPrimitiveComponent*	overlapComponent, 
	AActor*					otherActor, 
	UPrimitiveComponent*	otherComp, 
	int32					otherBodyIndex, 
	bool					bFromSweep, 
	const FHitResult&		sweepResult)
{
	bool alert = true;
	ABlasterCharacter* character = Cast<ABlasterCharacter>(otherActor);
	if (character) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("OnSphereOverlap: Weapon is overlap!"))
			);
		}
		character->SetOverlappingWeapon(this);
	}
	else {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("OnSphereOverlap: Player or pickupWidget is null!"))
			);
		}
	}
}

void AGBSWeapon::OnSphereEndOverlap(
	UPrimitiveComponent*	overlapComponent, 
	AActor*					otherActor, 
	UPrimitiveComponent*	otherComp, 
	int32					otherBodyIndex)
{
	bool alert = true;
	ABlasterCharacter* character = Cast<ABlasterCharacter>(otherActor);
	if (character) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("OnSphereEndOverlap: Weapon is overlap!"))
			);
		}
		character->SetOverlappingWeapon(nullptr);
	}
}

void AGBSWeapon::ShowPickupWidget(bool bShowWidget)
{
	if (pickupWidget) {
		pickupWidget->SetVisibility(bShowWidget);
	}
}

void AGBSWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	// register weapon states
	DOREPLIFETIME(AGBSWeapon, weaponState);
}

void AGBSWeapon::SetWeaponState(EWeaponState state)
{
	bool alert = true;
	// run on server
	weaponState = state;
	if (weaponState == EWeaponState::EWS_Equipped) {
		ShowPickupWidget(false);
		GetAreaSphere()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("SetWeaponState: character take on weapon!"))
			);
		}
	}
	else if (weaponState == EWeaponState::EWS_Initial) {

	}
	
}

EWeaponState AGBSWeapon::GetWeaponState()
{
	return weaponState;
}

void AGBSWeapon::OnRep_WeaponState()
{
	// run on client
	if (weaponState == EWeaponState::EWS_Equipped) {
		ShowPickupWidget(false);
	}
	else if (weaponState == EWeaponState::EWS_Initial) {

	}
}
