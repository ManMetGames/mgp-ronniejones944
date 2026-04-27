#include "Player/MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "ProjectileSpawner.h"
#include "GrappleProjectile.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Position = FVector(920.0, -510.0,1050.0);
	FVector PlayerPosition = this->GetActorLocation();
	FVector GrappleDirection = Position - PlayerPosition;
	GrappleDirection.Normalize(1);

	/*LaunchVector.Z = LaunchForce;
	LaunchVector.X = LaunchForce;*/
	LaunchCharacter(GrappleDirection*LaunchForce, false, false);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAxis("TurnCamera", this, &AMyCharacter::TurnCamera);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUp);
}

void AMyCharacter::MoveForward(float InputValue)
{
	FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, InputValue);
}

void AMyCharacter::MoveRight(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);
}

void AMyCharacter::TurnCamera(float InputValue)
{
	AddControllerYawInput(InputValue);
}

void AMyCharacter::LookUp(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

void AMyCharacter::GrappleLaunch() 
{

}