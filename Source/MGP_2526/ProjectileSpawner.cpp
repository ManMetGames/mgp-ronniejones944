// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileSpawner.h"
#include "GrappleProjectile.h"

// Sets default values
AProjectileSpawner::AProjectileSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectileSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->SpawnActor<AGrappleProjectile>(ProjectileActor, GetActorLocation(), GetActorRotation());
}

// Called every frame
void AProjectileSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

