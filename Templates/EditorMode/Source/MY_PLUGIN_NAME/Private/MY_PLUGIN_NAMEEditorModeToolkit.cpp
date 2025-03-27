// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_PLUGIN_NAMEEditorModeToolkit.h"
#include "MY_PLUGIN_NAMEEditorMode.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "MY_PLUGIN_NAMEEditorModeToolkit"

FMY_PLUGIN_NAMEEditorModeToolkit::FMY_PLUGIN_NAMEEditorModeToolkit()
{
}

void FMY_PLUGIN_NAMEEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);
}

void FMY_PLUGIN_NAMEEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}


FName FMY_PLUGIN_NAMEEditorModeToolkit::GetToolkitFName() const
{
	return FName("MY_PLUGIN_NAMEEditorMode");
}

FText FMY_PLUGIN_NAMEEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "MY_PLUGIN_NAMEEditorMode Toolkit");
}

#undef LOCTEXT_NAMESPACE
