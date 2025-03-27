// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "MY_MODULE_NAMEStyle.h"

class FMY_MODULE_NAMECommands : public TCommands<FMY_MODULE_NAMECommands>
{
public:

	FMY_MODULE_NAMECommands()
		: TCommands<FMY_MODULE_NAMECommands>(TEXT("MY_MODULE_NAME"), NSLOCTEXT("Contexts", "MY_MODULE_NAME", "MY_MODULE_NAME Module"), NAME_None, FMY_MODULE_NAMEStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
