// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TileView.h"
#include "BackpackUiMain.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEROOM_API UBackpackUiMain : public UUserWidget
{
	GENERATED_BODY()

public:
    // init backpack
    UFUNCTION(BlueprintCallable, Category = "Backpack")
    void InitializeBackpack();

    UFUNCTION(BlueprintCallable, Category = "Backpack")
    void UpdateBackpackItem();

private:

    //items in backpack
    UPROPERTY(meta = (BindWidget))
    UTileView* TileviewItems;
};
