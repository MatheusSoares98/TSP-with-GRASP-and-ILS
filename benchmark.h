#ifndef BENCHMARK_H 
#define BENCHMARK_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>  
#include "auxiliary.h"
#include "initial_solution.h"
#include "local_search.h"
 

int find_best_solution(int execution1, int execution2, int execution3)
{
	int bestSolution;

	if (execution1 <= execution2 && execution1 <= execution3)
	{
		bestSolution = execution1;
	}
	if (execution2 <= execution1 && execution2 <= execution3)
	{
		bestSolution = execution2;
	}
	if (execution3 <= execution1 && execution3 <= execution2)
	{
		bestSolution = execution3;
	}
	return bestSolution;
}

#endif