// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileSpawner.h"
#include "GrappleProjectile.h"
#include "Logging/StructuredLog.h"

// Sets default values
AProjectileSpawner::AProjectileSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Cable = CreateDefaultSubobject<UCableComponent>(TEXT("Cable"));
	Cable->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AProjectileSpawner::BeginPlay()
{
	Super::BeginPlay();

	/*AProjectileSpawner::Shoot();*/
	tick = 0;

	Cable->SetVisibility(false);
}

// Called every frame
void AProjectileSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*tick++;
	if (tick % 100 == 0) {
		AProjectileSpawner::Shoot();
	}*/
}

void AProjectileSpawner::Shoot() {
	if (canFire) {
		CurrentProjectile = GetWorld()->SpawnActor<AGrappleProjectile>(ProjectileActor, GetActorLocation(), GetActorRotation());
		ProjectileLocation = CurrentProjectile->GetActorLocation();

		USceneComponent* CurrentProjectileComp = CurrentProjectile->GetRootComponent();
		Cable->SetAttachEndToComponent(CurrentProjectileComp, NAME_None);
		Cable->SetVisibility(true);
	}
	canFire = false;
}

void AProjectileSpawner::OnRelease() // Performed on release of the shoot button
{
	CurrentProjectile->Destroy(); // Destroys the projectile
	canFire = true; // Allows the player to shoot again
	Cable->SetVisibility(false); // makes the cable invisible
}

