/* UVa problem: 10327
 *
 * Topic: Sorting
 *
 * Level: 1 point
 * 
 * Brief problem description: 
 *
 * Count the number of flips to sort the given data
 *
 * Solution Summary:
 *
 * The textbook suggests using the bubble sort algorithm and counting
 * the flips
 * 
 * Used Resources:
 *
 * Competitive Programming Volume 3
 * https://en.wikipedia.org/wiki/Bubble_sort
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Seann Murdock
 */
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

long long int flips;
int N, integers[1010];

int bubble_sort()
{
  int i, j, temp, flag = 1;
  flips = 0;
  for (i = 1; (i < N) && flag; i++)
  {
    flag = 0;
    for(j=0; j< ( N - 1); j++)
    {
      if (integers[j+1] < integers[j])
      {
        temp = integers[j];
        integers[j] = integers[j+1];
        integers[j+1] = temp;
        flag = 1;
        flips ++;
      }
    }
  }
  return flips;
}

int main() 
{
  while (scanf("%d", &N) != EOF) // while the last test case isn't reached
  {
    for(int x = 0; x < N; x++)
    {
      cin >> integers[x];
    }
    printf("Minimum exchange operations : %d\n",bubble_sort());
  }
  return 0;
}

