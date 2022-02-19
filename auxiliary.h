#ifndef AUXILIARY_H   
#define AUXILIARY_H
#include <stdlib.h>
#include <time.h>  
#include <stdbool.h>

typedef struct city{
	int xCoordinate;
	int yCoordinate;
    bool visited;

}city;

typedef struct step{
	int distance;
    city start;
    city finish;

}step;

double get_random() {
	return ((double)rand()) / ((double)RAND_MAX);
}

double get_random_interval(double min, double max) {
	return get_random() * (max - min) + min;
}

int count_unvisited_cities(int numberOfCities, city cities[]) {
	int hasUnvisitedCities = 0;
	for (int i = 0; i < numberOfCities; ++i)
	{
		if (cities[i].visited == false)
		{
			hasUnvisitedCities++;
		}
	}
	return hasUnvisitedCities;
}

int calculate_distance(city a, city b) {
	return sqrt( (b.xCoordinate - a.xCoordinate)*(b.xCoordinate - a.xCoordinate) + (b.yCoordinate - a.yCoordinate)*(b.yCoordinate - a.yCoordinate) );
}

int calculate_total_distance(int numberOfCities, step steps[numberOfCities]) {
	int distance = 0;
	for (int i = 0; i < numberOfCities; ++i)
	{
		distance += steps[i].distance; 
	}
	return (int)distance;
}

void initialize_cities_as_not_visited(int numberOfCities, city cities[]){
	for (int i = 0; i < numberOfCities; ++i)
	{
		cities[i].visited = false;
	}
}

void create_distance_matrix(int numberOfCities, city cities[], int distances[][numberOfCities]) {
	for (int i = 0; i < numberOfCities; ++i)
	{
		for (int j = 0; j < numberOfCities; ++j)
		{
			distances[i][j] = calculate_distance(cities[i], cities[j]);
		}
	}
}

void copy_cities(int numberOfCities, city citiesToCopy[], city copyCities[]) {
	for (int i = 0; i < numberOfCities; ++i)
	{
		copyCities[i] = citiesToCopy[i];
	}
}

void copy_path(int numberOfCities, step pathToCopy[numberOfCities], step copyPath[numberOfCities]) {
	for (int i = 0; i < numberOfCities; ++i)
	{
		copyPath[i] = pathToCopy[i];
	}
}

void print_path(int numberOfCities, step path[]) {
	printf("\n");
	for (int i = 0; i < numberOfCities; ++i)
	{
		printf("%d, %d--->%d, %d  \n", path[i].start.xCoordinate, path[i].start.yCoordinate, path[i].finish.xCoordinate, path[i].finish.yCoordinate);
	}
	printf("\n");
	for (int i = 0; i < numberOfCities; ++i)
	{
		printf("%d  ", path[i].distance);
	}
	printf("\n");
}

void print_distance_matrix(int numberOfCities, int distances[numberOfCities][numberOfCities]) {
	for (int i = 0; i < numberOfCities; ++i)
	{
		for (int j = 0; j < numberOfCities; ++j)
		{
			printf("%d ", distances[i][j]);
			if (j == numberOfCities-1)
			{
			printf("\n");
			}
		}
		
	}
}

bool is_a_valid_path(int numberOfCities, step path[numberOfCities]) {
	for (int i = 0; i < numberOfCities-1; ++i)
	{
		if (calculate_distance(path[i].finish, path[i+1].start) != 0)
		{
			return false;
		}
	}
	if (calculate_distance(path[numberOfCities-1].finish, path[0].start) != 0 )
	{
		return false;
	}
	return true;
}

#endif