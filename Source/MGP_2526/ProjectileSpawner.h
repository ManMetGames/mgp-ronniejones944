// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileSpawner.generated.h"

UCLASS()
class MGP_2526_API AProjectileSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectileSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AGrappleProjectile> ProjectileActor;
};
