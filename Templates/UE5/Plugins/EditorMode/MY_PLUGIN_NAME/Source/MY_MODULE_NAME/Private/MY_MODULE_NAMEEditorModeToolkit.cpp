// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_NAMEEditorModeToolkit.h"
#include "MY_MODULE_NAMEEditorMode.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "MY_MODULE_NAMEEditorModeToolkit"

FMY_MODULE_NAMEEditorModeToolkit::FMY_MODULE_NAMEEditorModeToolkit()
{
}

void FMY_MODULE_NAMEEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);
}

void FMY_MODULE_NAMEEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}


FName FMY_MODULE_NAMEEditorModeToolkit::GetToolkitFName() const
{
	return FName("MY_MODULE_NAMEEditorMode");
}

FText FMY_MODULE_NAMEEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "MY_MODULE_NAMEEditorMode Toolkit");
}

#undef LOCTEXT_NAMESPACE
