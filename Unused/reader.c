#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	FILE *filepointer = fopen("./instances/a280.tsp", "r");
	
	char line[250];
	char start;
	int numberOfCities, x, y, cityNumber;
	for (int i = 0; i < 3; ++i)
	{
		fgets(line, 250, filepointer);
	}
	fscanf(filepointer,"%s %d\n", line, &numberOfCities);
	printf("%d\n", numberOfCities);
	fgets(line, 250, filepointer);
	fgets(line, 250, filepointer);
	for (int i = 0; i < numberOfCities; ++i)
	{
		fscanf(filepointer,"%d %d %d\n", &cityNumber, &x, &y);
		printf("%d %d %d\n", cityNumber, x, y);
		
	}
	
	return 0;
}
