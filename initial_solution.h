#ifndef INITIAL_SOLUTION_H  
#define INITIAL_SOLUTION_H
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>
#include "auxiliary.h"

int find_nearest(int numberOfCities, int currentCity, int distances[][numberOfCities], city cities[]);

void nearestNeighbor(int numberOfCities, city cities[], int distances[][numberOfCities], step path[]){
    int nearest = 0;
    int currentStop = 0;
    int i;
    int pos = get_random_interval(0, numberOfCities-0.01);
    int currentCity = pos, currentCityCopy;
    cities[pos].visited = true;
    int firstcity = currentCity;
    double alpha = get_random_interval(0, 1);
    
    for (i = 0; i < numberOfCities && (count_unvisited_cities(numberOfCities, cities) > 0); ++i)
	{
		city citiesCopy[numberOfCities];
		copy_cities(numberOfCities, cities, citiesCopy);
		int size = (int)get_random_interval(1, count_unvisited_cities(numberOfCities, citiesCopy) + 0.99);
        //printf("size = %d\n", size);
        if (size * alpha >=1 )
        {
            size *= alpha;
        }

		int LCR[size];
		for (int i = 0; i < size; ++i)
		{
			nearest = find_nearest(numberOfCities, currentCity, distances, citiesCopy);
			citiesCopy[nearest].visited = true;
			currentCityCopy = nearest;
			LCR[i] = nearest;
		}
		
		pos = rand() % size;;

		nearest = LCR[pos];
		
		cities[nearest].visited = true;
		
		path[currentStop].start = cities[currentCity];
    	path[currentStop].finish = cities[nearest];

    	path[currentStop].distance = calculate_distance(path[currentStop].start, path[currentStop].finish);
    	currentCity = nearest;
    	currentStop++;
	}

    path[numberOfCities-1].start = path[numberOfCities-2].finish;
    path[numberOfCities-1].finish = cities[firstcity];
	path[numberOfCities-1].distance = calculate_distance(path[numberOfCities-1].start, path[numberOfCities-1].finish);  	
}

int find_nearest(int numberOfCities, int currentCity, int distances[][numberOfCities], city cities[]) {
	double shortestDistance = INFINITY;
	
	int nearest = 0;
	for(int j = 0; j < numberOfCities; j++){    
		if(j == currentCity){
            continue;
        }
        else if (cities[j].visited == true)
        {
        	continue;
        }
        else if(distances[currentCity][j]< shortestDistance){
            nearest = j;
            shortestDistance = distances[currentCity][j];      
        } 
    }
	return nearest;
}

#endif