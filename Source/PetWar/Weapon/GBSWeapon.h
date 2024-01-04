// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GBSWeaponEnum.h"
#include "Components/SphereComponent.h"
#include "GBSWeapon.generated.h"

UCLASS()
class PETWAR_API AGBSWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGBSWeapon();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void ShowPickupWidget(bool bShowWidget);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void SetWeaponState(EWeaponState state);
	EWeaponState GetWeaponState();
	FORCEINLINE USphereComponent* GetAreaSphere() const { return areaSphere; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnSphereOverlap(
		UPrimitiveComponent*	overlapComponent,
		AActor*					otherActor,
		UPrimitiveComponent*	otherComp,
		int32					otherBodyIndex,
		bool					bFromSweep,
		const FHitResult&		sweepResult
	);

	UFUNCTION()
	virtual void OnSphereEndOverlap(
		UPrimitiveComponent*	overlapComponent,
		AActor*					otherActor,
		UPrimitiveComponent*	otherComp,
		int32					otherBodyIndex
	);

private:
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	class USkeletalMeshComponent*	weaponMesh;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	class USphereComponent*			areaSphere;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	class UWidgetComponent*			pickupWidget;

	UPROPERTY(ReplicatedUsing = OnRep_WeaponState, VisibleAnywhere, Category = "Weapon Properties")
	EWeaponState					weaponState;

	UFUNCTION()
	void OnRep_WeaponState();
};
