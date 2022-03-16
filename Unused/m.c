#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>  
#include "file.h"
#include "auxiliary.h"
#include "initial_solution.h"
#include "local_search.h"
void print_array(int size, int array[size]);
void print_char_array(int size, char array[size]);

int main(int argc, char const *argv[])
{
	int sucessores[]={6, 2, 8, 4, 5, 1, 7, 3, 0};
	int sucessoresCopy[]={6, 2, 8, 4, 5, 1, 7, 3, 0};	
	char nodes[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
	char copy[9]={'.'};
	int aux = 0;

	copy[0] = nodes[0];
	print_array(9, sucessores);
	print_char_array(9, copy);
	for (int i = 1; i < 9; ++i)
	{
		copy[i] = nodes[sucessoresCopy[i-1]];
		printf("\n\n\n%d        %d %d\n", i, sucessores[sucessoresCopy[i-1]], sucessoresCopy[i]);
		print_array(9, sucessoresCopy);
		sucessoresCopy[i] = sucessores[sucessoresCopy[i-1]];
		

		print_char_array(9, copy);
		//printf(">>>>>>>>>>>>>>>>%d\n", i);
	}

	return 0;
}

void print_array(int size, int array[size]) {
	for (int i = 0; i < size-1; ++i)
	{
		printf("%d  ", array[i]);
	}
	printf("%d\n", array[size-1]);
}

void print_char_array(int size, char array[size]) {
	for (int i = 0; i < size-1; ++i)
	{
		printf("%c  ", array[i]);
	}
	printf("%c\n", array[size-1]);
}
