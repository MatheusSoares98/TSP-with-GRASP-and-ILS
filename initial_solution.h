#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>
#include "auxiliary.h"


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
    printf("alfa = %lf\n pos = %d", alfa, pos);
    

    	for (i = 0; i < numberOfSteps && (count_unvisited_cities(numberOfSteps, cities) > 0); ++i)
    	{
    		
    		city citiesCopy[numberOfSteps];
    		copy_cities(numberOfSteps, cities, citiesCopy);
    		int size = (int)get_random_interval(1, count_unvisited_cities(numberOfSteps, citiesCopy) + 0.99);
            
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
    		
    		pos = get_random_interval(0, size-0.01);

    		nearest = LCR[pos];
    		//printf("nearest = %d , pos = %d , size = %d\n", nearest, pos, size);
    		cities[nearest].visited = true;
    		
    		path[currentStop].start = cities[currentCity];
	    	path[currentStop].finish = cities[nearest];

	    	path[currentStop].distance = calculate_distance(path[currentStop].start, path[currentStop].finish);
	    	currentCity = nearest;
	    	currentStop++;
            //print_path(numberOfSteps, path);
         
	    	/*
	    	printf("\nsize= %d ", size);
	    	
    		for (int i = 0; i < size; ++i)
    		{
    			printf("[%d]  ", LCR[i]);
    		}
    		for (int i = 0; i < numberOfSteps; ++i)
    		{
    			printf("[%d] ", cities[i].visited);
    		}
            printf("\n");*/
    	}
        printf("saiu do for\n");
    
    printf("saiu do while %d %d\n", numberOfSteps, firstcity);

    path[numberOfSteps-1].start = path[numberOfSteps-2].finish;
    path[numberOfSteps-1].finish = cities[firstcity];
	path[numberOfSteps-1].distance = calculate_distance(path[numberOfSteps-1].start, path[numberOfSteps-1].finish);
    //&& (count_unvisited_cities(numberOfSteps, cities) > 0)	  	
    //print_path(numberOfSteps, path);
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
    //printf("%d %d %d\n", currentCity, nearest, shortestDistance);
	return nearest;
}