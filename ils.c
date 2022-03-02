#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <time.h>

#include "auxiliary.h"

void f();

int main(){
	int a, b, c, d;
	srand((unsigned) time(NULL));
	f();
	return 0;
}

void f() {
	srand((unsigned) time(NULL));
	printf("%f\n", get_random_interval(0, 1));
}