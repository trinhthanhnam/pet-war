// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BlasterCharacter.generated.h"

UCLASS()
class PETWAR_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABlasterCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostInitializeComponents() override;
protected:
	virtual void BeginPlay() override;

public:
	void SetOverlappingWeapon(AGBSWeapon* weapon);
	bool IsWeaponEquipped();
	bool IsAiming();

protected:
	void MoveForward				(float value);
	void MoveRight					(float value);
	void Turn						(float value);
	void Lookup						(float value);
	void EquipFirstWeaponPressed	();
	void CrouchPressed				();
	void AimButtonPressed			();
	void AimButtonReleased			();
	
private:
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent*	cameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent*		followCamera;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true")) 
	class UWidgetComponent*		overheadWidget;

	UPROPERTY(ReplicatedUsing = OnRep_OverlapingFirstWeapon)
	class AGBSWeapon*			overlapFirstWeapon;

	UFUNCTION()
	void OnRep_OverlapingFirstWeapon(AGBSWeapon* lastWeapon);

	UPROPERTY(VisibleAnywhere)
	class UBlasterFirstComponent* combatBlasterHaveFirstWeapon;

	UFUNCTION(Server, Reliable)
	void ServerEquipButtonPressed();

};
