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

void AIsland_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AIsland_PlayerController::Move);
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

void AIsland_PlayerController::CursorTrace()
{
	FHitResult CursorHit;
	if (!GetHitResultUnderCursor(ECC_Visibility, false, CursorHit))
		{ return; }
	if (!CursorHit.bBlockingHit)
		{ return; }
	
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	HandleActorHighlighting();
}

void AIsland_PlayerController::HandleActorHighlighting()
{
	if (LastActor != ThisActor)
	{
		HighlightActor(LastActor, false);
		HighlightActor(ThisActor, true);
	}
}

void AIsland_PlayerController::HighlightActor(IEnemyInterface* Actor, bool bHighlight)
{
	if (!Actor) { return; }

	Actor->HighlightActor(bHighlight);
}