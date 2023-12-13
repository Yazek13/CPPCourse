// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CourseActor.generated.h"

USTRUCT(BlueprintType)
struct FCourseItemInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Test Var")
	FName Name;

	UPROPERTY(BlueprintReadOnly)
	UTexture2D* Texture;
};

USTRUCT(BlueprintType)
struct FCourseMeshAndMaterial
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Test StaticMesh")
	UStaticMesh* MyStaticMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Test Material")
	UMaterial* MyMaterial;

	UPROPERTY()
	UStaticMeshComponent* StaticMeshComponent;
};

UENUM(BlueprintType)
enum class ECourseColor : uint8
{
	Red = 0,
	Green,
	Blue
};

UCLASS()
class CPPCOURSE_API ACourseActor : public AActor
{
	GENERATED_BODY()

public:
	ACourseActor();
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FCourseItemInfo Info;

	UPROPERTY(EditInstanceOnly)
	FCourseMeshAndMaterial MeshAndMaterial;
	
	UPROPERTY(EditDefaultsOnly)
	ECourseColor Color;
	
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

	UFUNCTION(BlueprintNativeEvent)
	void GetMyText();

	virtual void BeginPlay() override;
};
