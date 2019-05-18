// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto PossessedTank = GetControlledTank();
	if (!PossessedTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Possessed Tank: %s"), *(PossessedTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}


