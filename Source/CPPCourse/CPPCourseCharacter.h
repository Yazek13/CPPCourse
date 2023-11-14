// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPPCourseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputComponent;

UCLASS()
class ACPPCourseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACPPCourseCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate.
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	FORCEINLINE USpringArmComponent* GetCameraBoom() const
	{
		return CameraBoom;
	}

	FORCEINLINE UCameraComponent* GetFollowCamera() const
	{
		return FollowCamera;
	}

protected:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* FollowCamera;

	virtual void SetupPlayerInputComponent(
		UInputComponent* PlayerInputComponent) override;

	/** Called for forwards/backward input */
	void MoveForward(const float Value);

	/** Called for side to side input */
	void MoveRight(const float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired
	 * turn rate
	 */
	void TurnAtRate(const float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired
	 * turn rate
	 */
	void LookUpAtRate(const float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
	
private:
	void Move(const EAxis::Type& Axis, const float Value);
};
