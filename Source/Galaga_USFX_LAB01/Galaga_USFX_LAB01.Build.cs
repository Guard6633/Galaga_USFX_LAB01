// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Galaga_USFX_LAB01 : ModuleRules
{
	public Galaga_USFX_LAB01(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
