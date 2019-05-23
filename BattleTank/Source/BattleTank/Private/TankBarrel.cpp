// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Core/Public/Math/Rotator.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the Barrel the right amount this frame
	// Given a max elevation speed, and time frame
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);
	auto Time = GetWorld()->GetTimeSeconds();
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}