#ifndef ILS_H 
#define ILS_H
#ifndef BRIDGE_SIZE
#define BRIDGE_SIZE 4
#endif
#ifndef RAND_MAX
#define RAND_MAX 10
#endif
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include "initial_solution.h"
#include "local_search.h"
#include "auxiliary.h"

void generate_random_positions(int size, int pos[BRIDGE_SIZE]) {
	int aux = 0, cursor = 0, counter = 0;
	bool unique = false;
	for (int i = 0; i < BRIDGE_SIZE; )
	{
		aux = rand() % size;
		for (int j = 0; j < cursor || cursor == 0; j++, counter++)
		{
			if(cursor == 0){
				unique = true;
				break;
			}
			else if (aux == pos[j]) {
				break;
			}
			else if (aux == pos[j] + 1) {
				break;
			}
			else if(aux == pos[j] - 1){
				break;
			}
			else if(aux == 0 && pos[j] == size-1 || aux == size-1 && pos[j] == 0)
			{
				break;
			}
			else if (j == cursor - 1)
			{
				unique = true;
			}
		}
		if(unique == true || cursor == 0) {
			pos[i] = aux;	
			i++;
			cursor++;
		}
		if (counter > 10)
		{
			return generate_random_positions(size, pos);
		}
		unique = false;	
	}

}

void bubble_sort(int pos[BRIDGE_SIZE]) {
	int  n = BRIDGE_SIZE, i, j, swap;
	bool flag = false;
	
	for(i = 0 ; i < n - 1; i++) {
		flag = false;
		for(j = 0 ; j < n-i-1; j++) {
			if(pos[j] > pos[j+1]) {
				swap = pos[j];
				pos[j] = pos[j+1];
				pos[j+1] = swap;
				flag = true;
			}
		}
		if(!flag) {
			break;
		}
	}
}

void create_successors_array(int numberOfCities, int pos[BRIDGE_SIZE], int successors[numberOfCities], int successorsCopy[numberOfCities]) {
	int aux;
	
	for (int i = 0; i < numberOfCities; ++i)
	{
		successors[i] = i + 1;
	}
	successors[numberOfCities-1] = 0;
	
	aux = successors[pos[0]];
	successors[pos[0]] = successors[pos[2]];
	successors[pos[2]] = aux;
	aux = successors[pos[1]];
	successors[pos[1]] = successors[pos[3]];
	successors[pos[3]] = aux;

}

void double_bridge(int numberOfCities, step path[numberOfCities]) {
	int pos[BRIDGE_SIZE] = {-3,-3, -3, -3};
	int successors[numberOfCities], successorsCopy[numberOfCities];
	step copy[numberOfCities];
	copy_path(numberOfCities, path, copy);
	city swap;
	generate_random_positions(9, pos);
	bubble_sort(pos);
	create_successors_array(numberOfCities, pos, successors, successorsCopy);
	swap = path[pos[0]].finish;
	path[pos[0]].finish = path[pos[2]].finish;
	path[pos[2]].finish = swap;

	swap = path[pos[1]].finish;
	path[pos[1]].finish = path[pos[3]].finish;
	path[pos[3]].finish = swap;

	for (int i = 0; i < numberOfCities; ++i)
	{
		successorsCopy[i] = successors[i];
	}
	copy[0]= path[0];
	
	for (int i = 1; i < numberOfCities; ++i)
	{
		copy[i] = path[successorsCopy[i-1]];
		successorsCopy[i] = successors[successorsCopy[i-1]];
	}

	copy_path(numberOfCities, copy, path);
}

int ils(int iterationsWithoutImprovement, int numberOfCities, int distances[][numberOfCities], city cities[], step path[], FILE *f, float alpha)
{
	clock_t start_t, end_t, total_t;
	start_t = clock();
	step tempPath[numberOfCities];
	
	double minimumResult = INFINITY;
	int currentResult, totalIterations;
	initialize_cities_as_not_visited(numberOfCities, cities);
	nearest_neighbor(numberOfCities, cities, distances, path, alpha);
	currentResult = opt2(numberOfCities, path);
	
	for (int i = 0; i < iterationsWithoutImprovement; ++i, totalIterations++)
	{
		copy_path(numberOfCities, path, tempPath);
		double_bridge(numberOfCities, tempPath);
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
	return (int)minimumResult;
}

#endif