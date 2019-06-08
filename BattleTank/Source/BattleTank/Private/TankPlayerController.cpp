// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankAimingComponent.h"
#define OUT

// Sets up the tank, Called at the beginnning of play
void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();
}

// Every tick, aim the tank to the crosshair
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

// Attempts to get a controlled tank (casts Pawn to ATank)
ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

// Aims a tank towards a crosshair
void ATankPlayerController::AimTowardsCrosshair() 
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out Param
	if (GetSightRayHitLocation(OUT HitLocation))
	{
		//TODO This is also probably bad practice, change later
		if (!GetControlledTank()->GetAimingComponent()) { return; }
		GetControlledTank()->GetAimingComponent()->AimAt(HitLocation);
	}
	
}

// Get a ray hit location from a certain position on the screen, true if found false if not (ex. the skybox)
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// find crosshair pos
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		// line-trace along that look dir, and see what we end up hitting up to a max range
		GetLookVectorHitLocation(OUT LookDirection, HitLocation);
	}

	return true;
}

// Gets the direction the camera is facing given a screen location to a world, lazer pointer
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const 
{
	FVector WorldLocation;
	if (DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		WorldLocation, 
		OUT LookDirection))
	{
		return true;
	}
	return false;
}

// Gets hit location from a line trace, only called if @GetLookDirection(ScreenLocation, LookDirection), is true
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	// if line trace succeds
		// set hit location
			//return true
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		) {
		OUT HitLocation = HitResult.Location;
		return true;
	}
	//line trace didn't succeed
	return false;
}