// Fill out your copyright notice in the Description page of Project Settings.


#include "BackpackUiMain.h"
#include "Logging/LogMacros.h"
#include "GameFramework/Character.h"

 
void UBackpackUiMain::InitializeBackpack()
{
    UE_LOG(LogTemp, Display, TEXT("Backpack initialized"));

    UActorComponent *BpInventorySystem = nullptr;

    APlayerController *PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        ACharacter *character = Cast<ACharacter>(PlayerController->GetPawn());
        if (character)
        {
            // get BP_Inventory_System BP class
            TArray<UActorComponent *> Components;
            character->GetComponents(Components);
            for (UActorComponent *Component : Components)
            {
                if (Component->GetClass()->GetName().Contains(TEXT("BP_Inventory_System")))
                {
                    UE_LOG(LogTemp, Display, TEXT("Found BP_Inventory_System"));
                    BpInventorySystem = Component;
                    break;
                }
            }
        }
    }

    if (BpInventorySystem)
    {
        FName VariableName = TEXT("Content");
        FProperty *Property = BpInventorySystem->GetClass()->FindPropertyByName(VariableName);
        if (Property)
        {
            if (FArrayProperty *ArrayProperty = CastField<FArrayProperty>(Property))
            {
                void *ArrayPtr = ArrayProperty->ContainerPtrToValuePtr<void>(BpInventorySystem);
                FScriptArrayHelper ArrayHelper(ArrayProperty, ArrayPtr);
                for (int32 i = 0; i < ArrayHelper.Num(); i++)
                {
                    void *StructPtr = ArrayHelper.GetRawPtr(i);

                    for (TFieldIterator<FProperty> It(ArrayProperty->Inner->GetOwnerStruct()); It; ++It)
                    {
                        FProperty *StructProperty = *It;
                        if (FNameProperty *NameProp = CastField<FNameProperty>(StructProperty))
                        {
                            FName Value = *NameProp->ContainerPtrToValuePtr<FName>(StructPtr);
                            UE_LOG(LogTemp, Display, TEXT("ItemID: %s"), *Value.ToString());
                        }
                        else if (FIntProperty *IntProp = CastField<FIntProperty>(StructProperty))
                        {
                            int32 Value = *IntProp->ContainerPtrToValuePtr<int32>(StructPtr);
                            UE_LOG(LogTemp, Display, TEXT("Quantity: %d"), Value);
                        }
                    }
                }
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("BP_Inventory_System not found"));
    }
}

void UBackpackUiMain::UpdateBackpackItem()
{
    UE_LOG(LogTemp, Display, TEXT("Backpack initialized"));
    InitializeBackpack();
    
}