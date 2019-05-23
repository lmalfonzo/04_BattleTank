// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	auto Time = GetWorld()->GetTimeSeconds();
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	// UE_LOG(LogTemp, Warning, TEXT("%f : Rotating Turret at %f"), Time, RawNewRotation)
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}


