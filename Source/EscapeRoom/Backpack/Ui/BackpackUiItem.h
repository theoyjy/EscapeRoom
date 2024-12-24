// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "BackpackUiItem.generated.h"

/**
 * 
 */

class UTextBlock;
class UImage;

class UButton;

UCLASS()
class ESCAPEROOM_API UBackpackUiItem : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
public:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

protected:
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ItemTextName;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ItemTextCount;

    UPROPERTY(meta = (BindWidget))
    UImage* ItemImageIcon;

    UPROPERTY(meta = (BindWidget))
    UButton* ItemButtonClick;
};
