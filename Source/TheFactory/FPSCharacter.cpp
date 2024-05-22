// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
	
	PrimaryActorTick.bCanEverTick = true;
	isRun = false;

	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

	MyMode = Cast<AFPSGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	defaultWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AFPSCharacter::OnRun);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AFPSCharacter::OnWalk);
	PlayerInputComponent->BindAction("Sit", IE_Pressed, this, &AFPSCharacter::OnSit);
	PlayerInputComponent->BindAction("ToggleInventory", IE_Pressed, this, &AFPSCharacter::ToggleInventory);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFPSCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFPSCharacter::LookUpAtRate);
}

void AFPSCharacter::OnRun() {
	//UE_LOG(LogTemp, Log, TEXT("isRun is true"));
	isRun = true;
}

void AFPSCharacter::OnWalk() {
	//UE_LOG(LogTemp, Log, TEXT("isRun is false"));
	isRun = false;
}

void AFPSCharacter::OnSit() {
	isSit = !isSit;

	if (isSit) {
		FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 24.f));
		walkForwardSpeed = 300.0f;
		runSpeed = 300.0f;
	}
	else {
		FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
		walkForwardSpeed = 600.0f;
		runSpeed = 1200.0f;
	}
}

void AFPSCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		if (isRun) {
			GetCharacterMovement()->MaxWalkSpeed = runSpeed;
		}
		else {
			GetCharacterMovement()->MaxWalkSpeed = walkForwardSpeed;
		}
		// add movement in that direction
		UE_LOG(LogTemp, Log, TEXT("%f"), GetCharacterMovement()->MaxWalkSpeed);
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFPSCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		GetCharacterMovement()->MaxWalkSpeed = walkRightSpeed;
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AFPSCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFPSCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AFPSCharacter::ToggleInventory() {
	widgetMode = widgetMode == 0 ? 1 : 0;
	MyMode->ChangeFPSWidget(widgetMode);
}