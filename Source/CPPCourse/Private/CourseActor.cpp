// Fill out your copyright notice in the Description page of Project Settings.

#include "CourseActor.h"

ACourseActor::ACourseActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ACourseActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACourseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
