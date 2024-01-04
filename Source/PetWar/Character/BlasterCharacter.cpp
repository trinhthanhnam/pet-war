// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetComponent.h"
#include "Net/UnrealNetwork.h"
#include "PetWar/Weapon/GBSWeapon.h"
#include "PetWar/Weapon/GBSWeaponEnum.h"
#include "PetWar/PetWarComponent/BlasterFirstComponent.h"

ABlasterCharacter::ABlasterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(GetMesh());
	cameraBoom->TargetArmLength = 0.f;
	cameraBoom->bUsePawnControlRotation = true;

	followCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	followCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);
	followCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	overheadWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("OverheadWidget"));
	overheadWidget->SetupAttachment(RootComponent);

	combatBlasterHaveFirstWeapon = CreateDefaultSubobject<UBlasterFirstComponent>(TEXT("CombatBlaster"));
	combatBlasterHaveFirstWeapon->SetIsReplicated(true);

	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;
}

void ABlasterCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	//DOREPLIFETIME(ABlasterCharacter, overlapMainWeapon);								// replicated to all players
	DOREPLIFETIME_CONDITION(ABlasterCharacter, overlapFirstWeapon, COND_OwnerOnly);		// replicated with condition
}



void ABlasterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlasterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABlasterCharacter::OnRep_OverlapingFirstWeapon(AGBSWeapon* lastWeapon)
{
	if (overlapFirstWeapon) {
		overlapFirstWeapon->ShowPickupWidget(true);
	}
	if (lastWeapon) {
		lastWeapon->ShowPickupWidget(false);
	}
}

void ABlasterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// bind input
	PlayerInputComponent->BindAction("jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("moveforward", this, &ThisClass::MoveForward);
	PlayerInputComponent->BindAxis("moveright", this, &ThisClass::MoveRight);
	PlayerInputComponent->BindAxis("turn", this, &ThisClass::Turn);
	PlayerInputComponent->BindAxis("lookup", this, &ThisClass::Lookup);
	PlayerInputComponent->BindAction("btn1", IE_Pressed, this, &ThisClass::EquipFirstWeaponPressed);
	PlayerInputComponent->BindAction("crouch", IE_Pressed, this, &ThisClass::CrouchPressed);
	PlayerInputComponent->BindAction("aim", IE_Pressed, this, &ThisClass::AimButtonPressed);
	PlayerInputComponent->BindAction("aim", IE_Released, this, &ThisClass::AimButtonReleased);
}

void ABlasterCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (combatBlasterHaveFirstWeapon) {
		combatBlasterHaveFirstWeapon->character = this;
	}
}

void ABlasterCharacter::EquipFirstWeaponPressed()
{
	bool alert = true;
	if (combatBlasterHaveFirstWeapon) {
		if(combatBlasterHaveFirstWeapon->firstWeapon) {
			if (combatBlasterHaveFirstWeapon->firstWeapon->GetWeaponState() == EWeaponState::EWS_Equipped) {
				if (GEngine && alert) {
					GEngine->AddOnScreenDebugMessage(
						-1, 150.f, FColor::Red,
						FString(TEXT("EquipFirstWeaponPressed: Host already have first weapon, do nothing!"))
					);
				}
				return;
			}
		}
		if (HasAuthority()) {
			if (GEngine && alert) {
				GEngine->AddOnScreenDebugMessage(
					-1, 150.f, FColor::Green,
					FString(TEXT("EquipFirstWeaponPressed: pick first weapon is pressed on host!"))
				);
			}
			// player is host
			if (!overlapFirstWeapon) {
				if (GEngine && alert) {
					GEngine->AddOnScreenDebugMessage(
						-1, 150.f, FColor::Red,
						FString(TEXT("EquipFirstWeaponPressed: Host is not nearby the first weapon, do nothing!"))
					);
				}
				return;
			}
			combatBlasterHaveFirstWeapon->EquipFirstWeapon(overlapFirstWeapon);
		}
		else {
			// player is client
			ServerEquipButtonPressed();
		}
	}
}

void ABlasterCharacter::ServerEquipButtonPressed_Implementation()
{
	bool alert = true;
	if (combatBlasterHaveFirstWeapon) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Green,
				FString(TEXT("ServerEquipButtonPressed_Implementation (RPC): pick first weapon is pressed on client!"))
			);
		}
		if (combatBlasterHaveFirstWeapon->firstWeapon) {
			if (combatBlasterHaveFirstWeapon->firstWeapon->GetWeaponState() == EWeaponState::EWS_Equipped) {
				if (GEngine && alert) {
					GEngine->AddOnScreenDebugMessage(
						-1, 150.f, FColor::Red,
						FString(TEXT("ServerEquipButtonPressed_Implementation (RPC): Client already have first weapon!"))
					);
				}
				return;
			}
		}
		if (!overlapFirstWeapon) {
			if (GEngine && alert) {
				GEngine->AddOnScreenDebugMessage(
					-1, 150.f, FColor::Red,
					FString(TEXT("ServerEquipButtonPressed_Implementation (RPC): Client is not nearby the first weapon, do nothing!"))
				);
			}
			return;
		}
		combatBlasterHaveFirstWeapon->EquipFirstWeapon(overlapFirstWeapon);
	}
}

void ABlasterCharacter::CrouchPressed()
{
	if (bIsCrouched) {
		UnCrouch();
	}
	else {
		Crouch();
	}
	
}

void ABlasterCharacter::AimButtonPressed()
{
	if (combatBlasterHaveFirstWeapon) {
		combatBlasterHaveFirstWeapon->SetAiming(true);
	}
}

void ABlasterCharacter::AimButtonReleased()
{
	if (combatBlasterHaveFirstWeapon) {
		combatBlasterHaveFirstWeapon->SetAiming(false);
	}
}

void ABlasterCharacter::SetOverlappingWeapon(AGBSWeapon* weapon)
{
	if (overlapFirstWeapon) {
		overlapFirstWeapon->ShowPickupWidget(false);
	}
	overlapFirstWeapon = weapon; 
	if (IsLocallyControlled() == true) {
		// true if this player is the host, then call show text because the callback rep notify only call in client
		if (overlapFirstWeapon) {
			overlapFirstWeapon->ShowPickupWidget(true);
		}
	}
}

bool ABlasterCharacter::IsWeaponEquipped()
{
	if (combatBlasterHaveFirstWeapon) {
		if (combatBlasterHaveFirstWeapon->firstWeapon)
			return true;
	}
	return false;
}

bool ABlasterCharacter::IsAiming()
{
	if (combatBlasterHaveFirstWeapon) {
		if (combatBlasterHaveFirstWeapon->bAiming)
			return true;
	}
	return false;
}

void ABlasterCharacter::MoveForward(float value)
{
	if (Controller != nullptr && value != 0.f) {
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, value);
	}
}

void ABlasterCharacter::MoveRight(float value)
{
	if (Controller != nullptr && value != 0.f) {
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction, value);
	}
}

void ABlasterCharacter::Turn(float value)
{
	AddControllerYawInput(value);
}

void ABlasterCharacter::Lookup(float value)
{
	AddControllerPitchInput(value);
}







