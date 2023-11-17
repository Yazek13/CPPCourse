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
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
