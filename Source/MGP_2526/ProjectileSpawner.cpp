// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileSpawner.h"
#include "GrappleProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Player/MyCharacter.h"
#include "Logging/StructuredLog.h"

// Sets default values
AProjectileSpawner::AProjectileSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Cable = CreateDefaultSubobject<UCableComponent>(TEXT("Cable")); // creates the cable
	Cable->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AProjectileSpawner::BeginPlay()
{
	Super::BeginPlay();

	Cable->SetVisibility(false); // makes the cable invisible
	PlayerActor = UGameplayStatics::GetActorOfClass(GetWorld(), AMyCharacter::StaticClass());
	Player = Cast<AMyCharacter>(PlayerActor);
}

// Called every frame
void AProjectileSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectileSpawner::Shoot() { // used to fire the grapple projectile
	if (canFire) {
		CurrentProjectile = GetWorld()->SpawnActor<AGrappleProjectile>(ProjectileActor, GetActorLocation(), GetActorRotation()); // creates the projectile
		CurrentProjectile->Player = Player;
		CurrentProjectile->GrappleGunNumber = GrappleGunNumber;
		USceneComponent* CurrentProjectileComp = CurrentProjectile->GetRootComponent();
		Cable->SetAttachEndToComponent(CurrentProjectileComp, NAME_None);
		Cable->SetVisibility(true); // makes the cable visible
	}
	canFire = false;
}

void AProjectileSpawner::OnRelease() // Performed on release of the shoot button
{
	CurrentProjectile->Destroy(); // Destroys the projectile
	canFire = true; // Allows the player to shoot again
	Cable->SetVisibility(false); // makes the cable invisible again
}

