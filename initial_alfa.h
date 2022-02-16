#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>
#include "auxiliary.h"
#include "rand.h"

void nearestNeighbor(int numberOfSteps, city cities[], int distances[][numberOfSteps], step path[]);
int find_nearest(int numberOfSteps, int currentCity, int distances[][numberOfSteps], city cities[]);


void nearestNeighbor(int numberOfSteps, city cities[], int distances[][numberOfSteps], step path[]){
    int nearest = 0;
    int currentStop = 0;
    int i;
    int pos = get_random_interval(0, numberOfSteps-0.01);
    int currentCity = pos, currentCityCopy;
    cities[pos].visited = true;
    //printf("%d\n", pos);
    int firstcity = currentCity;

    double alfa = get_random_interval(0, 1);
    int AlfaValues[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int probabilities[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int means[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int candidato = myRand(AlfaValues, probabilities, 10);
    printf("candidato == %d\n", candidato);

    printf("alfa = %lf  pos = %d\n", alfa, pos);
    
    	for (i = 0; i < numberOfSteps && (count_unvisited_cities(numberOfSteps, cities) > 0); ++i)
    	{
    		
    		city citiesCopy[numberOfSteps];
    		copy_cities(numberOfSteps, cities, citiesCopy);
    		int size = (int)get_random_interval(1, count_unvisited_cities(numberOfSteps, citiesCopy) + 0.99);
            //printf("size = %d\n", size);
            if (size * alfa >=1 )
            {
                size *= alfa;
            }

    		int LCR[size];
    		for (int i = 0; i < size; ++i)
    		{
    			nearest = find_nearest(numberOfSteps, currentCity, distances, citiesCopy);
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
 
    path[numberOfSteps-1].start = path[numberOfSteps-2].finish;
    path[numberOfSteps-1].finish = cities[firstcity];
	path[numberOfSteps-1].distance = calculate_distance(path[numberOfSteps-1].start, path[numberOfSteps-1].finish);
    
    //&& (count_unvisited_cities(numberOfSteps, cities) > 0)	  	
}

int find_nearest(int numberOfSteps, int currentCity, int distances[][numberOfSteps], city cities[]) {
	double shortestDistance = INFINITY;
	
	int nearest = 0;
	for(int j = 0; j < numberOfSteps; j++){    
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