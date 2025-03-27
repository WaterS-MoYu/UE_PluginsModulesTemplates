// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_CLASS.h"
#include "MY_MODULE_NAMEStyle.h"
#include "MY_MODULE_NAMECommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName MY_MODULE_NAMETabName("MY_MODULE_NAME");

#define LOCTEXT_NAMESPACE "FMY_MODULE_CLASS"

void FMY_MODULE_CLASS::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FMY_MODULE_NAMEStyle::Initialize();
	FMY_MODULE_NAMEStyle::ReloadTextures();

	FMY_MODULE_NAMECommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FMY_MODULE_NAMECommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FMY_MODULE_CLASS::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMY_MODULE_CLASS::RegisterMenus));
}

void FMY_MODULE_CLASS::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMY_MODULE_NAMEStyle::Shutdown();

	FMY_MODULE_NAMECommands::Unregister();
}

void FMY_MODULE_CLASS::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FMY_MODULE_CLASS::PluginButtonClicked()")),
							FText::FromString(TEXT("MY_MODULE_NAME.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FMY_MODULE_CLASS::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FMY_MODULE_NAMECommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMY_MODULE_NAMECommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMY_MODULE_CLASS, MY_MODULE_NAME)