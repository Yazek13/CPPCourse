// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CPPCourse/CPPCourseGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPPCourseGameMode() {}
// Cross Module References
	CPPCOURSE_API UClass* Z_Construct_UClass_ACPPCourseGameMode_NoRegister();
	CPPCOURSE_API UClass* Z_Construct_UClass_ACPPCourseGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_CPPCourse();
// End Cross Module References
	void ACPPCourseGameMode::StaticRegisterNativesACPPCourseGameMode()
	{
	}
	UClass* Z_Construct_UClass_ACPPCourseGameMode_NoRegister()
	{
		return ACPPCourseGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACPPCourseGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPPCourseGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_CPPCourse,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPPCourseGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "CPPCourseGameMode.h" },
		{ "ModuleRelativePath", "CPPCourseGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPPCourseGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPPCourseGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACPPCourseGameMode_Statics::ClassParams = {
		&ACPPCourseGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_ACPPCourseGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACPPCourseGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACPPCourseGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACPPCourseGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACPPCourseGameMode, 201894089);
	template<> CPPCOURSE_API UClass* StaticClass<ACPPCourseGameMode>()
	{
		return ACPPCourseGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACPPCourseGameMode(Z_Construct_UClass_ACPPCourseGameMode, &ACPPCourseGameMode::StaticClass, TEXT("/Script/CPPCourse"), TEXT("ACPPCourseGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPPCourseGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
