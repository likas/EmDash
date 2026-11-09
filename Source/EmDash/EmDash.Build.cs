// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EmDash : ModuleRules
{
	public EmDash(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"EmDash",
			"EmDash/Variant_Platforming",
			"EmDash/Variant_Platforming/Animation",
			"EmDash/Variant_Combat",
			"EmDash/Variant_Combat/AI",
			"EmDash/Variant_Combat/Animation",
			"EmDash/Variant_Combat/Gameplay",
			"EmDash/Variant_Combat/Interfaces",
			"EmDash/Variant_Combat/UI",
			"EmDash/Variant_SideScrolling",
			"EmDash/Variant_SideScrolling/AI",
			"EmDash/Variant_SideScrolling/Gameplay",
			"EmDash/Variant_SideScrolling/Interfaces",
			"EmDash/Variant_SideScrolling/UI",
			"EmDash/AbilitySystem",
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
