// Fill out your copyright notice in the Description page of Project Settings.


#include "CatmullRomSpline.h"

FVector UCatmullRomSpline::CatmullRomSplineInterp(FVector p_mi1, FVector p_0, FVector p_1, FVector p_2, float t)
{
    FVector a4 = p_0;
    FVector a3 = (p_1 - p_mi1) / 2.0f;
    FVector a1 = (p_2 - p_0) / 2.0f - 2.0f * p_1 + a3 + 2.0f * a4;
    FVector a2 = 3.0f * p_1 - (p_2 - p_0) / 2.0f - 2.0f * a3 - 3.0f * a4;

    return a1 * t * t * t + a2 * t * t + a3 * t + a4;
}
