// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	// TODO Clamp throttle values 
	//UE_LOG(LogTemp, Warning, TEXT("Throttling %s Track at %f"), *GetName(), Throttle)

	auto ForceApplied = GetForwardVector() * (Throttle * TrackMaxDrivingForce);
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


