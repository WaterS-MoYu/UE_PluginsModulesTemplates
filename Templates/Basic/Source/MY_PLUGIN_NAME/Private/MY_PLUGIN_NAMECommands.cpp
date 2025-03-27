// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_PLUGIN_NAMECommands.h"

#define LOCTEXT_NAMESPACE "FMY_PLUGIN_NAMEModule"

void FMY_PLUGIN_NAMECommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "MY_PLUGIN_NAME", "Execute MY_PLUGIN_NAME action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
