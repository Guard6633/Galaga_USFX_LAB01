// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB01/EnemyShipInvicible.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyShipInvicible() {}
// Cross Module References
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipInvicible_NoRegister();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipInvicible();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipSpy();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB01();
// End Cross Module References
	void AEnemyShipInvicible::StaticRegisterNativesAEnemyShipInvicible()
	{
	}
	UClass* Z_Construct_UClass_AEnemyShipInvicible_NoRegister()
	{
		return AEnemyShipInvicible::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyShipInvicible_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyShipInvicible_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemyShipSpy,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyShipInvicible_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "EnemyShipInvicible.h" },
		{ "ModuleRelativePath", "EnemyShipInvicible.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyShipInvicible_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyShipInvicible>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyShipInvicible_Statics::ClassParams = {
		&AEnemyShipInvicible::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AEnemyShipInvicible_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyShipInvicible_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyShipInvicible()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyShipInvicible_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyShipInvicible, 825571473);
	template<> GALAGA_USFX_LAB01_API UClass* StaticClass<AEnemyShipInvicible>()
	{
		return AEnemyShipInvicible::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyShipInvicible(Z_Construct_UClass_AEnemyShipInvicible, &AEnemyShipInvicible::StaticClass, TEXT("/Script/Galaga_USFX_LAB01"), TEXT("AEnemyShipInvicible"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyShipInvicible);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
