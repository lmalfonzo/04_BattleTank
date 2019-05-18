// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"

void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();

	auto TankAIController = GetAITank();
	if (!TankAIController) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not posessing a tank"));
	} 
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: %s"), *(TankAIController->GetName()));
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Could not find TankPlayerController"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI %s found TankPlayerController=%s"), *(TankAIController->GetName()), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetAITank() const 
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const 
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}