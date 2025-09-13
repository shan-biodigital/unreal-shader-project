// Copyright Epic Games, Inc. All Rights Reserved.

#include "My2ndShaderPluginV1.h"
#include "Interfaces/IPluginManager.h"
#include "ShaderCore.h"

#define LOCTEXT_NAMESPACE "FMy2ndShaderPluginV1Module"

void FMy2ndShaderPluginV1Module::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("halo 4!!!")));

	// This is the key step to tell the engine where to find your shaders.
	// It maps the virtual shader path "/Plugin/My2ndShaderPluginV1" to your plugin's
	// physical Shaders directory.

	// do we need this?
	// seems like we do need it!
	// also we need to update .uplugin file to add "ShaderDirectory": "Shaders"
	// and also ensure that the plugin loading phase is set to "PostConfigInit"
	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("My2ndShaderPluginV1"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/My2ndShaderPluginV1"), PluginShaderDir);
}

void FMy2ndShaderPluginV1Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// This removes the shader mapping when the module is unloaded.
	// ResetAllShaderSourceDirectoryMappings();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMy2ndShaderPluginV1Module, My2ndShaderPluginV1)
