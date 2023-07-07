// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CatmullRomSpline.generated.h"

/**
 * 
 */
UCLASS()
class PROCEDURALALGORITHMS_API UCatmullRomSpline : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Catmull–Rom Spline interpolation", Keywords = "Catmull–Rom Spline interpolation"), Category = "ProceduralAlgorithms")
	static FVector CatmullRomSplineInterp(FVector p_mi1, FVector p_0, FVector p_1, FVector p_2, float t);
};
