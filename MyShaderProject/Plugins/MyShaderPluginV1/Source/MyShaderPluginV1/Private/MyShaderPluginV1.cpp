// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyShaderPluginV1.h"
#include "Modules/ModuleManager.h"
#include "Misc/MessageDialog.h"
#include "Logging/LogMacros.h"

#define LOCTEXT_NAMESPACE "FMyShaderPluginV1Module"

DEFINE_LOG_CATEGORY_STATIC(LogMyPlugin, Log, All);

void FMyShaderPluginV1Module::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("yo!!!")));

	UE_LOG(LogTemp, Warning, TEXT("yo!!!"));
}

void FMyShaderPluginV1Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMyShaderPluginV1Module, MyShaderPluginV1)
