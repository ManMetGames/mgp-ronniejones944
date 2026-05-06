// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GrappleProjectile.h"
#include "Player/MyCharacter.h"
#include "CableComponent.h"
#include "ProjectileSpawner.generated.h"

UCLASS()
class MGP_2526_API AProjectileSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectileSpawner();

	UFUNCTION(BlueprintCallable, Category = "Shoot")
		void Shoot();

	UFUNCTION(BlueprintCallable, Category = "Release")
		void OnRelease();

	UPROPERTY(EditAnywhere, Category = "Cable")
		class UCableComponent* Cable;

	UPROPERTY(EditAnywhere)
		AGrappleProjectile* CurrentProjectile;

	UPROPERTY(EditAnywhere)
	int GrappleGunNumber=0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool canFire = true;
	AActor*  PlayerActor;
	AMyCharacter* Player;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AGrappleProjectile> ProjectileActor;
};
