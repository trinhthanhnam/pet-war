// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MULTIPLAYERSESSION_GBSMultiplayerSubsystem_generated_h
#error "GBSMultiplayerSubsystem.generated.h already included, missing '#pragma once' in GBSMultiplayerSubsystem.h"
#endif
#define MULTIPLAYERSESSION_GBSMultiplayerSubsystem_generated_h

#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_12_DELEGATE \
struct _Script_MultiplayerSession_eventMultiplayerOnCreateSessionComplete_Parms \
{ \
	bool bWasSuccessful; \
}; \
static inline void FMultiplayerOnCreateSessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnCreateSessionComplete, bool bWasSuccessful) \
{ \
	_Script_MultiplayerSession_eventMultiplayerOnCreateSessionComplete_Parms Parms; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	MultiplayerOnCreateSessionComplete.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_15_DELEGATE \
struct _Script_MultiplayerSession_eventMultiplayerOnDestroySessionComplete_Parms \
{ \
	bool bWasSuccessful; \
}; \
static inline void FMultiplayerOnDestroySessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnDestroySessionComplete, bool bWasSuccessful) \
{ \
	_Script_MultiplayerSession_eventMultiplayerOnDestroySessionComplete_Parms Parms; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	MultiplayerOnDestroySessionComplete.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_16_DELEGATE \
struct _Script_MultiplayerSession_eventMultiplayerOnStartSessionComplete_Parms \
{ \
	bool bWasSuccessful; \
}; \
static inline void FMultiplayerOnStartSessionComplete_DelegateWrapper(const FMulticastScriptDelegate& MultiplayerOnStartSessionComplete, bool bWasSuccessful) \
{ \
	_Script_MultiplayerSession_eventMultiplayerOnStartSessionComplete_Parms Parms; \
	Parms.bWasSuccessful=bWasSuccessful ? true : false; \
	MultiplayerOnStartSessionComplete.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_SPARSE_DATA
#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_RPC_WRAPPERS
#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGBSMultiplayerSubsystem(); \
	friend struct Z_Construct_UClass_UGBSMultiplayerSubsystem_Statics; \
public: \
	DECLARE_CLASS(UGBSMultiplayerSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MultiplayerSession"), NO_API) \
	DECLARE_SERIALIZER(UGBSMultiplayerSubsystem)


#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_INCLASS \
private: \
	static void StaticRegisterNativesUGBSMultiplayerSubsystem(); \
	friend struct Z_Construct_UClass_UGBSMultiplayerSubsystem_Statics; \
public: \
	DECLARE_CLASS(UGBSMultiplayerSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MultiplayerSession"), NO_API) \
	DECLARE_SERIALIZER(UGBSMultiplayerSubsystem)


#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGBSMultiplayerSubsystem(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGBSMultiplayerSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGBSMultiplayerSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGBSMultiplayerSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGBSMultiplayerSubsystem(UGBSMultiplayerSubsystem&&); \
	NO_API UGBSMultiplayerSubsystem(const UGBSMultiplayerSubsystem&); \
public:


#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGBSMultiplayerSubsystem(UGBSMultiplayerSubsystem&&); \
	NO_API UGBSMultiplayerSubsystem(const UGBSMultiplayerSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGBSMultiplayerSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGBSMultiplayerSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGBSMultiplayerSubsystem)


#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_18_PROLOG
#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_SPARSE_DATA \
	FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_RPC_WRAPPERS \
	FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_INCLASS \
	FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_SPARSE_DATA \
	FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_INCLASS_NO_PURE_DECLS \
	FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MULTIPLAYERSESSION_API UClass* StaticClass<class UGBSMultiplayerSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_GBSMultiplayerSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
