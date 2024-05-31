// RW&MH

#include "Characters/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/Island_PlayerController.h"
#include "UI/HUD/Island_HUD.h"


APlayerCharacter::APlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	InitializeHUD();
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitializeHUD();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitializeHUD();
}

void APlayerCharacter::InitializeHUD()
{
	if (AIsland_PlayerController* PC = Cast<AIsland_PlayerController>(GetController()))
	{
		if (AIsland_HUD* HUD = Cast<AIsland_HUD>(PC->GetHUD()))
		{
			HUD->InitializeOverlay(PC, GetPlayerState());
		}
		
	}
}
