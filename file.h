#ifndef FILE_H   
#define FILE_H
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "auxiliary.h"

void writeFile() {
	char fileName[50];
	int size, xCoordinate, yCoordinate;
	printf("digite o nome do arquivo a ser criado\n");
	scanf("%s", fileName);
	printf("digite a quantidade de cidades\n");
	scanf("%d", &size);
	
	FILE *f = fopen(fileName, "w");

	fprintf(f, "%d\n", size);
	for (int i = 0; i < size; ++i)
	{
		xCoordinate = (int)get_random_interval(1, 1000);
		yCoordinate = (int)get_random_interval(1, 1000);
		fprintf(f, "%d %d\n", xCoordinate, yCoordinate);
		//printf("%d %d\n", xCoordinate, yCoordinate);
	}
	fclose(f);
}

void readFile() {
	char fileName[50];
	printf("digite o nome do arquivo a ser lido\n");
	city a;
	scanf("%s", fileName);
	FILE *f = fopen(fileName, "r");
	int n;
	fscanf(f, "%d\n", &n);
	int cities[n][2];
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
	{
		fscanf(f,"%d %d\n", &cities[i][0], &cities[i][1]);
		printf("%d %d\n", cities[i][0], cities[i][1]*2);
	}
	fclose(f);
}

void deprecated_read_file_and_fill_Cities(int numberOfCities, city cities[], FILE *f) {
	for (int i = 0; i < numberOfCities; ++i)
	{
		fscanf(f,"%d %d\n", &cities[i].xCoordinate, &cities[i].yCoordinate);
	}
}

void read_file_and_fill_Cities(city cities[], FILE *f, int numberOfCities) {
	char line[250];
	int cityNumber;
	
	printf("%d\n", numberOfCities);
	fgets(line, 250, f);
	fgets(line, 250, f);
	for (int i = 0; i < numberOfCities; ++i)
	{
		fscanf(f,"%d %d %d\n", &cityNumber, &cities[i].xCoordinate, &cities[i].yCoordinate);
	}
}
#endif