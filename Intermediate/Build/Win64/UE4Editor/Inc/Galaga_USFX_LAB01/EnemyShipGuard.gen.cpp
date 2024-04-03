// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB01/EnemyShipGuard.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyShipGuard() {}
// Cross Module References
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipGuard_NoRegister();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipGuard();
	GALAGA_USFX_LAB01_API UClass* Z_Construct_UClass_AEnemyShipMother();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB01();
// End Cross Module References
	void AEnemyShipGuard::StaticRegisterNativesAEnemyShipGuard()
	{
	}
	UClass* Z_Construct_UClass_AEnemyShipGuard_NoRegister()
	{
		return AEnemyShipGuard::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyShipGuard_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyShipGuard_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AEnemyShipMother,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB01,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyShipGuard_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "EnemyShipGuard.h" },
		{ "ModuleRelativePath", "EnemyShipGuard.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyShipGuard_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyShipGuard>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEnemyShipGuard_Statics::ClassParams = {
		&AEnemyShipGuard::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEnemyShipGuard_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyShipGuard_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEnemyShipGuard()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEnemyShipGuard_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEnemyShipGuard, 1915438241);
	template<> GALAGA_USFX_LAB01_API UClass* StaticClass<AEnemyShipGuard>()
	{
		return AEnemyShipGuard::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEnemyShipGuard(Z_Construct_UClass_AEnemyShipGuard, &AEnemyShipGuard::StaticClass, TEXT("/Script/Galaga_USFX_LAB01"), TEXT("AEnemyShipGuard"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyShipGuard);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
