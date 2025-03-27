// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_PLUGIN_NAMEModule.h"
#include "MY_PLUGIN_NAMEEditorModeCommands.h"

#define LOCTEXT_NAMESPACE "MY_PLUGIN_NAMEModule"

void FMY_PLUGIN_NAMEModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FMY_PLUGIN_NAMEEditorModeCommands::Register();
}

void FMY_PLUGIN_NAMEModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FMY_PLUGIN_NAMEEditorModeCommands::Unregister();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMY_PLUGIN_NAMEModule, MY_PLUGIN_NAMEEditorMode)