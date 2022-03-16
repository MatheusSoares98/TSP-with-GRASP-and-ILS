#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file.h"
#include "auxiliary.h"
#include "ils.h"
#include "grasp.h"

int main(int argc, char const *argv[])
{
	srand((unsigned) time(NULL));
	char fileName[250], line[250], filePath[250]="./instances/", benchmark[250]="./benchmark/";
	int numberOfIterations;
	printf("digite o numero de iteracoes desejadas\n");
	scanf("%d", &numberOfIterations);
	printf("digite o nome do arquivo a ser lido\n");
	scanf("%s", fileName);
	strcat(benchmark, fileName);
	strcat(benchmark, ".benchmark");
	strcat(filePath, fileName);
	strcat(filePath, ".tsp");
	printf("%s", filePath);
	FILE *f = fopen(filePath, "r");
	FILE *benchmarkFile = fopen(benchmark, "a");
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
	
	printf("melhor = %d\n", grasp(numberOfIterations, numberOfCities, distances, cities, path));
	//printf("melhor = %d\n", ils(numberOfIterations, numberOfCities, distances, cities, path));

	printf("%d\n", is_a_valid_path(numberOfCities, path));
	fclose(f);
	
	return 0;
}

