// RW&MH


#include "Characters/IslandCharacterBase.h"

// Sets default values
AIslandCharacterBase::AIslandCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIslandCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIslandCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIslandCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

