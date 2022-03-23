#ifndef GRASP_H 
#define GRASP_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>  
#include "auxiliary.h"
#include "initial_solution.h"
#include "local_search.h"
 

int grasp(int iterationsWithoutImprovement, int numberOfCities, int distances[][numberOfCities], city cities[], step path[], FILE *f, float alpha, clock_t *total_t) {
	clock_t start_t, end_t;
	start_t = clock();
	step tempPath[numberOfCities];
	copy_path(numberOfCities, path, tempPath);
	double minimumResult = INFINITY;
	int currentResult, totalIterations;
	for (int i = 0; i < iterationsWithoutImprovement; ++i, totalIterations++)
	{
		initialize_cities_as_not_visited(numberOfCities, cities);
		nearest_neighbor(numberOfCities, cities, distances, tempPath, alpha);
		currentResult = opt2(numberOfCities, tempPath);
		if (currentResult < minimumResult)
		{
			i = 0;
			minimumResult = currentResult;
			copy_path(numberOfCities, tempPath, path);
		}
	}
	end_t = clock();
	*total_t = (long int)(end_t - start_t);
   	//printf("Total time taken by CPU: %f\n", (float)*total_t / CLOCKS_PER_SEC);
	return (int)minimumResult;
}

#endif