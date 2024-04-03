// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB01/EnemyShipKamikaze.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyShipKamikaze() {}
// Cross Module References
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipKamikaze_NoRegister();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipKamikaze();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipHunter();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB01();
// End Cross Module References
	void AEnemyShipKamikaze::StaticRegisterNativesAEnemyShipKamikaze()
	{
	}
	UClass* Z_Construct_UClass_AEnemyShipKamikaze_NoRegister()
	{
		return AEnemyShipKamikaze::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyShipKamikaze_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyShipKamikaze_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemyShipHunter,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyShipKamikaze_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "EnemyShipKamikaze.h" },
		{ "ModuleRelativePath", "EnemyShipKamikaze.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyShipKamikaze_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyShipKamikaze>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyShipKamikaze_Statics::ClassParams = {
		&AEnemyShipKamikaze::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEnemyShipKamikaze_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyShipKamikaze_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyShipKamikaze()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyShipKamikaze_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyShipKamikaze, 3396214005);
	template<> GALAGA_USFX_LAB01_API UClass* StaticClass<AEnemyShipKamikaze>()
	{
		return AEnemyShipKamikaze::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyShipKamikaze(Z_Construct_UClass_AEnemyShipKamikaze, &AEnemyShipKamikaze::StaticClass, TEXT("/Script/Galaga_USFX_LAB01"), TEXT("AEnemyShipKamikaze"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyShipKamikaze);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
