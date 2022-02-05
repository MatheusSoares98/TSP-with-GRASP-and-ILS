#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	
   clock_t start_t, end_t, total_t;
   int i;

   start_t = clock(); //clock start
   printf("Starting of the program, start_t = %ld\n", start_t);

   printf("Going to scan a big loop, start_t = %ld\n", start_t);
   for(i=0; i < 0X7FFFFFF; i++)  //trying to determine execution time of this block
   {
   }
   end_t = clock(); //clock stopped
   printf("End of the big loop, end_t = %ld\n", end_t);

   total_t = (long int)(end_t - start_t);
   printf("Total time taken by CPU: %lu\n", total_t  );

   return(0);
}