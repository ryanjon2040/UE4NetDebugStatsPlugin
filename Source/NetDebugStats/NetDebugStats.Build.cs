// Created by Satheesh (ryanjon2040). Copyright - 2021. Twitter: @ryanjon2040 - Discord: ryanjon2040#5319

using UnrealBuildTool;

public class NetDebugStats : ModuleRules
{
	public NetDebugStats(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core" });
		PrivateDependencyModuleNames.AddRange( new string[] { "CoreUObject", "Engine" });
	}
}
