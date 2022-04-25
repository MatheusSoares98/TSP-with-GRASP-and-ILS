/*#ifndef ITERATIONS_WITHOUT_IMPROVEMENT
#define ITERATIONS_WITHOUT_IMPROVEMENT 100
#endif*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h> 
#include "file.h"
#include "auxiliary.h"
#include "benchmark.h"
#include "ils.h"
#include "grasp.h"

int main(int argc, char const *argv[])
{
	srand((unsigned) time(NULL));
	char fileName[250], line[250], filePath[250]="./instances/", benchmark[250]="./benchmark/";
	int iterationsWithoutImprovement = 100;
	int execution1, execution2, execution3, bestSolution;
	clock_t execution1Time, execution2Time, execution3Time, averageTime;
	float averageSolution;
	//printf("digite o numero de iteracoes desejadas\n");
	//scanf("%d", &iterationsWithoutImprovement);
	printf("digite o nome do arquivo a ser lido\n");
	scanf("%s", fileName);
	strcat(benchmark, fileName);
	strcat(benchmark, ".benchmark");
	strcat(filePath, fileName);
	strcat(filePath, ".tsp");
	printf("%s", filePath);
	FILE *f = fopen(filePath, "r");
	FILE *benchmarkFile = fopen(benchmark, "w");
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
	
	float alpha = (numberOfCities < 100) ? 0.1 : 0.3;
	execution1 = grasp(iterationsWithoutImprovement, numberOfCities, distances, cities, path, benchmarkFile, alpha, &execution1Time);
	execution2 = grasp(iterationsWithoutImprovement, numberOfCities, distances, cities, path, benchmarkFile, alpha, &execution2Time);
	execution3 = grasp(iterationsWithoutImprovement, numberOfCities, distances, cities, path, benchmarkFile, alpha, &execution3Time);
	averageTime = (execution1Time + execution2Time + execution3Time) / 3;
	averageSolution = (execution1 + execution2 + execution3) / 3;
	bestSolution = find_best_solution(execution1, execution2, execution3);

	fprintf(benchmarkFile, "GRASP:\n");
	fprintf(benchmarkFile, "Average solution: %f\n", averageSolution);
	fprintf(benchmarkFile, "Best solution: %d\n", bestSolution);
	fprintf(benchmarkFile, "Average time: %f\n\n\n",(float)averageTime/ CLOCKS_PER_SEC);

	fprintf(benchmarkFile, "ILS:\n");
	execution1 = ils(iterationsWithoutImprovement, numberOfCities, distances, cities, path, benchmarkFile, alpha, &execution1Time);
	execution2 = ils(iterationsWithoutImprovement, numberOfCities, distances, cities, path, benchmarkFile, alpha, &execution2Time);
	execution3 = ils(iterationsWithoutImprovement, numberOfCities, distances, cities, path, benchmarkFile, alpha, &execution3Time);
	averageTime = (execution1Time + execution2Time + execution3Time) / 3;
	averageSolution = (execution1 + execution2 + execution3) / 3;
	bestSolution = find_best_solution(execution1, execution2, execution3);

	fprintf(benchmarkFile, "Average solution: %f\n", averageSolution);
	fprintf(benchmarkFile, "Best solution: %d\n", bestSolution);
	fprintf(benchmarkFile, "Average time: %f\n\n\n",(float)averageTime/ CLOCKS_PER_SEC);
	
	
	
	fclose(f);
	
	return 0;
}

