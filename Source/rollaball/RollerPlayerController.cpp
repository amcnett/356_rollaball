// Fill out your copyright notice in the Description page of Project Settings.


#include "RollerPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "rollaballCharacter.h"

void ARollerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void ARollerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARollerPlayerController::Move);
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARollerPlayerController::Look);

		EIC->BindAction(JumpAction, ETriggerEvent::Started, this, &ARollerPlayerController::StartJump);
		EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ARollerPlayerController::StopJump);
		
		EIC->BindAction(AttackAction, ETriggerEvent::Started, this, &ARollerPlayerController::StartAttack);
		EIC->BindAction(AttackAction, ETriggerEvent::Completed, this, &ARollerPlayerController::StopAttack);
	}
}

void ARollerPlayerController::Move(const FInputActionValue& Value)
{
	if (ArollaballCharacter* Char = Cast<ArollaballCharacter>(GetPawn()))
	{
		Char->Move(Value);
	}
}

void ARollerPlayerController::Look(const FInputActionValue& Value)
{
	if (ArollaballCharacter* Char = Cast<ArollaballCharacter>(GetPawn()))
	{
		Char->Look(Value);
	}
}

void ARollerPlayerController::StartJump()
{
	if (ArollaballCharacter* Char = Cast<ArollaballCharacter>(GetPawn()))
	{
		Char->Jump();
	}
}

void ARollerPlayerController::StopJump()
{
	if (ArollaballCharacter* Char = Cast<ArollaballCharacter>(GetPawn()))
	{
		Char->StopJumping();
	}
}

void ARollerPlayerController::StartAttack()
{
	if (ArollaballCharacter* Char = Cast<ArollaballCharacter>(GetPawn()))
	{
		Char->Attack();
	}
}

void ARollerPlayerController::StopAttack()
{
	if (ArollaballCharacter* Char = Cast<ArollaballCharacter>(GetPawn()))
	{
		Char->StopAttack();
	}
}