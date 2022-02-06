#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>  
#include "file.h"
#include "auxiliary.h"
#include "initial_solution.h"
#include "local_search.h"
#include "ils.h"
int grasp(int numberOfIterations, int numberOfCities, int distances[][numberOfCities], city cities[], step path[]);
int main(int argc, char const *argv[])
{
	srand((unsigned) time(NULL));
	char fileName[250], line[250];
	int numberOfIterations;
	printf("digite o numero de iteracoes desejadas\n");
	scanf("%d", &numberOfIterations);
	printf("digite o nome do arquivo a ser lido\n");
	scanf("%s", fileName);
	FILE *f = fopen(fileName, "r");
	if(f == NULL)
   	{
      printf("Arquivo nao encontrado");   
      exit(1);             
   	}
   	int numberOfCities;
   	for (int i = 0; i < 3; ++i)
	{
		fgets(line, 250, f);
	}
	fscanf(f,"%s %d\n", line, &numberOfCities);
	
	
	city cities[numberOfCities];
	step path[numberOfCities];
	int distances[numberOfCities][numberOfCities];

	read_file_and_fill_Cities(cities, f, numberOfCities);
	create_distance_matrix(numberOfCities, cities, distances);
	
	//print_distance_matrix(numberOfCities, distances);
	/*initialize_cities_as_not_visited(numberOfCities, cities);
	for (int i = 0; i < numberOfCities-1; ++i)
	{
		path[i].start = cities[i];
		path[i].finish = cities[i+1];
		path[i].distance = distances[i][i+1];
	}
	path[9].start = cities[9];
	path[9].finish = cities[0];
	path[9].distance = distances[0][9];
	print_path(numberOfCities, path);
	//opt2(numberOfCities, path);
	print_path(numberOfCities, path);
	nearestNeighbor(numberOfCities, cities, distances, path);*/
	
	printf("melhor = %d\n", grasp(numberOfIterations, numberOfCities, distances, cities, path));
	print_path(numberOfCities, path);
	successors(numberOfCities, path);
	print_path(numberOfCities, path);
	printf("%d\n", is_a_valid_path(numberOfCities, path));
	//printf("\n");
	
	fclose(f);
	
	return 0;
}

int grasp(int numberOfIterations, int numberOfCities, int distances[][numberOfCities], city cities[], step path[]) {
	clock_t start_t, end_t, total_t;
	start_t = clock();
	step tempPath[numberOfCities];
	copy_path(numberOfCities, path, tempPath);
	double minimumResult = INFINITY;
	int currentResult;
	for (int i = 0; i < numberOfIterations; ++i)
	{
		initialize_cities_as_not_visited(numberOfCities, cities);
		nearestNeighbor(numberOfCities, cities, distances, tempPath);
		currentResult = opt2(numberOfCities, tempPath);
		if (currentResult < minimumResult)
		{
			minimumResult = currentResult;
			copy_path(numberOfCities, tempPath, path);
		}
		//printf("%lf\n", minimumResult);

	}
	end_t = clock();
	total_t = (long int)(end_t - start_t);
   	printf("Total time taken by CPU: %f\n", (float)total_t / CLOCKS_PER_SEC);
	return (int)minimumResult;
}
