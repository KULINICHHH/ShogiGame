// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"

ABoard* ABoard::BoardInstance = nullptr;

ABoard* ABoard::GetInstance(UWorld* World)
{
    if (BoardInstance == nullptr) {

        UE_LOG(LogTemp, Warning, TEXT("Hello"));
        BoardInstance = NewObject<ABoard>();
        if (World) {
            BoardInstance = World->SpawnActor<ABoard>();
            UE_LOG(LogTemp, Warning, TEXT("Hello"));
        }
    }
    return BoardInstance;
}

// Sets default values
ABoard::ABoard()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Add components to the actor
    UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;
    // Put the default cube mesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeMeshAsset.Succeeded())
    {
        MeshComponent->SetStaticMesh(CubeMeshAsset.Object);
    }
    // Put the material
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("/Script/Engine.Material'/Game/Blueprints/Materials/MBoard.MBoard'"));
    if (MaterialAsset.Succeeded())
    {
        MeshComponent->SetMaterial(0, MaterialAsset.Object);
    }

    // Set up the actor's initialization params
    SetActorLocation(FVector(-40.f, -10.f, 0.f)); // Set initial location
    SetActorRotation(FRotator(0.f, 0.f, 0.f)); // Set initial rotation
    SetActorScale3D(FVector(4.f, 4.f, 0.5f)); // Set initial scale
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
    Super::BeginPlay();
}

void ABoard::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    // Reset the BoardInstance
    BoardInstance = nullptr;
}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

