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
int count_unvisited_cities(int numberOfSteps, city cities[]) {
	int hasUnvisitedCities = 0;
	for (int i = 0; i < numberOfSteps; ++i)
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
int calculate_total_distance(int numberOfsteps, step steps[numberOfsteps]) {
	int distance = 0;
	for (int i = 0; i < numberOfsteps; ++i)
	{
		distance += steps[i].distance; 
	}
	return (int)distance;
}
void initialize_cities_as_not_visited(int numberOfSteps, city cities[]){
	for (int i = 0; i < numberOfSteps; ++i)
	{
		cities[i].visited = false;
	}
}
void create_distance_matrix(int numberOfSteps, city cities[], int distances[][numberOfSteps]) {
	for (int i = 0; i < numberOfSteps; ++i)
	{
		for (int j = 0; j < numberOfSteps; ++j)
		{
			distances[i][j] = calculate_distance(cities[i], cities[j]);
		}
	}
}

void copy_cities(int numberOfSteps, city citiesToCopy[], city copyCities[]) {
	for (int i = 0; i < numberOfSteps; ++i)
	{
		copyCities[i] = citiesToCopy[i];
	}
}

void copy_path(int numberOfSteps, step pathToCopy[numberOfSteps], step copyPath[numberOfSteps]) {
	for (int i = 0; i < numberOfSteps; ++i)
	{
		copyPath[i] = pathToCopy[i];
	}
}

void print_path(int numberOfSteps, step path[]) {
	printf("\n");
	for (int i = 0; i < numberOfSteps; ++i)
	{
		printf("%d, %d--->%d, %d  \n", path[i].start.xCoordinate, path[i].start.yCoordinate, path[i].finish.xCoordinate, path[i].finish.yCoordinate);
	}
	printf("\n");
	for (int i = 0; i < numberOfSteps; ++i)
	{
		printf("%d  ", path[i].distance);
	}
	printf("\n");
}
void print_distance_matrix(int numberOfSteps, int distances[numberOfSteps][numberOfSteps]) {
	for (int i = 0; i < numberOfSteps; ++i)
	{
		for (int j = 0; j < numberOfSteps; ++j)
		{
			printf("%d ", distances[i][j]);
			if (j == numberOfSteps-1)
			{
			printf("\n");
			}
		}
		
	}
}
#endif