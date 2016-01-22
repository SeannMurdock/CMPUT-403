/* UVa problem: 674
 *
 * Topic: Dynamic Programming
 *
 * Level: 1 point
 * 
 * Brief problem description: 
 *
 * Given a number determine the total number of ways to make change
 * represent that number with the following 5 coins : 50 25 10 5 1
 *
 * Solution Summary:
 *
 * The textbook suggests using dynamic programming.
 * We choose not to reset the memo table since the coin values are not changed
 * 
 * 
 *
 * Used Resources:
 *
 * Competitive Programming Volume 3
 *
 *  
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Seann Murdock
 */

#include <cstdio>
#include <cstring>
using namespace std;

int N = 5, V, coinValue[5] = {1, 5, 10, 25, 50}, memo[6][7500];

int ways(int type, int value)
{
  if (value == 0)
  {
    return 1;
  }
  if (value < 0)
  {
    return 0;
  }
  if (type == N)
  {
    return 0;
  }
  if (memo[type][value] != -1)
  {
    return memo[type][value];
  }
  memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);
  return memo[type][value];
}

int main() 
{
  memset(memo, -1, sizeof memo); //set every value in the array to -1
  while (scanf("%d", &V) != EOF) // while the last test case isn't reached (keeping the same memo table)
  {
    printf("%d\n", ways(0, V)); // print the number of ways in which change can be made
  }
  return 0;
}
