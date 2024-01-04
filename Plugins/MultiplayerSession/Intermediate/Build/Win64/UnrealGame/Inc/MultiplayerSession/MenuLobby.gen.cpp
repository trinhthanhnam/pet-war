// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultiplayerSession/Public/MenuLobby.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMenuLobby() {}
// Cross Module References
	MULTIPLAYERSESSION_API UClass* Z_Construct_UClass_UMenuLobby_NoRegister();
	MULTIPLAYERSESSION_API UClass* Z_Construct_UClass_UMenuLobby();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_MultiplayerSession();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UMenuLobby::execJoinBtnClick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JoinBtnClick();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMenuLobby::execHostBtnClick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HostBtnClick();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMenuLobby::execOnStartSession)
	{
		P_GET_UBOOL(Z_Param_bWasSuccessful);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnStartSession(Z_Param_bWasSuccessful);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMenuLobby::execOnDestroySession)
	{
		P_GET_UBOOL(Z_Param_bWasSuccessful);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnDestroySession(Z_Param_bWasSuccessful);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMenuLobby::execOnCreateSession)
	{
		P_GET_UBOOL(Z_Param_bWasSuccessful);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnCreateSession(Z_Param_bWasSuccessful);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMenuLobby::execMenuSetup)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_numOfConnection);
		P_GET_PROPERTY(FStrProperty,Z_Param_theMatchType);
		P_GET_PROPERTY(FStrProperty,Z_Param_path);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MenuSetup(Z_Param_numOfConnection,Z_Param_theMatchType,Z_Param_path);
		P_NATIVE_END;
	}
	void UMenuLobby::StaticRegisterNativesUMenuLobby()
	{
		UClass* Class = UMenuLobby::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HostBtnClick", &UMenuLobby::execHostBtnClick },
			{ "JoinBtnClick", &UMenuLobby::execJoinBtnClick },
			{ "MenuSetup", &UMenuLobby::execMenuSetup },
			{ "OnCreateSession", &UMenuLobby::execOnCreateSession },
			{ "OnDestroySession", &UMenuLobby::execOnDestroySession },
			{ "OnStartSession", &UMenuLobby::execOnStartSession },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMenuLobby_HostBtnClick_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMenuLobby_HostBtnClick_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MenuLobby.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuLobby_HostBtnClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuLobby, nullptr, "HostBtnClick", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMenuLobby_HostBtnClick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuLobby_HostBtnClick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMenuLobby_HostBtnClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuLobby_HostBtnClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMenuLobby_JoinBtnClick_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMenuLobby_JoinBtnClick_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MenuLobby.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuLobby_JoinBtnClick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuLobby, nullptr, "JoinBtnClick", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMenuLobby_JoinBtnClick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuLobby_JoinBtnClick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMenuLobby_JoinBtnClick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuLobby_JoinBtnClick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics
	{
		struct MenuLobby_eventMenuSetup_Parms
		{
			int32 numOfConnection;
			FString theMatchType;
			FString path;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_numOfConnection;
		static const UECodeGen_Private::FStrPropertyParams NewProp_theMatchType;
		static const UECodeGen_Private::FStrPropertyParams NewProp_path;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::NewProp_numOfConnection = { "numOfConnection", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MenuLobby_eventMenuSetup_Parms, numOfConnection), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::NewProp_theMatchType = { "theMatchType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MenuLobby_eventMenuSetup_Parms, theMatchType), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::NewProp_path = { "path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MenuLobby_eventMenuSetup_Parms, path), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::NewProp_numOfConnection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::NewProp_theMatchType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::NewProp_path,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::Function_MetaDataParams[] = {
		{ "CPP_Default_numOfConnection", "4" },
		{ "CPP_Default_path", "/Game/ThirdPerson/Maps/Lobby" },
		{ "CPP_Default_theMatchType", "FreeForAll" },
		{ "ModuleRelativePath", "Public/MenuLobby.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuLobby, nullptr, "MenuSetup", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::MenuLobby_eventMenuSetup_Parms), Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMenuLobby_MenuSetup()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuLobby_MenuSetup_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics
	{
		struct MenuLobby_eventOnCreateSession_Parms
		{
			bool bWasSuccessful;
		};
		static void NewProp_bWasSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
	{
		((MenuLobby_eventOnCreateSession_Parms*)Obj)->bWasSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MenuLobby_eventOnCreateSession_Parms), &Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::NewProp_bWasSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// callback for custom delegates on UGBSMultiplayerSubsystem\n// UFUNCTION is needed for dynamic multicast function\n" },
		{ "ModuleRelativePath", "Public/MenuLobby.h" },
		{ "ToolTip", "callback for custom delegates on UGBSMultiplayerSubsystem\nUFUNCTION is needed for dynamic multicast function" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuLobby, nullptr, "OnCreateSession", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::MenuLobby_eventOnCreateSession_Parms), Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMenuLobby_OnCreateSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuLobby_OnCreateSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics
	{
		struct MenuLobby_eventOnDestroySession_Parms
		{
			bool bWasSuccessful;
		};
		static void NewProp_bWasSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
	{
		((MenuLobby_eventOnDestroySession_Parms*)Obj)->bWasSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MenuLobby_eventOnDestroySession_Parms), &Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::NewProp_bWasSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MenuLobby.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuLobby, nullptr, "OnDestroySession", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::MenuLobby_eventOnDestroySession_Parms), Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMenuLobby_OnDestroySession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuLobby_OnDestroySession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics
	{
		struct MenuLobby_eventOnStartSession_Parms
		{
			bool bWasSuccessful;
		};
		static void NewProp_bWasSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWasSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::NewProp_bWasSuccessful_SetBit(void* Obj)
	{
		((MenuLobby_eventOnStartSession_Parms*)Obj)->bWasSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::NewProp_bWasSuccessful = { "bWasSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MenuLobby_eventOnStartSession_Parms), &Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::NewProp_bWasSuccessful_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::NewProp_bWasSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MenuLobby.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMenuLobby, nullptr, "OnStartSession", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::MenuLobby_eventOnStartSession_Parms), Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMenuLobby_OnStartSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMenuLobby_OnStartSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMenuLobby);
	UClass* Z_Construct_UClass_UMenuLobby_NoRegister()
	{
		return UMenuLobby::StaticClass();
	}
	struct Z_Construct_UClass_UMenuLobby_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HostBtn_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HostBtn;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JoinBtn_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JoinBtn;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMenuLobby_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_MultiplayerSession,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMenuLobby_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMenuLobby_HostBtnClick, "HostBtnClick" }, // 1019943027
		{ &Z_Construct_UFunction_UMenuLobby_JoinBtnClick, "JoinBtnClick" }, // 1801923603
		{ &Z_Construct_UFunction_UMenuLobby_MenuSetup, "MenuSetup" }, // 362368422
		{ &Z_Construct_UFunction_UMenuLobby_OnCreateSession, "OnCreateSession" }, // 3075021885
		{ &Z_Construct_UFunction_UMenuLobby_OnDestroySession, "OnDestroySession" }, // 1584669482
		{ &Z_Construct_UFunction_UMenuLobby_OnStartSession, "OnStartSession" }, // 1550822162
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMenuLobby_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MenuLobby.h" },
		{ "ModuleRelativePath", "Public/MenuLobby.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMenuLobby_Statics::NewProp_HostBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "Comment", "// NOTE: variable name must be the same between C++ and Blueprint\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MenuLobby.h" },
		{ "ToolTip", "NOTE: variable name must be the same between C++ and Blueprint" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMenuLobby_Statics::NewProp_HostBtn = { "HostBtn", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMenuLobby, HostBtn), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMenuLobby_Statics::NewProp_HostBtn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMenuLobby_Statics::NewProp_HostBtn_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMenuLobby_Statics::NewProp_JoinBtn_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MenuLobby.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMenuLobby_Statics::NewProp_JoinBtn = { "JoinBtn", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMenuLobby, JoinBtn), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UMenuLobby_Statics::NewProp_JoinBtn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMenuLobby_Statics::NewProp_JoinBtn_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMenuLobby_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMenuLobby_Statics::NewProp_HostBtn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMenuLobby_Statics::NewProp_JoinBtn,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMenuLobby_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMenuLobby>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMenuLobby_Statics::ClassParams = {
		&UMenuLobby::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMenuLobby_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMenuLobby_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMenuLobby_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMenuLobby_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMenuLobby()
	{
		if (!Z_Registration_Info_UClass_UMenuLobby.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMenuLobby.OuterSingleton, Z_Construct_UClass_UMenuLobby_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMenuLobby.OuterSingleton;
	}
	template<> MULTIPLAYERSESSION_API UClass* StaticClass<UMenuLobby>()
	{
		return UMenuLobby::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMenuLobby);
	struct Z_CompiledInDeferFile_FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MenuLobby_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MenuLobby_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMenuLobby, UMenuLobby::StaticClass, TEXT("UMenuLobby"), &Z_Registration_Info_UClass_UMenuLobby, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMenuLobby), 2811433723U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MenuLobby_h_1246089396(TEXT("/Script/MultiplayerSession"),
		Z_CompiledInDeferFile_FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MenuLobby_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PetWar_Plugins_MultiplayerSession_Source_MultiplayerSession_Public_MenuLobby_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
