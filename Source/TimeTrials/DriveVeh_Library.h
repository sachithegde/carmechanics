// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DriveVeh_Library.generated.h"

/**
 * 
 */

class UWheeledVehicleMovementComponent;


UCLASS()
class TIMETRIALS_API UDriveVeh_Library : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static TArray<UPhysicalMaterial*> GetPhyMatUnderTyres(UWheeledVehicleMovementComponent* VehMovement);

	UFUNCTION(BlueprintCallable)
	static float GetMaxSuspensionForce(UWheeledVehicleMovementComponent* VehMovement);

	UFUNCTION(BlueprintCallable)
	static bool GetSlipThreshold(UWheeledVehicleMovementComponent* VehMovement, float LongSlipT, float LatSliptT);
};
