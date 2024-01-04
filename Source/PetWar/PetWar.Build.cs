// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PetWar : ModuleRules
{
	public PetWar(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnforceIWYU = true;
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "Slate", "SlateCore", "OnlineSubsystemSteam", "OnlineSubsystem" });

        PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
        /*
        if (Target.bBuildEditor)
        {
            PublicDependencyModuleNames.AddRange(new string[]
                    {
                "SteamShared",
                    });
        }
        */
    }
}
