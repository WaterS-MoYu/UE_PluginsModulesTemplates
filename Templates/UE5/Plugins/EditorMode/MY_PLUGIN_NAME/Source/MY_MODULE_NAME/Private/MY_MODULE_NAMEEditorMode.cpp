// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_NAMEEditorMode.h"
#include "MY_MODULE_NAMEEditorModeToolkit.h"
#include "EdModeInteractiveToolsContext.h"
#include "InteractiveToolManager.h"
#include "MY_MODULE_NAMEEditorModeCommands.h"


//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
// AddYourTool Step 1 - include the header file for your Tools here
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include "Tools/MY_MODULE_NAMESimpleTool.h"
#include "Tools/MY_MODULE_NAMEInteractiveTool.h"

// step 2: register a ToolBuilder in FMY_MODULE_NAMEEditorMode::Enter() below


#define LOCTEXT_NAMESPACE "MY_MODULE_NAMEEditorMode"

const FEditorModeID UMY_MODULE_NAMEEditorMode::EM_MY_MODULE_NAMEEditorModeId = TEXT("EM_MY_MODULE_NAMEEditorMode");

FString UMY_MODULE_NAMEEditorMode::SimpleToolName = TEXT("MY_MODULE_NAME_ActorInfoTool");
FString UMY_MODULE_NAMEEditorMode::InteractiveToolName = TEXT("MY_MODULE_NAME_MeasureDistanceTool");


UMY_MODULE_NAMEEditorMode::UMY_MODULE_NAMEEditorMode()
{
	FModuleManager::Get().LoadModule("EditorStyle");

	// appearance and icon in the editing mode ribbon can be customized here
	Info = FEditorModeInfo(UMY_MODULE_NAMEEditorMode::EM_MY_MODULE_NAMEEditorModeId,
		LOCTEXT("ModeName", "MY_MODULE_NAME"),
		FSlateIcon(),
		true);
}


UMY_MODULE_NAMEEditorMode::~UMY_MODULE_NAMEEditorMode()
{
}


void UMY_MODULE_NAMEEditorMode::ActorSelectionChangeNotify()
{
}

void UMY_MODULE_NAMEEditorMode::Enter()
{
	UEdMode::Enter();

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// AddYourTool Step 2 - register the ToolBuilders for your Tools here.
	// The string name you pass to the ToolManager is used to select/activate your ToolBuilder later.
	//////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////// 
	const FMY_MODULE_NAMEEditorModeCommands& SampleToolCommands = FMY_MODULE_NAMEEditorModeCommands::Get();

	RegisterTool(SampleToolCommands.SimpleTool, SimpleToolName, NewObject<UMY_MODULE_NAMESimpleToolBuilder>(this));
	RegisterTool(SampleToolCommands.InteractiveTool, InteractiveToolName, NewObject<UMY_MODULE_NAMEInteractiveToolBuilder>(this));

	// active tool type is not relevant here, we just set to default
	GetToolManager()->SelectActiveToolType(EToolSide::Left, SimpleToolName);
}

void UMY_MODULE_NAMEEditorMode::CreateToolkit()
{
	Toolkit = MakeShareable(new FMY_MODULE_NAMEEditorModeToolkit);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> UMY_MODULE_NAMEEditorMode::GetModeCommands() const
{
	return FMY_MODULE_NAMEEditorModeCommands::Get().GetCommands();
}

#undef LOCTEXT_NAMESPACE
