// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#define OUT


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

// Tick
//Call Super
//AimTowardsCrosshair();
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardsCrosshair() 
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out Param
	if (GetSightRayHitLocation(OUT HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		//TODO tell controlled tank to aim at this point
	}
	
	// Get world location of linetrace through crosshair
	
	// if hits landscape
		// Tell controlled tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//ray cast in the middle of the screen, 1/3rd of th way down the screen
	//if hit landscape, return the ray cast
	//if not, then idk

	//for now 
	HitLocation = FVector(1.0);
	return true;
}