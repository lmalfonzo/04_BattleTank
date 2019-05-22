// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Engine/World.h"



void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the Barrel the right amount this frame
	// Given a max elevation speed, and time frame
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f : Elevating Barrel"), Time)
}