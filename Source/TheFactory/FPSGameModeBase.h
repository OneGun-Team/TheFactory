// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "FPSGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class THEFACTORY_API AFPSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category="UMG")
	void ChangeFPSWidget(int widgetMode);
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="UMG")
	TSubclassOf<UUserWidget> playWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG")
	TSubclassOf<UUserWidget> inventoryWidget;

	UPROPERTY()
	UUserWidget* currWidget;
	UPROPERTY()
	TSubclassOf<UUserWidget> nextWidget;
};

