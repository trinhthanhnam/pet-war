// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BlasterFirstComponent.generated.h"

class AGBSWeapon;
class ABlasterCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PETWAR_API UBlasterFirstComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBlasterFirstComponent();
	friend class ABlasterCharacter;	// ABlasterCharacter will have full access to this class
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void EquipFirstWeapon(AGBSWeapon* weaponToEquip);
private:
	ABlasterCharacter*	character;

	UPROPERTY(ReplicatedUsing = OnRep_EquippedFirstWeapon)
	AGBSWeapon*	firstWeapon;
	UPROPERTY(Replicated)
	bool		bAiming;

protected:
	virtual void BeginPlay() override;
	void SetAiming(bool bIsAiming);
	UFUNCTION(Server, Reliable)
	void ServerSetAiming(bool bIsAiming);
	UFUNCTION()
	void OnRep_EquippedFirstWeapon();
};
