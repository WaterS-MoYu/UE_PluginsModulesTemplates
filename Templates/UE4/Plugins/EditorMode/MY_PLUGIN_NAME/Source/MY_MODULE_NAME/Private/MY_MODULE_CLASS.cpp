// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_CLASS.h"
#include "MY_MODULE_NAMEEdMode.h"

#define LOCTEXT_NAMESPACE "FMY_MODULE_CLASS"

void FMY_MODULE_CLASS::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FMY_MODULE_NAMEEdMode>(FMY_MODULE_NAMEEdMode::EM_MY_MODULE_NAMEEdModeId, LOCTEXT("MY_MODULE_NAMEEdModeName", "MY_MODULE_NAMEEdMode"), FSlateIcon(), true);
}

void FMY_MODULE_CLASS::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FMY_MODULE_NAMEEdMode::EM_MY_MODULE_NAMEEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMY_MODULE_CLASS, MY_MODULE_NAME)