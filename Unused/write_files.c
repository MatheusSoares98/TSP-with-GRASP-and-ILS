#include "file.h"
#include <time.h>
#include "auxiliary.h"

int main(int argc, char const *argv[])
{
	srand((unsigned) time(NULL));
	writeFile();
	
	return 0;
}