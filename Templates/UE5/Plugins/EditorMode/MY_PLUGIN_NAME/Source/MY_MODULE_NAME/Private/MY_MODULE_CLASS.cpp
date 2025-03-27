// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_CLASS.h"
#include "MY_MODULE_NAMEEditorModeCommands.h"

#define LOCTEXT_NAMESPACE "MY_MODULE_CLASS"

void FMY_MODULE_CLASS::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FMY_MODULE_NAMEEditorModeCommands::Register();
}

void FMY_MODULE_CLASS::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FMY_MODULE_NAMEEditorModeCommands::Unregister();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMY_MODULE_CLASS, MY_MODULE_NAME)  //MY_MODULE_NAMEEditorMode