// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Naves_USFX012026 : ModuleRules
{
	public Naves_USFX012026(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
