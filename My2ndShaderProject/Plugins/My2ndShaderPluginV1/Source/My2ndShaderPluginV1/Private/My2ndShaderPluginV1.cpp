// Copyright Epic Games, Inc. All Rights Reserved.

#include "My2ndShaderPluginV1.h"

#define LOCTEXT_NAMESPACE "FMy2ndShaderPluginV1Module"

void FMy2ndShaderPluginV1Module::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(TEXT("halo 4!!!")));
}

void FMy2ndShaderPluginV1Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMy2ndShaderPluginV1Module, My2ndShaderPluginV1)
