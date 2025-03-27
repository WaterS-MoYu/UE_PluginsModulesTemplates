// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_PLUGIN_NAMEEditorMode.h"
#include "MY_PLUGIN_NAMEEditorModeToolkit.h"
#include "EdModeInteractiveToolsContext.h"
#include "InteractiveToolManager.h"
#include "MY_PLUGIN_NAMEEditorModeCommands.h"


//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
// AddYourTool Step 1 - include the header file for your Tools here
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include "Tools/MY_PLUGIN_NAMESimpleTool.h"
#include "Tools/MY_PLUGIN_NAMEInteractiveTool.h"

// step 2: register a ToolBuilder in FMY_PLUGIN_NAMEEditorMode::Enter() below


#define LOCTEXT_NAMESPACE "MY_PLUGIN_NAMEEditorMode"

const FEditorModeID UMY_PLUGIN_NAMEEditorMode::EM_MY_PLUGIN_NAMEEditorModeId = TEXT("EM_MY_PLUGIN_NAMEEditorMode");

FString UMY_PLUGIN_NAMEEditorMode::SimpleToolName = TEXT("MY_PLUGIN_NAME_ActorInfoTool");
FString UMY_PLUGIN_NAMEEditorMode::InteractiveToolName = TEXT("MY_PLUGIN_NAME_MeasureDistanceTool");


UMY_PLUGIN_NAMEEditorMode::UMY_PLUGIN_NAMEEditorMode()
{
	FModuleManager::Get().LoadModule("EditorStyle");

	// appearance and icon in the editing mode ribbon can be customized here
	Info = FEditorModeInfo(UMY_PLUGIN_NAMEEditorMode::EM_MY_PLUGIN_NAMEEditorModeId,
		LOCTEXT("ModeName", "MY_PLUGIN_NAME"),
		FSlateIcon(),
		true);
}


UMY_PLUGIN_NAMEEditorMode::~UMY_PLUGIN_NAMEEditorMode()
{
}


void UMY_PLUGIN_NAMEEditorMode::ActorSelectionChangeNotify()
{
}

void UMY_PLUGIN_NAMEEditorMode::Enter()
{
	UEdMode::Enter();

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// AddYourTool Step 2 - register the ToolBuilders for your Tools here.
	// The string name you pass to the ToolManager is used to select/activate your ToolBuilder later.
	//////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////// 
	const FMY_PLUGIN_NAMEEditorModeCommands& SampleToolCommands = FMY_PLUGIN_NAMEEditorModeCommands::Get();

	RegisterTool(SampleToolCommands.SimpleTool, SimpleToolName, NewObject<UMY_PLUGIN_NAMESimpleToolBuilder>(this));
	RegisterTool(SampleToolCommands.InteractiveTool, InteractiveToolName, NewObject<UMY_PLUGIN_NAMEInteractiveToolBuilder>(this));

	// active tool type is not relevant here, we just set to default
	GetToolManager()->SelectActiveToolType(EToolSide::Left, SimpleToolName);
}

void UMY_PLUGIN_NAMEEditorMode::CreateToolkit()
{
	Toolkit = MakeShareable(new FMY_PLUGIN_NAMEEditorModeToolkit);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> UMY_PLUGIN_NAMEEditorMode::GetModeCommands() const
{
	return FMY_PLUGIN_NAMEEditorModeCommands::Get().GetCommands();
}

#undef LOCTEXT_NAMESPACE
