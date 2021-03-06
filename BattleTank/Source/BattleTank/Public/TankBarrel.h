// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float);  
	// -1 is max downward speed and +1 is max up movement
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 10.f; 

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevation = 30.f; 

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevation = 0.f;
};
