// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB01/EnemyShipShooter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyShipShooter() {}
// Cross Module References
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipShooter_NoRegister();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipShooter();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipHunter();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB01();
// End Cross Module References
	void AEnemyShipShooter::StaticRegisterNativesAEnemyShipShooter()
	{
	}
	UClass* Z_Construct_UClass_AEnemyShipShooter_NoRegister()
	{
		return AEnemyShipShooter::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyShipShooter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyShipShooter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemyShipHunter,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyShipShooter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "EnemyShipShooter.h" },
		{ "ModuleRelativePath", "EnemyShipShooter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyShipShooter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyShipShooter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyShipShooter_Statics::ClassParams = {
		&AEnemyShipShooter::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEnemyShipShooter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyShipShooter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyShipShooter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyShipShooter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyShipShooter, 737142918);
	template<> GALAGA_USFX_LAB01_API UClass* StaticClass<AEnemyShipShooter>()
	{
		return AEnemyShipShooter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyShipShooter(Z_Construct_UClass_AEnemyShipShooter, &AEnemyShipShooter::StaticClass, TEXT("/Script/Galaga_USFX_LAB01"), TEXT("AEnemyShipShooter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyShipShooter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
