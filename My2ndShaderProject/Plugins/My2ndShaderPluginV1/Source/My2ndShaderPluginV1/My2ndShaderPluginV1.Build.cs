// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class My2ndShaderPluginV1 : ModuleRules
{
	public My2ndShaderPluginV1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				// "Core",
				// // ... add other public dependencies that you statically link with here ...
				// "Projects",   // Added to resolve IPluginManager::Get() linker error
				// // "ShaderCore"  // Added to resolve shader directory mapping linker errors

				"Core",
				"CoreUObject",
				"Engine",
				"RenderCore",
				"RHI",
				// "ShaderCore", // Needed to use usf files, jk, deprecated in unreal 5
				"Projects",  // Added to resolve IPluginManager::Get() linker error
				"UnrealEd",        // Editor-only module
				"MaterialEditor"   // For material editor integration
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"RenderCore",
				"RHI",

				// "Slate",
				// "SlateCore",
				// // ... add private dependencies that you statically link with here ...	
				// // "ShaderCore"  // Added to resolve shader directory mapping linker errors
				// "Projects",
				// "RenderCore",
				// "RHI"
				// // "ShaderCore", // Needed to use usf files, jk, deprecated in unreal 5
				// "UnrealEd",        // Editor-only module
				// "MaterialEditor"   // For material editor integration

				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
				"UnrealEd",        // Editor-only module
				// "MaterialShader",    // <-- Add this, jk, doesn't exist
				// "ShaderGraph", // ← required for UMaterialExpressionCustom
				"MaterialEditor"   // For material editor integration
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
