// RW&MH

#include "Player/Island_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "Interaction/EnemyInterface.h"


AIsland_PlayerController::AIsland_PlayerController()
{
	bReplicates = true;
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AIsland_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	SetupInputSubsystem();
	SetupMouseCursorProperties();
}

void AIsland_PlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AIsland_PlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();
	
	if (LastActor == nullptr && ThisActor == nullptr)
	{
		// UE_LOG(LogTemp, Warning, TEXT("Cursor: Case A: Both actors are null\nDo nothing"));
	}
	else if (LastActor == nullptr && ThisActor != nullptr)
	{
		ThisActor->HighlightActor(true);	// UE_LOG(LogTemp, Warning, TEXT("Cursor: Case B: LastActor is null, ThisActor is valid\nHighlight ThisActor"));
	}
	else if (LastActor != nullptr && ThisActor == nullptr)
	{
		LastActor->HighlightActor(false);	// UE_LOG(LogTemp, Warning, TEXT("Cursor: Case C: LastActor is valid, ThisActor is null\nUnHighlight LastActor"));
	}
	else if (LastActor != nullptr && ThisActor != nullptr && LastActor != ThisActor)
	{
		LastActor->HighlightActor(false);
		ThisActor->HighlightActor(true);	// UE_LOG(LogTemp, Warning, TEXT("Cursor: Case D: Both actors are valid and different\nUnHighlight LastActor, and Highlight ThisActor"));
	}	// Case E: Both actors are valid and the same (no action needed)
}

void AIsland_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AIsland_PlayerController::Move);
}

void AIsland_PlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AIsland_PlayerController::SetupInputSubsystem()
{
	if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		InputSubsystem->AddMappingContext(PlayerInputContext, 0);
	}
}

void AIsland_PlayerController::SetupMouseCursorProperties()
{
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
