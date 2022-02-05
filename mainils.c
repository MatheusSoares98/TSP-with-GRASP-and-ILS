#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>

#include "auxiliary.h"
#include "ils.h"



int main(){
	srand((unsigned) time(NULL));
	int pos[4] = {-3,-3, -3, -3};
	f(9, pos);
	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", pos[i]);
	}
	return 0;
}
