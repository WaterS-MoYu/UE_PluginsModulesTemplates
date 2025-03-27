// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_CLASS.h"
#include "MY_MODULE_NAMEStyle.h"
#include "MY_MODULE_NAMECommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
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
		FMY_MODULE_NAMECommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FMY_MODULE_CLASS::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FMY_MODULE_CLASS::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(MY_MODULE_NAMETabName, FOnSpawnTab::CreateRaw(this, &FMY_MODULE_CLASS::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FMY_MODULE_NAMETabTitle", "MY_MODULE_NAME"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FMY_MODULE_CLASS::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FMY_MODULE_NAMEStyle::Shutdown();

	FMY_MODULE_NAMECommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(MY_MODULE_NAMETabName);
}

TSharedRef<SDockTab> FMY_MODULE_CLASS::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FMY_MODULE_CLASS::OnSpawnPluginTab")),
		FText::FromString(TEXT("MY_MODULE_NAME.cpp"))
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

void FMY_MODULE_CLASS::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(MY_MODULE_NAMETabName);
}

void FMY_MODULE_CLASS::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FMY_MODULE_NAMECommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FMY_MODULE_NAMECommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMY_MODULE_CLASS, MY_MODULE_NAME)