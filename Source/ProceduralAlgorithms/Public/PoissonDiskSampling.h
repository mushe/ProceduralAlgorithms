// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PoissonDiskSampling.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALALGORITHMS_API UPoissonDiskSampling : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PoissonDiskSampling2D", Keywords = "Poisson Disk Sampling on 2D with radius(r) and serch iteration max(k=30 recommend) and area(Vector2D)"), Category = "ProceduralAlgorithms")
	static TArray<FVector2D> PoissonDiskSampling2D(float r, int k, FVector2D area);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PoissonDiskSampling2D Nearly N", Keywords = "Poisson Disk Sampling on 2D with Count(nearly N) and serch iteration max(k=30 recommend) and area(Vector2D) and radius(r) is automatically calculated by N (not accurate)"), Category = "ProceduralAlgorithms")
	static TArray<FVector2D> PoissonDiskSampling2DNearlyN(int N, int k, FVector2D area);
};
