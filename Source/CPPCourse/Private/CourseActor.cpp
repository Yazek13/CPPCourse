// Fill out your copyright notice in the Description page of Project Settings.

#include "CourseActor.h"

ACourseActor::ACourseActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(
		"StaticMeshComponent"));
	SetRootComponent(StaticMeshComponent);
}

void ACourseActor::OnConstruction(const FTransform& Transform) 
{
	Super::OnConstruction(Transform);
	check(StaticMeshComponent);
	StaticMeshComponent->SetStaticMesh(StaticMesh);
	StaticMeshComponent->SetWorldRotation(Rotation);
}

void ACourseActor::GetMyText_Implementation() 
{
	UE_LOG(LogTemp, Warning, TEXT("My Function"));
}

void ACourseActor::BeginPlay()
{
	Super::BeginPlay();
	FText TextHealth = FText::FromString(TEXT("Health"));
	FText TextStamina = FText::FromString(TEXT("Stamina"));
	FText TextCoins = FText::FromString(TEXT("Coins"));
	FText PlayerLocations = FText::FromString(TEXT("Locations"));
	uint8 PlayerHealth = 100;
	uint8 PlayerStamina = 100;
	uint32 PlayerCoins = 0;
	FVector Locations(0.0, 0.0, 0.0);
	GetMyText();
	

	GEngine->AddOnScreenDebugMessage(
		INDEX_NONE, 5.0f, FColor::Red, TEXT("Hello!!!"));
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Green,
		FString::Printf(TEXT("PlayerStamina = %llu, PlayerHealth = %llu"),
			PlayerStamina, PlayerHealth));
	
}

void ACourseActor::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
}

