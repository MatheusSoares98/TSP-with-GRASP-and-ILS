#ifndef GRASP_H 
#define GRASP_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>  
#include "file.h"
#include "auxiliary.h"
#include "initial_solution.h"
#include "local_search.h"

#include <string.h> 

int grasp(int numberOfIterations, int numberOfCities, int distances[][numberOfCities], city cities[], step path[]) {
	clock_t start_t, end_t, total_t;
	start_t = clock();
	step tempPath[numberOfCities];
	copy_path(numberOfCities, path, tempPath);
	double minimumResult = INFINITY;
	int currentResult;
	for (int i = 0; i < numberOfIterations; ++i)
	{
		initialize_cities_as_not_visited(numberOfCities, cities);
		nearestNeighbor(numberOfCities, cities, distances, tempPath);
		currentResult = opt2(numberOfCities, tempPath);
		if (currentResult < minimumResult)
		{
			minimumResult = currentResult;
			copy_path(numberOfCities, tempPath, path);
		}
	}
	end_t = clock();
	total_t = (long int)(end_t - start_t);
   	printf("Total time taken by CPU: %f\n", (float)total_t / CLOCKS_PER_SEC);
	return (int)minimumResult;
}

#endif