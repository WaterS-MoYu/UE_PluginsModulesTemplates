// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_NAMEEdMode.h"
#include "MY_MODULE_NAMEEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"

const FEditorModeID FMY_MODULE_NAMEEdMode::EM_MY_MODULE_NAMEEdModeId = TEXT("EM_MY_MODULE_NAMEEdMode");

FMY_MODULE_NAMEEdMode::FMY_MODULE_NAMEEdMode()
{

}

FMY_MODULE_NAMEEdMode::~FMY_MODULE_NAMEEdMode()
{

}

void FMY_MODULE_NAMEEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FMY_MODULE_NAMEEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FMY_MODULE_NAMEEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FMY_MODULE_NAMEEdMode::UsesToolkits() const
{
	return true;
}




