// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "BlasterCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class BLASTER_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABlasterCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;

protected:
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* BlasterContext;

    UPROPERTY(EditAnywhere, Category = Input)
    UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = Input)
    UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
    UInputAction* JumpAction;

	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);

private:	
    UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;
      
    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* OverheadWidget;

public:

	

};
