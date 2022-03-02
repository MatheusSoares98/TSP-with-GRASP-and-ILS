#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define SIZE 52
void bubble_sort(int pos[SIZE]);
int calculate_path_distance(int numberOfCities, int citiesArray[2][numberOfCities]); 

int main(int argc, char const *argv[])
{
	FILE *cidades = fopen("cidade", "r");
	char buffer[250];
	FILE *caminho = fopen("caminho", "r");
	FILE *order = fopen("eil101optroute", "r");
	if(caminho == NULL || order == NULL)
   	{
      printf("Arquivo nao encontrado");   
      exit(1);             
   	}
	int arrayCaminho[2][SIZE], citiesArray[2][SIZE], citiesArrayCopy[2][SIZE];
	int line; 
	int path[SIZE], citiesOrder[SIZE];
	
	
	for (int i = 0; i < SIZE; ++i)
	{
		fscanf(caminho, "%d %d", &arrayCaminho[0][i], &arrayCaminho[1][i]);
		fgets(buffer, 250, caminho);
	}
	for (int i = 0; i < SIZE; ++i)
	{
		fscanf(cidades, "%d %d %d\n", &line, &citiesArray[0][i], &citiesArray[1][i]);
	}
	/*for (int i = 0; i < SIZE; ++i)
	{
		//printf("%d %d ", citiesArray[0][i], citiesArray[1][i]);
		for (int j = 0; j < SIZE; ++j)
		{
			if (arrayCaminho[0][j] == citiesArray[0][i] && arrayCaminho[1][j] == citiesArray[1][i])
			{
				//printf("%d\n", j);
				path[i] = j;
				break;
			}
		}
	}*/
	for (int i = 0,  m; i < SIZE; ++i)
	{
		fscanf(order, "%d\n", &m);
		path[i] = m-1;
		printf("%d\n", path[i]);
	}
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (path[j] == i)
			{
				citiesOrder[i] = j;
				break;
			}
		}
	}
	
	/*
	for (int i = 0; i < SIZE; ++i)
	{
		citiesArrayCopy[0][i] = citiesArray[0][citiesOrder[i]];
		citiesArrayCopy[1][i] = citiesArray[1][citiesOrder[i]];
	}
	*/
	for (int i = 0; i < SIZE; ++i)
	{
		citiesArrayCopy[0][i] = citiesArray[0][path[i]];
		citiesArrayCopy[1][i] = citiesArray[1][path[i]];
	}

	printf("%d\n", calculate_path_distance(SIZE, citiesArrayCopy));
	free(caminho);
	return 0;
}


void bubble_sort(int pos[SIZE]) {
	int  n = SIZE, i, j, swap;
	bool flag = false;
	
	for(i = 0 ; i < n - 1; i++) {
		flag = false;
		for(j = 0 ; j < n-i-1; j++) {
			if(pos[j] > pos[j+1]) {
				swap = pos[j];
				pos[j] = pos[j+1];
				pos[j+1] = swap;
				flag = true;
			}
		}
		if(!flag) {
			break;
		}
	}
}

int calculate_path_distance(int numberOfCities, int citiesArray[2][numberOfCities]) {
	int pathTotalDistance = 0, i, aux;
	for (i = 0; i < numberOfCities-1; ++i)
	{
		aux = sqrt( (citiesArray[0][i+1] - citiesArray[0][i])*(citiesArray[0][i+1] - citiesArray[0][i]) + (citiesArray[1][i+1] - citiesArray[1][i])*(citiesArray[1][i+1] - citiesArray[1][i]) );
		pathTotalDistance += aux;
		//printf("%d\n", aux);
	}
	
	pathTotalDistance += sqrt( (citiesArray[0][0] - citiesArray[0][i])*(citiesArray[0][0] - citiesArray[0][i]) + (citiesArray[1][0] - citiesArray[1][i])*(citiesArray[1][0] - citiesArray[1][i]));
	return pathTotalDistance;
}
