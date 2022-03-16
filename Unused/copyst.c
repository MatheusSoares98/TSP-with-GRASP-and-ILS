#include<stdio.h>
#include<math.h>
#include "auxiliary.h"
void opt2Swap(int numberOfCities, int path[][numberOfCities], int tempPath[][numberOfCities], int start, int finish);
int main(int argc, char const *argv[])
{
	/*step path[5];
	step tempPath[5];
	path[0].distance=77;
	tempPath[0] = path[0];
	tempPath[0].distance = 99;
	printf("%d\n", tempPath[0].distance);*/

	int path[2][8] = {
        {0,22,34,55,99, 88, 100, 77},
        {22,34,55,99,88, 100, 77, 14}
    };
	int tempPath[2][8];
    opt2Swap(8, path, tempPath, 0, 2);
	return 0;
}


void opt2Swap(int numberOfCities, int path[][numberOfCities], int tempPath[][numberOfCities], int start, int finish){
	
	 int aux[2];
	 printf("copiando:\n");
	 for (int x = 0; x < numberOfCities; ++x)
	 {
	 	tempPath[0][x] = path[0][x];
	 	tempPath[1][x] = path[1][x];
	 }
	 for (int i = 0; i < numberOfCities; ++i)
	 {
	 	printf("%d, %d\n", tempPath[0][i], tempPath[1][i]);
	 }
	 printf("\n\n");
	 printf("invertendo:\n");
	 for (int x = start+1; x < finish; ++x)
	 {
	 	tempPath[0][x] = path[1][x];
	 	tempPath[1][x] = path[0][x];
	 }
	 for (int i = 0; i < numberOfCities; ++i)
	 {
	 	printf("%d, %d\n", tempPath[0][i], tempPath[1][i]);
	 }

	 printf("\n\n");
	 printf("swap:\n");
	 for (int x = start+1,  y = finish-1; x <= y; ++x, --y)
	 {
	 	aux[0] = tempPath[0][x];
	 	aux[1] = tempPath[1][x];
	 	tempPath[0][x] = tempPath[0][y];
	 	tempPath[1][x] = tempPath[1][y];
	 	tempPath[0][y] = aux[0];
	 	tempPath[1][y] = aux[1];
	 	printf("trocou %d %d\n", x, y);
	 }
	 
	 for (int i = 0; i < numberOfCities; ++i)
	 {
	 	printf("%d, %d\n", tempPath[0][i], tempPath[1][i]);
	 }
	 printf("\n\n");

	 for (int x = finish + 1; x < numberOfCities; ++x)
	 {
	 	tempPath[0][x] = path[0][x];
	 	tempPath[1][x] = path[1][x];
	 }
	 tempPath[0][start] = path[0][start];
	 tempPath[1][start] = path[0][finish];;
	 tempPath[0][finish] = path[1][start];;
	 tempPath[1][finish] = path[1][finish];;

	 for (int i = 0; i < numberOfCities; ++i)
	 {
	 	printf("%d, %d\n", tempPath[0][i], tempPath[1][i]);
	 }
	
	 
}