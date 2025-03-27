// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_NAMECommands.h"

#define LOCTEXT_NAMESPACE "FMY_MODULE_CLASS"

void FMY_MODULE_NAMECommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "MY_MODULE_NAME", "Bring up MY_MODULE_NAME window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
