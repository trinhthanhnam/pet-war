// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterAnimInstance.h"
#include "BlasterCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBlasterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	blasterCharacter = Cast<ABlasterCharacter>(TryGetPawnOwner());
}

void UBlasterAnimInstance::NativeUpdateAnimation(float deltaTime)
{
	bool alert = false;
	Super::NativeUpdateAnimation(deltaTime);
	if (blasterCharacter == nullptr) {
		blasterCharacter = Cast<ABlasterCharacter>(TryGetPawnOwner());	
	}
	if (blasterCharacter == nullptr) {
		if (GEngine && alert) {
			GEngine->AddOnScreenDebugMessage(
				-1, 150.f, FColor::Orange,
				FString(TEXT("NativeUpdateAnimation: blasterCharacter can not init even try many times!"))
			);
		}
		return;
	}
	FVector velocity = blasterCharacter->GetVelocity();
	velocity.Z = 0.f;
	speedOfCharacter = velocity.Size();
	bIsInAir = blasterCharacter->GetCharacterMovement()->IsFalling();
	bIsAccelerating = blasterCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
	bIsWeaponEquipped = blasterCharacter->IsWeaponEquipped();
	bIsCrouch = blasterCharacter->bIsCrouched;
	bAiming = blasterCharacter->IsAiming();

	// YawOffet for strafing
	FRotator aimRotation = blasterCharacter->GetBaseAimRotation();
	FRotator movementRotation = UKismetMathLibrary::MakeRotFromX(blasterCharacter->GetVelocity());
	FRotator tmp = UKismetMathLibrary::NormalizedDeltaRotator(movementRotation, aimRotation);
	deltaRotatorThisFrame = FMath::RInterpTo(deltaRotatorThisFrame, tmp, deltaTime, 10.f);
	yawOffset = deltaRotatorThisFrame.Yaw;

	// Lean for strafing
	characterRotatorLastFrame = characterRotatorThisFrame;
	characterRotatorThisFrame = blasterCharacter->GetActorRotation();
	const FRotator delta = UKismetMathLibrary::NormalizedDeltaRotator(characterRotatorThisFrame, characterRotatorLastFrame);
	const float target = delta.Yaw / deltaTime;
	const float interp = FMath::FInterpTo(lean, target, deltaTime, 5.f);
	lean = FMath::Clamp(interp, -90.f, 90.f);

	if (blasterCharacter->HasAuthority() == false && blasterCharacter->IsLocallyControlled() == false) {
		// player is client
		UE_LOG(LogTemp, Warning, TEXT("AimRotation Yaw %f | MovementRotation Yaw %f | Lean %f"), aimRotation.Yaw, movementRotation.Yaw, lean);
	}
}

