#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class MGP_2526_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(EditAnywhere, Category = "Launch Force")
	float LaunchForce=15;
	//bool IsLaunching = false;
	bool IsLaunching[2] = {false,false};

	FVector Position;
	FVector Positions[2] = {FVector(0,0,0),FVector(0,0,0)};

	FVector LaunchPositions[2] = { FVector(0,0,0),FVector(0,0,0) };
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector GrappleDirection = FVector(0, 0, 0);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "launch")
	void GrappleLaunch(FVector launchPoint, bool launch, int GrappleGunNumber);
protected:
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void TurnCamera(float InputValue);
	void LookUp(float InputValue);

};
