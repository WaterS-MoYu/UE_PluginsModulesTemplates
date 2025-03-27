// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_PLUGIN_NAME.h"
#include "MY_PLUGIN_NAMEStyle.h"
#include "MY_PLUGIN_NAMECommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
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
		FMY_PLUGIN_NAMECommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FMY_PLUGIN_NAMEModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMY_PLUGIN_NAMEModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(MY_PLUGIN_NAMETabName, FOnSpawnTab::CreateRaw(this, &FMY_PLUGIN_NAMEModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FMY_PLUGIN_NAMETabTitle", "MY_PLUGIN_NAME"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FMY_PLUGIN_NAMEModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMY_PLUGIN_NAMEStyle::Shutdown();

	FMY_PLUGIN_NAMECommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(MY_PLUGIN_NAMETabName);
}

TSharedRef<SDockTab> FMY_PLUGIN_NAMEModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FMY_PLUGIN_NAMEModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("MY_PLUGIN_NAME.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FMY_PLUGIN_NAMEModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(MY_PLUGIN_NAMETabName);
}

void FMY_PLUGIN_NAMEModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FMY_PLUGIN_NAMECommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMY_PLUGIN_NAMECommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMY_PLUGIN_NAMEModule, MY_PLUGIN_NAME)