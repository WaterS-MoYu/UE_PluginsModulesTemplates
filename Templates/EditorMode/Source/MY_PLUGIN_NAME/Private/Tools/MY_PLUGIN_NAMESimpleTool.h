// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InteractiveToolBuilder.h"
#include "BaseTools/SingleClickTool.h"
#include "MY_PLUGIN_NAMESimpleTool.generated.h"

/**
 * Builder for UMY_PLUGIN_NAMESimpleTool
 */
UCLASS()
class MY_PLUGIN_NAME_API UMY_PLUGIN_NAMESimpleToolBuilder : public UInteractiveToolBuilder
{
	GENERATED_BODY()

public:
	virtual bool CanBuildTool(const FToolBuilderState& SceneState) const override { return true; }
	virtual UInteractiveTool* BuildTool(const FToolBuilderState& SceneState) const override;
};



/**
 * Settings UObject for UMY_PLUGIN_NAMESimpleTool. This UClass inherits from UInteractiveToolPropertySet,
 * which provides an OnModified delegate that the Tool will listen to for changes in property values.
 */
UCLASS(Transient)
class MY_PLUGIN_NAME_API UMY_PLUGIN_NAMESimpleToolProperties : public UInteractiveToolPropertySet
{
	GENERATED_BODY()
public:
	UMY_PLUGIN_NAMESimpleToolProperties();

	/** If enabled, dialog should display extended information about the actor clicked on. Otherwise, only basic info will be shown. */
	UPROPERTY(EditAnywhere, Category = Options, meta = (DisplayName = "Show Extended Info"))
	bool ShowExtendedInfo;
};




/**
 * UMY_PLUGIN_NAMESimpleTool is an example Tool that opens a message box displaying info about an actor that the user
 * clicks left mouse button. All the action is in the ::OnClicked handler.
 */
UCLASS()
class MY_PLUGIN_NAME_API UMY_PLUGIN_NAMESimpleTool : public USingleClickTool
{
	GENERATED_BODY()

public:
	UMY_PLUGIN_NAMESimpleTool();

	virtual void SetWorld(UWorld* World);

	virtual void Setup() override;

	virtual void OnClicked(const FInputDeviceRay& ClickPos);


protected:
	UPROPERTY()
	TObjectPtr<UMY_PLUGIN_NAMESimpleToolProperties> Properties;


protected:
	/** target World we will raycast into to find actors */
	UWorld* TargetWorld;
};