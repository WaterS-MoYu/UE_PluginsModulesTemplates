// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_NAMEEditorModeCommands.h"
#include "MY_MODULE_NAMEEditorMode.h"
#include "EditorStyleSet.h"

#define LOCTEXT_NAMESPACE "MY_MODULE_NAMEEditorModeCommands"

FMY_MODULE_NAMEEditorModeCommands::FMY_MODULE_NAMEEditorModeCommands()
	: TCommands<FMY_MODULE_NAMEEditorModeCommands>("MY_MODULE_NAMEEditorMode",
		NSLOCTEXT("MY_MODULE_NAMEEditorMode", "MY_MODULE_NAMEEditorModeCommands", "MY_MODULE_NAME Editor Mode"),
		NAME_None,
		FEditorStyle::GetStyleSetName())
{
}

void FMY_MODULE_NAMEEditorModeCommands::RegisterCommands()
{
	TArray <TSharedPtr<FUICommandInfo>>& ToolCommands = Commands.FindOrAdd(NAME_Default);

	UI_COMMAND(SimpleTool, "Show Actor Info", "Opens message box with info about a clicked actor", EUserInterfaceActionType::Button, FInputChord());
	ToolCommands.Add(SimpleTool);

	UI_COMMAND(InteractiveTool, "Measure Distance", "Measures distance between 2 points (click to set origin, shift-click to set end point)", EUserInterfaceActionType::ToggleButton, FInputChord());
	ToolCommands.Add(InteractiveTool);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> FMY_MODULE_NAMEEditorModeCommands::GetCommands()
{
	return FMY_MODULE_NAMEEditorModeCommands::Get().Commands;
}

#undef LOCTEXT_NAMESPACE
