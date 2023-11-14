// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPPCourseCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

ACPPCourseCharacter::ACPPCourseCharacter()
{
	// Set size for collision capsule
	check(GetCapsuleComponent());
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the
	// camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	check(GetCharacterMovement());
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); 
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a
	// collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	check(CameraBoom);
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength =
		300.0f; // The camera follows at this distance behind the character
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	check(FollowCamera);
	FollowCamera->SetupAttachment(CameraBoom,
		USpringArmComponent::SocketName); // Attach the camera to the end of the
										  // boom and let the boom adjust to
										  // match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}


void ACPPCourseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction(
		"Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(
		"Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis(
		"MoveForward", this, &ACPPCourseCharacter::MoveForward);
	PlayerInputComponent->BindAxis(
		"MoveRight", this, &ACPPCourseCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of
	// devices differently "turn" handles devices that provide an absolute
	// delta, such as a mouse. "turnrate" is for devices that we choose to treat
	// as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(
		"TurnRate", this, &ACPPCourseCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis(
		"LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(
		"LookUpRate", this, &ACPPCourseCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(
		IE_Pressed, this, &ACPPCourseCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(
		IE_Released, this, &ACPPCourseCharacter::TouchStopped);
}

void ACPPCourseCharacter::MoveForward(const float Value)
{
	Move(EAxis::X, Value);
}

void ACPPCourseCharacter::Move(const EAxis::Type& Axis, const float Value) 
{
	if (Controller && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector  Direction = FRotationMatrix(YawRotation).GetUnitAxis(Axis);
		AddMovementInput(Direction, Value);
	}
}

void ACPPCourseCharacter::MoveRight(const float Value)
{
	Move(EAxis::Y, Value);
}

void ACPPCourseCharacter::TurnAtRate(const float Rate)
{
	// calculate delta for this frame from the rate information
	check(GetWorld());
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACPPCourseCharacter::LookUpAtRate(const float Rate)
{
	// calculate delta for this frame from the rate information
	check(GetWorld());
	AddControllerPitchInput(
		Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}
void ACPPCourseCharacter::TouchStarted(
	ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void ACPPCourseCharacter::TouchStopped(
	ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}
