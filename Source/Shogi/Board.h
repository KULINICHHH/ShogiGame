// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "Board.generated.h"

UCLASS()
class SHOGI_API ABoard : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	ABoard();
	UFUNCTION(BlueprintCallable, Category = "Board")
	static ABoard* GetInstance(UWorld* World);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	static ABoard* BoardInstance;
};
