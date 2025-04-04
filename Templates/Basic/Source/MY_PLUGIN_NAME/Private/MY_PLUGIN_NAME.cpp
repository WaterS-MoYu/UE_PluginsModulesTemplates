// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_PLUGIN_NAME.h"
#include "MY_PLUGIN_NAMEStyle.h"
#include "MY_PLUGIN_NAMECommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName MY_PLUGIN_NAMETabName("MY_PLUGIN_NAME");

#define LOCTEXT_NAMESPACE "FMY_PLUGIN_NAMEModule"

void FMY_PLUGIN_NAMEModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FMY_PLUGIN_NAMEStyle::Initialize();
	FMY_PLUGIN_NAMEStyle::ReloadTextures();

	FMY_PLUGIN_NAMECommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FMY_PLUGIN_NAMECommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FMY_PLUGIN_NAMEModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMY_PLUGIN_NAMEModule::RegisterMenus));
}

void FMY_PLUGIN_NAMEModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMY_PLUGIN_NAMEStyle::Shutdown();

	FMY_PLUGIN_NAMECommands::Unregister();
}

void FMY_PLUGIN_NAMEModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FMY_PLUGIN_NAMEModule::PluginButtonClicked()")),
							FText::FromString(TEXT("MY_PLUGIN_NAME.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FMY_PLUGIN_NAMEModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FMY_PLUGIN_NAMECommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMY_PLUGIN_NAMECommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMY_PLUGIN_NAMEModule, MY_PLUGIN_NAME)