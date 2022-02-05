#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>
#ifndef RAND_MAX
#define RAND_MAX = 10; value
#endif
#include "auxiliary.h"

int opt2Swap(int numberOfSteps, step path[numberOfSteps], step *tempPath, int start, int finish);
int opt2(int numberOfSteps, step path[]);

int opt2(int numberOfSteps, step path[]){
	step *tempPath = malloc(sizeof(step)* numberOfSteps);
	copy_path(numberOfSteps, path, tempPath);
	bool improved = true;
	int bestDistance = calculate_total_distance(numberOfSteps, path);
	while(improved) {
		improved = false;
		for (int i = 0; i < numberOfSteps - 1; ++i)
		{
			for (int j = i + 2; j < numberOfSteps; ++j)
			{
				if(i == 0 && j == numberOfSteps-1){
					continue;
				}
				int newDistance = opt2Swap(numberOfSteps, path, tempPath, i, j);
				if(newDistance < bestDistance) {
					bestDistance = newDistance;
					improved = true;
					copy_path(numberOfSteps, tempPath, path);
					//printf("\ntotal distance = %d\n", calculate_total_distance(numberOfSteps, path));
					break;
				}
			}
			if(improved == true) {
				break;
			}
		}
	}
	free(tempPath);
	return calculate_total_distance(numberOfSteps, path);
}
int opt2Swap(int numberOfSteps, step path[numberOfSteps], step *tempPath, int start, int finish){
	
	 step aux;
	 for (int x = 0; x < numberOfSteps; ++x)
	 {
	 	tempPath[x] = path[x];
	 }
	 for (int x = start+1; x < finish; ++x)
	 {
	 	
	 	tempPath[x].start = path[x].finish;
	 	tempPath[x].finish = path[x].start;
	 }
	 
	 for (int x = start+1,  y = finish-1;  x <= y; ++x, --y)
	 {
	 	aux = tempPath[x];
	 	tempPath[x] = tempPath[y];
	 	tempPath[y] = aux;
	 }
	 for (int x = finish + 1; x < numberOfSteps; ++x)
	 {
	 	tempPath[x] = path[x];
	 }
	 tempPath[start].start = path[start].start;
	 tempPath[start].finish = path[finish].start;
	 tempPath[finish].start = path[start].finish;
	 tempPath[finish].finish = path[finish].finish;
	 for (int i = 0; i < numberOfSteps; ++i)
	 {
	 	tempPath[i].distance = calculate_distance(tempPath[i].start, tempPath[i].finish);
	 	
	 }
	 return calculate_total_distance(numberOfSteps, tempPath);
}
