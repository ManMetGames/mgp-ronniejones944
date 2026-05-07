#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Player/MyCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GrappleProjectile.generated.h"

UCLASS()
class MGP_2526_API AGrappleProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGrappleProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "hit")
	void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintCallable, Category = "Destroyed")
	void OnDestroyed();

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* ProjectileComponent;

	UPROPERTY(EditAnywhere)
	AMyCharacter* Player;

	UPROPERTY(EditAnywhere)
	int GrappleGunNumber;

};
