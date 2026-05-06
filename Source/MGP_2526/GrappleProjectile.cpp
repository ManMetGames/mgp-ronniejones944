#include "GrappleProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"

// Sets default values
AGrappleProjectile::AGrappleProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh")); // mesh component for the blueprint
	RootComponent = ProjectileMesh;
	
	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component")); // projectile component
	ProjectileComponent->InitialSpeed = 800;
	ProjectileComponent->MaxSpeed = 8500;

	ProjectileMesh->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void AGrappleProjectile::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMesh->OnComponentHit.AddDynamic(this,&AGrappleProjectile::OnComponentHit); //binds OnComponentHit to the onhit event
	
}

// Called every frame
void AGrappleProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// returns the position of the grapple projectile and gives it to the player
void AGrappleProjectile::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{ 
	FVector position = this->GetActorLocation(); // returns the position of the grapple projectile
	Player->GrappleLaunch(position, true); //calls the player grapple function and gives the position to the player
}

void AGrappleProjectile::OnDestroyed() 
{
	Player->GrappleLaunch(FVector(0, 0, 0), false); // sets the player to no longer launching
}

void AGrappleProjectile::Destroyed() // run when the projectile is destroyed
{
	Super::Destroyed();
	OnDestroyed();
}