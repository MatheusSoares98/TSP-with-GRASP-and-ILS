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

int grasp(int numberOfIterations, int numberOfCities, int distances[][numberOfCities], city cities[], step path[], FILE *f, float alpha) {
	clock_t start_t, end_t, total_t;
	start_t = clock();
	step tempPath[numberOfCities];
	copy_path(numberOfCities, path, tempPath);
	double minimumResult = INFINITY;
	int currentResult;
	int i = 0, totalIterations = 0;
	for (i = 0; i < 100; ++i, totalIterations++)
	{
		initialize_cities_as_not_visited(numberOfCities, cities);
		nearestNeighbor(numberOfCities, cities, distances, tempPath, alpha);
		if (i == 0)
		{
			fprintf(f, "grasp with an alpha of: %.1f\ncost after initial solution = %d\n", alpha, calculate_total_distance(numberOfCities, tempPath));
		}
		currentResult = opt2(numberOfCities, tempPath);
		if (currentResult < minimumResult)
		{
			i = 0;
			minimumResult = currentResult;
			copy_path(numberOfCities, tempPath, path);
		}
	}
	end_t = clock();
	total_t = (long int)(end_t - start_t);
   	printf("Total time taken by CPU: %f\n", (float)total_t / CLOCKS_PER_SEC);
   	fprintf(f, "cost after 100 iterations with no improvements = %d\nTime taken by cpu: %f\nTotal number of iterations:%d\n\n\n", (int)minimumResult, (float)total_t / CLOCKS_PER_SEC, totalIterations);
	return (int)minimumResult;
}

#endif