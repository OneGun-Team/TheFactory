// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSGameModeBase.h"
#include "FPSCharacter.generated.h"

class UCameraComponent;
class UInputComponent;

UCLASS()
class THEFACTORY_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = State)
	bool isRun;
	UPROPERTY(VisibleDefaultsOnly, Category = State)
	bool isSit;
	UPROPERTY(VisibleDefaultsOnly, Category = State)
	float defaultWalkSpeed;
	

public:
	// Sets default values for this character's properties
	AFPSCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MovementSpeedValue)
	float runSpeed = 1200.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MovementSpeedValue)
	float walkForwardSpeed = 600.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = MovementSpeedValue)
	float walkRightSpeed = 400.0f;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	AFPSGameModeBase* MyMode;

	void MoveForward(float Val);
	void MoveRight(float Val);

	void OnRun();
	void OnWalk();
	void OnSit();
	void ToggleInventory();


	void TurnAtRate(float Rate);
	void LookUpAtRate(float Rate);

public :
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

private:
	int widgetMode = 0;
};
