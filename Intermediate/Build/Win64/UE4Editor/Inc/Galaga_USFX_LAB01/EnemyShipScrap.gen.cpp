// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB01/EnemyShipScrap.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyShipScrap() {}
// Cross Module References
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipScrap_NoRegister();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipScrap();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipTransport();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB01();
// End Cross Module References
	void AEnemyShipScrap::StaticRegisterNativesAEnemyShipScrap()
	{
	}
	UClass* Z_Construct_UClass_AEnemyShipScrap_NoRegister()
	{
		return AEnemyShipScrap::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyShipScrap_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyShipScrap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemyShipTransport,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyShipScrap_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "EnemyShipScrap.h" },
		{ "ModuleRelativePath", "EnemyShipScrap.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyShipScrap_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyShipScrap>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyShipScrap_Statics::ClassParams = {
		&AEnemyShipScrap::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEnemyShipScrap_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyShipScrap_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyShipScrap()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyShipScrap_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyShipScrap, 2025251428);
	template<> GALAGA_USFX_LAB01_API UClass* StaticClass<AEnemyShipScrap>()
	{
		return AEnemyShipScrap::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyShipScrap(Z_Construct_UClass_AEnemyShipScrap, &AEnemyShipScrap::StaticClass, TEXT("/Script/Galaga_USFX_LAB01"), TEXT("AEnemyShipScrap"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyShipScrap);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
