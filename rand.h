/*********************************************************************************************************
 *     taken from:
 *     http://www.geeksforgeeks.org/random-number-generator-in-arbitrary-probability-distribution-fashion/
 **********************************************************************************************************/
//C program to generate random numbers according to given frequency distribution
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
// Utility function to find ceiling of r in arr[l..h]
int findCeil(int arr[], int r, int l, int h)
{
    int mid;
    while (l < h)
    {
         mid = l + ((h - l) >> 1);  // Same as mid = (l+h)/2
        (r > arr[mid]) ? (l = mid + 1) : (h = mid);
    }
    return (arr[l] >= r) ? l : -1;
}
 
// The main function that returns a random number from arr[] according to
// distribution array defined by freq[]. n is size of arrays.
int myRand(int arr[], int freq[], int n)
{
    // Create and fill prefix array
    int prefix[n], i;
    prefix[0] = freq[0];
    for (i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + freq[i];
 
    // prefix[n-1] is sum of all frequencies. Generate a random number
    // with value from 1 to this sum
    int r = (rand() % prefix[n - 1]) + 1;
 
    // Find index of ceiling of r in prefix arrat
    int indexc = findCeil(prefix, r, 0, n - 1);
    /*for (int i = 0; i < n; ++i)
    {
        printf("%d ", prefix[i]);
    }*/
    return arr[indexc];
}
 
// Driver program to test above functions
/*(int main()
{
    int arr[]  = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int freq[] = {10, 5, 20, 10, 50, 100, 50, 200, 50};
    int i, n = sizeof(arr) / sizeof(arr[0]);
 
    // Use a different seed value for every run.
    srand(time(NULL));
 
    // Let us generate 10 random numbers accroding to
    // given distribution
    for (i = 0; i < 30; i++)
      printf("%d\n", myRand(arr, freq, n));
 
    return 0;
}*/