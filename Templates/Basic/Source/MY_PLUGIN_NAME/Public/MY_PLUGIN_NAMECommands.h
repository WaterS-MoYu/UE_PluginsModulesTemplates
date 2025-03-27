// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MY_PLUGIN_NAMEStyle.h"

class FMY_PLUGIN_NAMECommands : public TCommands<FMY_PLUGIN_NAMECommands>
{
public:

	FMY_PLUGIN_NAMECommands()
		: TCommands<FMY_PLUGIN_NAMECommands>(TEXT("MY_PLUGIN_NAME"), NSLOCTEXT("Contexts", "MY_PLUGIN_NAME", "MY_PLUGIN_NAME Plugin"), NAME_None, FMY_PLUGIN_NAMEStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
