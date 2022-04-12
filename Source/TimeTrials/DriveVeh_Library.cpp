// Fill out your copyright notice in the Description page of Project Settings.


#include "DriveVeh_Library.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "WheeledVehicleMovementComponent.h"
#include "VehicleWheel.h"

TArray<UPhysicalMaterial*> UDriveVeh_Library::GetPhyMatUnderTyres(UWheeledVehicleMovementComponent* VehMovement)
{
    TArray<UPhysicalMaterial*> Mats;
    if(VehMovement)
    {
        for(UVehicleWheel* Wheel : VehMovement->Wheels)
        {
            Mats.Emplace(Wheel->GetContactSurfaceMaterial());
        }
    }
    return Mats;
}

float UDriveVeh_Library::GetMaxSuspensionForce(UWheeledVehicleMovementComponent* VehMovement)
{
    if(VehMovement)
    {
        return VehMovement->GetMaxSpringForce();
    }
    return 0.f;
}

bool UDriveVeh_Library::GetSlipThreshold(UWheeledVehicleMovementComponent* VehMovement, float LongSlipT, float LatSlipT)
{
    if(VehMovement)
    {
        float Long = FMath::Clamp<float>(LongSlipT, 0, 1);
        float Lat = FMath::Clamp<float>(LatSlipT, 0, 1);

        return  VehMovement->CheckSlipThreshold(Long, Lat);


    }
    return false;
}