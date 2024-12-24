// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BackpackUiItemData.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEROOM_API UBackpackUiItemData : public UObject
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ListView")
    FString ItemTextName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ListView")
    FString ItemTextCount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ListView")
    UTexture2D* ItemImageIcon;
};
