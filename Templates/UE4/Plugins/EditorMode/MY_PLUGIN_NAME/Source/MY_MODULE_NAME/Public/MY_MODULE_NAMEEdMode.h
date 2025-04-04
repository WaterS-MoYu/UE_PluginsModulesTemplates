// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EdMode.h"

class FMY_MODULE_NAMEEdMode : public FEdMode
{
public:
	const static FEditorModeID EM_MY_MODULE_NAMEEdModeId;
public:
	FMY_MODULE_NAMEEdMode();
	virtual ~FMY_MODULE_NAMEEdMode();

	// FEdMode interface
	virtual void Enter() override;
	virtual void Exit() override;
	//virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;
	//virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI) override;
	//virtual void ActorSelectionChangeNotify() override;
	bool UsesToolkits() const override;
	// End of FEdMode interface
};
