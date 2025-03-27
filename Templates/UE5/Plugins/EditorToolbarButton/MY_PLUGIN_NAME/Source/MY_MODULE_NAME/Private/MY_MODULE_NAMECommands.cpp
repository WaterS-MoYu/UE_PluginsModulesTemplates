// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_NAMECommands.h"

#define LOCTEXT_NAMESPACE "FMY_MODULE_CLASS"

void FMY_MODULE_NAMECommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "MY_MODULE_NAME", "Execute MY_MODULE_NAME action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
