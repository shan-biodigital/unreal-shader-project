// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyShaderPluginV1 : ModuleRules
{
	public MyShaderPluginV1(ReadOnlyTargetRules Target) : base(Target)
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
				// old
				// "Core",
				// ... add other public dependencies that you statically link with here ...

				// // new
				"Core",
				"CoreUObject",
				"Engine",
				"RenderCore",
				"RHI",
				// "ShaderCore", // Needed to use usf files, jk, deprecated in unreal 5
				"UnrealEd",        // Editor-only module
				"MaterialEditor"   // For material editor integration
			}
			);

		// PrivateIncludePaths.Add("MyShaderPluginV1/Shaders/Private");
		// PrivateIncludePaths.AddRange(
		// 		new string[] {
		// 				"MyShaderPluginV1/Shaders/Private"
		// 		}
		// );

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
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
