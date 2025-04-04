// Copyright Epic Games, Inc. All Rights Reserved.

#include "MY_PLUGIN_NAMEStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FMY_PLUGIN_NAMEStyle::StyleInstance = nullptr;

void FMY_PLUGIN_NAMEStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FMY_PLUGIN_NAMEStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FMY_PLUGIN_NAMEStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MY_PLUGIN_NAMEStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FMY_PLUGIN_NAMEStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("MY_PLUGIN_NAMEStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("MY_PLUGIN_NAME")->GetBaseDir() / TEXT("Resources"));

	Style->Set("MY_PLUGIN_NAME.OpenPluginWindow", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));

	return Style;
}

void FMY_PLUGIN_NAMEStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FMY_PLUGIN_NAMEStyle::Get()
{
	return *StyleInstance;
}
