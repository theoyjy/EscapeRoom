// Fill out your copyright notice in the Description page of Project Settings.


#include "BackpackUiItem.h"
#include "BackpackUiItemData.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"


void UBackpackUiItem::NativeOnListItemObjectSet(UObject* ListItemObject)
{
    if (UBackpackUiItemData* ItemData = Cast<UBackpackUiItemData>(ListItemObject))
    {
        if (ItemTextName)
        {
            ItemTextName->SetText(FText::FromString(ItemData->ItemTextName));
        }

        if (ItemTextCount)
        {
            ItemTextCount->SetText(FText::FromString(ItemData->ItemTextCount));
        }

        if (ItemImageIcon && ItemData->ItemImageIcon)
        {
            ItemImageIcon->SetBrushFromTexture(ItemData->ItemImageIcon);
        }
    }
}