// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ui/BackpackUiMain.h"
#include "InputAction.h"

#include "BackpackActorController.generated.h"

UCLASS()
class ESCAPEROOM_API ABackpackActorController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABackpackActorController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// show or hide backpack
	UFUNCTION(BlueprintCallable, Category = "BackpackUI")
	void ToggleBackpackUI();

	UFUNCTION(BlueprintCallable, Category = "BackpackControl")
	static void ControlUpdateBackpackItem();

	UFUNCTION(BlueprintCallable, Category = "BackpackUI")
	void test();

private:
	UPROPERTY(EditAnywhere, Category = "BackpackUI")
	TSubclassOf<UBackpackUiMain> BackpackUIMainClass;

	UPROPERTY(EditAnywhere, Category = "BackpackUI")
	UInputAction* ToggleBackpackAction;

	// instance of backpack
	static UBackpackUiMain* BackpackUIMainInstance;
};
