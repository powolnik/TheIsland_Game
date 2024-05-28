#include "Player/TheIslandPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "Interaction/HighlightActorInterface.h"


ATheIslandPlayerController::ATheIslandPlayerController()
{
	bReplicates = true;
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void ATheIslandPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void ATheIslandPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();
	
	// Case A: Both actors are null
	if (LastActor == nullptr && ThisActor == nullptr)
	{
		// Do nothing
		
		UE_LOG(LogTemp, Warning, TEXT("Cursor: Do nothing"));
	}
	// Case B: LastActor is null, ThisActor is valid
	else if (LastActor == nullptr && ThisActor != nullptr)
	{
		ThisActor->HighlightActor(true);
		
		UE_LOG(LogTemp, Warning, TEXT("Cursor: Highlight ThisActor"));
	}
	// Case C: LastActor is valid, ThisActor is null
	else if (LastActor != nullptr && ThisActor == nullptr)
	{
		LastActor->HighlightActor(false);
		
		UE_LOG(LogTemp, Warning, TEXT("Cursor: UnHighlight LastActor"));
	}
	// Case D: Both actors are valid and different
	else if (LastActor != nullptr && ThisActor != nullptr && LastActor != ThisActor)
	{
		LastActor->HighlightActor(false);
		ThisActor->HighlightActor(true);
		
		UE_LOG(LogTemp, Warning, TEXT("Cursor: UnHighlight LastActor, and Highlight ThisActor"));
	}
	// Case E: Both actors are valid and the same (no action needed)
	
/**
 *Line trace from cursor. There are several scenarios:
 *  A.LastActor is null ThisActor is null
 *		- Do nothing
 *  B.LastActor is nuLL ThisActor is valid
 *		- Highlight ThisActor
 *  C.LastActor is vaLid && ThisActor is nul L
 *		- UnHighLight LastActor
 *  D. Both actors are vaLid, but LastActor != ThisActor
 *		- UnHighlight LastActor, and Highlight ThisActor
 *  E. Both actors are vaLid, and LastActor == ThisActor
 *		- Do nothing
 */
}

void ATheIslandPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	SetupInputSubsystem();
	SetupMouseCursorProperties();
}

void ATheIslandPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATheIslandPlayerController::Move);
}

void ATheIslandPlayerController::Move(const FInputActionValue& InputActionValue)
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

void ATheIslandPlayerController::SetupInputSubsystem()
{
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(InputSubsystem);
	check(PlayerInputContext);
	InputSubsystem->AddMappingContext(PlayerInputContext, 0);
}

void ATheIslandPlayerController::SetupMouseCursorProperties()
{
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
