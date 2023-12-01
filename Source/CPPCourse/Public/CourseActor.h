// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CourseActor.generated.h"

UCLASS()
class CPPCOURSE_API ACourseActor : public AActor
{
	GENERATED_BODY()

public:
	ACourseActor();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY()
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditDefaultsOnly)
	uint16 Money = 125;

	UPROPERTY(EditInstanceOnly)
	float MyFloat = 1.25f;

	UPROPERTY(VisibleAnywhere)
	FString MyText = TEXT("My First Text");

	UPROPERTY(EditInstanceOnly)
	UStaticMesh* StaticMesh;

	UPROPERTY(EditInstanceOnly)
	FRotator Rotation;


	virtual void BeginPlay() override;
};
