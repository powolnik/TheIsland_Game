// RW&MH

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Interaction/EnemyInterface.h"
#include "Island_PlayerController.generated.h"

class UInputMappingContext;
class UEnhancedInputLocalPlayerSubsystem;
class UInputAction;
struct FInputActionsValue;


UCLASS()
class THEISLAND_API AIsland_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AIsland_PlayerController();
	virtual void PlayerTick(float DeltaTime) override;
	void HandleActorHighlighting();
	static void HighlightActor(IEnemyInterface* Actor, bool bHighlight);

private:
	UPROPERTY(EditAnywhere, Category = "Island|Input")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditAnywhere, Category = "Island|Input")
	TObjectPtr<UInputMappingContext> PlayerInputContext;

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
	
#pragma region private_Methods
	UFUNCTION()
	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	void SetupInputSubsystem();
	void SetupMouseCursorProperties();
#pragma endregion 

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
