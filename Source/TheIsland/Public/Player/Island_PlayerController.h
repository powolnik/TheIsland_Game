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

  	UPROPERTY(EditAnywhere, Category = "Island|Input")
	TObjectPtr<UInputMappingContext> PlayerInputContext;
	
private:
	UPROPERTY(EditAnywhere, Category = "Island|Input")
	TObjectPtr<UInputAction> MoveAction;

	TScriptInterface<IEnemyInterface> LastActor;
	TScriptInterface<IEnemyInterface> ThisActor;
	
	UFUNCTION()
	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();
	void SetupInputSubsystem();
	void SetupMouseCursorProperties();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
