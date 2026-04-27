#include "GrappleProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"

// Sets default values
AGrappleProjectile::AGrappleProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));
	RootComponent = ProjectileMesh;

	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
	ProjectileComponent->InitialSpeed = 800;
	ProjectileComponent->MaxSpeed = 8500;

	ProjectileMesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void AGrappleProjectile::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("bleehStart"));


}

// Called every frame
void AGrappleProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector AGrappleProjectile::HitFunction() {
	FVector Position = this->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("bleehHit"));
	UE_LOG(LogTemp, Warning, TEXT("Actor location: %s"), *Position.ToString());
	return Position;
}

