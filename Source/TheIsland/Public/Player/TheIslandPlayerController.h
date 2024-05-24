#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TheIslandPlayerController.generated.h"

/**
 * @file TheIslandPlayerController.h RANDOMWORDS
 * @brief RANDOM WORDSRANDOM WORDSRANDOM WORDSRANDOM WORDSRANDOM WORDS
 * 
 * in the meanwhile, it will demonstrate usage of Doxygen-style comments
 * and `#pragma region` for organizing code
 */

/**
 * @region ForwardDeclaration
 * @brief i wanted to find a way to improve 
 * 		readability of code i write, below i use it for the very first time
 *		possibly its totally unnecessery it that specific case, but im freakin proud of myself. NO REASON
 *		contains forward declarations of classes and structs.
 *		These declarations are used to inform the compiler about the existence
 *		of these types before they are fully defined.
 */
#define ForwardDeclaration

#pragma region ForwardDeclaration

	/**
	 * @class UInputMappingContext
	 * @brief Forward declaration of UInputMappingContext class.
	 *
	 * UInputMappingContext is used for mapping input actions within the input system.
	 * DUPA
	 */
class UInputMappingContext; 
											//idk why it provides tooltip for UInputMappingContext and for FInputActionsValue, but does not do that for UEnhancedInputLocalPlayerSubsystem
	/**
	 * @class UEnhancedInputLocalPlayerSubsystem
	 * @brief Forward declaration of UEnhancedInputLocalPlayerSubsystem class. which manages enhanced input handling for a local player.
	 */
class UEnhancedInputLocalPlayerSubsystem;

	/**
	* @struct FInputActionsValue
	* @brief Forward declaration of FInputActionsValue struct.
	*
	* FInputActionsValue holds values related to input actions.
	*/
struct FInputActionsValue;

#pragma endregion ForwardDeclaration 

UCLASS()
class THEISLAND_API ATheIslandPlayerController : public APlayerController
{
	GENERATED_BODY()	
public:
	ATheIslandPlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> PlayerInputContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> InputSubsystem;



private:
	void Move(const FInputActionsValue& InputActionValue);
	void SetupInputSubsystem();
	void SetupMouseCursorProperties();

};
