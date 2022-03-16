#ifndef LOCAL_SEARCH_H  
#define LOCAL_SEARCH_H 
#ifndef RAND_MAX
#define RAND_MAX = 10; value
#endif
#include <stdbool.h>
#include "auxiliary.h"

bool is_shorter(int numberOfCities, step path[], int start, int finish); 
int opt2Swap(int numberOfCities, step path[numberOfCities], step *tempPath, int start, int finish);

int opt2(int numberOfCities, step path[]){
	step *tempPath = malloc(sizeof(step)* numberOfCities);
	copy_path(numberOfCities, path, tempPath);
	bool improved = true;
	while(improved) {
		improved = false;
		for (int i = 0; i < numberOfCities - 1; ++i)
		{
			for (int j = i + 2; j < numberOfCities; ++j)
			{
				if(i == 0 && j == numberOfCities-1){
					continue;
				}
				if(is_shorter(numberOfCities, path, i, j)) {
					opt2Swap(numberOfCities, path, tempPath, i, j);
					improved = true;
					copy_path(numberOfCities, tempPath, path);
					//printf("\ntotal distance = %d\n", calculate_total_distance(numberOfCities, path));
					break;
				}
			}
			if(improved == true) {
				break;
			}
		}
	}
	free(tempPath);
	return calculate_total_distance(numberOfCities, path);
}
int opt2Swap(int numberOfCities, step path[numberOfCities], step *tempPath, int start, int finish){
	
	 step aux;
	 for (int x = 0; x < numberOfCities; ++x)
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
	 
	 tempPath[start].start = path[start].start;
	 tempPath[start].finish = path[finish].start;
	 tempPath[finish].start = path[start].finish;
	 tempPath[finish].finish = path[finish].finish;
	 for (int i = 0; i < numberOfCities; ++i)
	 {
	 	tempPath[i].distance = calculate_distance(tempPath[i].start, tempPath[i].finish);
	 	
	 }
	 return calculate_total_distance(numberOfCities, tempPath);
}

bool is_shorter(int numberOfCities, step path[], int start, int finish) {
	int a = path[start].distance + path[finish].distance;
	int b = calculate_distance(path[start].start, path[finish].start) + calculate_distance(path[start].finish, path[finish].finish);

	return a > b;
}

#endif