// Fill out your copyright notice in the Description page of Project Settings.


#include "BackpackActorController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include <Kismet/GameplayStatics.h>

UBackpackUiMain*  ABackpackActorController::BackpackUIMainInstance = nullptr;

// Sets default values
ABackpackActorController::ABackpackActorController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABackpackActorController::BeginPlay()
{
	UE_LOG(LogTemp, Display, TEXT("BackpackActorController Begin"));
	// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::MakeRandomColor(), FString(TEXT("BackpackActorController Begin")));

	Super::BeginPlay();

	if (BackpackUIMainClass == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Please set BackpackUIMainClass"));
	}

	BackpackUIMainInstance = CreateWidget<UBackpackUiMain>(GetWorld(), BackpackUIMainClass);
	if (BackpackUIMainInstance)
	{
		BackpackUIMainInstance->AddToViewport();
		BackpackUIMainInstance->SetVisibility(ESlateVisibility::Hidden);
	}


	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController)
	{
		UEnhancedInputComponent *EnhancedInput = Cast<UEnhancedInputComponent>(PlayerController->InputComponent);
		if (EnhancedInput)
		{
			EnhancedInput->BindAction(ToggleBackpackAction, ETriggerEvent::Triggered, this, &ABackpackActorController::ToggleBackpackUI);
		}
	}

	BackpackUIMainInstance->InitializeBackpack();
}

// Called every frame
void ABackpackActorController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABackpackActorController::ToggleBackpackUI()
{
	UE_LOG(LogTemp, Display, TEXT("ToggleBackpackUI Triggered!"));
	// GEngine->AddOnScreenDebugMessage(-1, 5, FColor::MakeRandomColor(), FString(TEXT("ToggleBackpackUI Triggered!")));

	if (BackpackUIMainInstance != nullptr)
	{
		if (BackpackUIMainInstance->Visibility == ESlateVisibility::Hidden)
		{
			BackpackUIMainInstance->SetVisibility(ESlateVisibility::Visible);

			// stop game and show mouse pointer
			UGameplayStatics::SetGamePaused(GetWorld(), true);
			APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
			if (PlayerController)
			{
				PlayerController->bShowMouseCursor = true;
				PlayerController->SetInputMode(FInputModeGameAndUI());
			}
		}
		else
		{
			BackpackUIMainInstance->SetVisibility(ESlateVisibility::Hidden);

			// resume game
			UGameplayStatics::SetGamePaused(GetWorld(), false);
			APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
			if (PlayerController)
			{
				PlayerController->bShowMouseCursor = false;
				PlayerController->SetInputMode(FInputModeGameOnly());
			}
		}
	}
}

void ABackpackActorController::ControlUpdateBackpackItem()
{
	if (BackpackUIMainInstance != nullptr)
	{
		BackpackUIMainInstance->UpdateBackpackItem();
	}
}


void ABackpackActorController::test()
{

}