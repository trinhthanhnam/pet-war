#pragma once

UENUM(BlueprintType)
enum class EWeaponState : uint8 {
	EWS_Initial		UMETA(DisplayName = "Initial State"),
	EWS_Equipped	UMETA(DisplayName = "Equipped"),
	EWS_Dropped		UMETA(DisplayName = "Dropped"),
	EWS_Max			UMETA(DisplayName = "Default Max"),
};