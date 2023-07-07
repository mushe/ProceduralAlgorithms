// Fill out your copyright notice in the Description page of Project Settings.


#include "PoissonDiskSampling.h"

TArray<FVector2D> UPoissonDiskSampling::PoissonDiskSampling2D(float r, int k, FVector2D area)
{
	TArray<FVector2D> res;
	TArray<int> activeList;

	// -----------------------------------------------
	// Step 0.
	// -----------------------------------------------
	float cellSize = r / FMath::Sqrt(2.0f);

	int cols = FMath::Floor(area.X / cellSize) + 1;
	int rows = FMath::Floor(area.Y / cellSize) + 1;

	TArray<TArray<int>> grid;
	for (int i = 0; i < rows; i++)
	{
		TArray<int> arr;
		for (int j = 0; j < cols; j++)
		{
			arr.Add(-1);
		}
		grid.Add(arr);
	}

	// -----------------------------------------------
	// Step 1.
	// -----------------------------------------------
	float initialX = FMath::FRandRange(0.0f, area.X);
	float initialY = FMath::FRandRange(0.0f, area.Y);
	FVector2D initialPosition = FVector2D(initialX, initialY);

	int initialXIndex = FMath::Floor(initialX / cellSize);
	int initialYIndex = FMath::Floor(initialY / cellSize);
	grid[initialYIndex][initialXIndex] = 0;

	activeList.Add(0);
	res.Add(initialPosition);

	// -----------------------------------------------
	// Step 2.
	// -----------------------------------------------
	int currentIndex = 0;
	while (activeList.Num() > 0)
	{
		auto activeIndex = activeList[FMath::RandRange(0, activeList.Num() - 1)];
		auto activePos = res[activeIndex];

		bool found = false;
		for (int i = 0; i < k; i++)
		{
			float radian = FMath::RandRange(0.0f, 2.0f * PI);
			float radius = FMath::RandRange(r, r * 2.0f);
			FVector2D p = FVector2D(cos(radian), sin(radian)) * radius + activePos;

			int xIndex = FMath::Floor(p.X / cellSize);
			int yIndex = FMath::Floor(p.Y / cellSize);
			if (xIndex < 0 || yIndex <0 || xIndex > cols - 1 || yIndex > rows - 1)
			{
				continue;
			}

			if (grid[yIndex][xIndex] == -1)
			{
				bool farFromAll = true;
				for (int j = -1; j <= 1; j++)
				{
					for (int k = -1; k <= 1; k++)
					{
						int checkXIndex = xIndex + k;
						int checkYIndex = yIndex + j;
						if (checkXIndex < 0 || checkYIndex <0 || checkXIndex > cols - 1 || checkYIndex > rows - 1) continue;

						int checkIndex = grid[checkYIndex][checkXIndex];
						if (checkIndex == -1) continue;

						FVector2D targetPos = res[checkIndex];
						if ((targetPos - p).Length() < r) farFromAll = false;
					}
				}

				if (farFromAll)
				{
					currentIndex++;
					grid[yIndex][xIndex] = currentIndex;
					activeList.Add(currentIndex);
					res.Add(p);
					found = true;
					break;
				}
			}
		}
		if (!found)
		{
			activeList.Remove(activeIndex);
		}
	}

	return res;
}

TArray<FVector2D> UPoissonDiskSampling::PoissonDiskSampling2DNearlyN(int N, int k, FVector2D area)
{
	float r = sqrt(area.X * area.Y / float(N)) * 0.84f;
	return PoissonDiskSampling2D(r, k, area);
}