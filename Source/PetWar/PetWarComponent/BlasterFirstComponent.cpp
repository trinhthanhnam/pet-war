// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterFirstComponent.h"
#include "PetWar/Weapon/GBSWeapon.h"
#include "PetWar/Weapon/GBSWeaponEnum.h"
#include "PetWar/Character/BlasterCharacter.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Components/SphereComponent.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
UBlasterFirstComponent::UBlasterFirstComponent()
{
	PrimaryComponentTick.bCanEverTick = false;


}

void UBlasterFirstComponent::BeginPlay()
{
	Super::BeginPlay();


}

void UBlasterFirstComponent::SetAiming(bool bIsAiming)
{
	bAiming = bIsAiming;	
	// no need to check other pointer cause this is deep functions
	ServerSetAiming(bIsAiming);
}

void UBlasterFirstComponent::OnRep_EquippedFirstWeapon()
{
	if (firstWeapon && character) {
		// player is client
		character->GetCharacterMovement()->bOrientRotationToMovement = false;
		character->bUseControllerRotationYaw = true;
	}
}

void UBlasterFirstComponent::ServerSetAiming_Implementation(bool bIsAiming)
{
	bAiming = bIsAiming;
}

void UBlasterFirstComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

void UBlasterFirstComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UBlasterFirstComponent, firstWeapon);
	DOREPLIFETIME(UBlasterFirstComponent, bAiming);
}

void UBlasterFirstComponent::EquipFirstWeapon(AGBSWeapon* weaponToEquip)
{
	bool alert = true;
	if (character == nullptr && weaponToEquip == nullptr) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Red,
				FString(TEXT("EquipMainWeapon: character or weapon is null"))
			);
		}
		return;
	}
	firstWeapon = weaponToEquip;
	firstWeapon->SetWeaponState(EWeaponState::EWS_Equipped);
	FName weaponSocketNameOnMesh = FName("blaster_right_hand_socket");
	const USkeletalMeshSocket* weaponSocket = character->GetMesh()->GetSocketByName(weaponSocketNameOnMesh);
	if (weaponSocket) {
		weaponSocket->AttachActor(firstWeapon, character->GetMesh());
	}
	firstWeapon->SetOwner(character);
	// player is host
	character->GetCharacterMovement()->bOrientRotationToMovement = false;
	character->bUseControllerRotationYaw = true;
}

