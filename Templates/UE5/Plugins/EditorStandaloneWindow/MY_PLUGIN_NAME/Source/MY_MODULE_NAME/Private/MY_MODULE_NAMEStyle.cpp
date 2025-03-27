// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_MODULE_NAMEStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FMY_MODULE_NAMEStyle::StyleInstance = nullptr;

void FMY_MODULE_NAMEStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FMY_MODULE_NAMEStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FMY_MODULE_NAMEStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MY_MODULE_NAMEStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FMY_MODULE_NAMEStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("MY_MODULE_NAMEStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("MY_PLUGIN_NAME")->GetBaseDir() / TEXT("Resources"));

	Style->Set("MY_MODULE_NAME.OpenPluginWindow", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));

	return Style;
}

void FMY_MODULE_NAMEStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FMY_MODULE_NAMEStyle::Get()
{
	return *StyleInstance;
}
