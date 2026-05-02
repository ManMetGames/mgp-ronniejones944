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
	UPROPERTY(EditAnywhere, Category = "Min Launch Force")
	float MinLaunchForce=9;
	UPROPERTY(EditAnywhere, Category = "Max Launch Force")
	float MaxLaunchForce=40;

	bool IsLaunching = false;
	FVector Position;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	void MoveForward(float InputValue);
	void MoveRight(float InputValue);

	void TurnCamera(float InputValue);
	void LookUp(float InputValue);
	UFUNCTION(BlueprintCallable, Category = "launch")
	void GrappleLaunch(FVector launchPoint, bool launch);

};
