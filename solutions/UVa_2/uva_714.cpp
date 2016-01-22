/* UVa problem: 714
 *
 * Topic: Binary Search 
 *
 * Level: 2 point
 * 
 * Brief problem description: 
 *
 * Given m books with px pages (where p1 = number of pages in book 1) and k scribes
 * determine the most number of pages a scribe will have to copy if books are distributed 
 * in order and in their entirety.
 *
 * Solution Summary:
 *
 * The textbook suggestes combining the Binary Search algorithm with the greedy solution.
 * We can safely assume that the least amount of pages possible for a scribe would be the number of
 * pages in the thickest book. And the largest possible amount is the sum of all books. It is important to catch the overflows. 
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


#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
int TC, i, m, k, x, p[500], high = 0, mid = 0, ans = 0, karray[500];
long long int testtotal = 0, total = 0;
bool greed()
{
	//cout << "WE Have entered greed mid is : " << mid << endl;
	bool ans = true;
	int  it = (m-1), bit = 0, test[500];
	long long int acheck = 0, check;
	for(int a = k-1; a >= 0; a --)
	{
		//cout << "a equals : " <<a << endl;
		int counter = 0;
		check = 0;
		while((check + p[it]) <=mid && (counter + bit) < m && (m - (counter+ bit)) > (a))
		{
			counter +=1;
			check += p[it];
			it --;
			//cout << "this is the book iterator " << bit << endl;
		//	cout << counter << " this is the counter " << endl;
		//	cout << "this is check : " << check <<endl;
	
		}
		bit += counter;
		test[a] = counter;
		acheck+= check;
	//	cout << " acheck equals : " << acheck << endl;
	}
	//cout << acheck << endl;
	if (acheck < testtotal )
	{
		ans = false;	
	}
	else 
	
	{
		for (int d =0; d < k; d++)
		{
		//	cout << " karray values " << karray[d] << endl;
		//	cout << "TEST ARRAY " << test[d] << endl;
			karray[d] = test[d];
		}
	}
	return ans;
}

int main()
{
	
	
	
	scanf("%d", &TC);
	
	//cout << "the number of test cases is : "<< TC << endl;
	for (i = 0; i < TC; i++)
	{
		testtotal = 0;
		total = 0;
		high = 0;
		scanf("%d %d", &m, &k);
		for (x = 0; x < m; x++)
		{
			cin >> p[x];
			testtotal += p[x];
			total += p[x];
			if (p[x] > high)
			{
				high = p[x];
			}
		}
//		cout << "smallest book " << low << endl;
		//cout << "biggest book " << high << endl;
		//cout << "total pages " << total << endl;
		while (fabs(total - high) > 1)
		{
			mid = (total + high) / 2;
			if (!greed())
			{
				high = mid;
			}
			else
			{
				ans = mid; 
				total = mid;
			}
		}
		//cout << "the most amount of pages per scribe is : " << ans << endl;
		int count = 0;
		//cout << k << " this is k " << endl;
		for (int v =0; v < k; v ++)
		{
			//cout << "the number of books in given to this scribe is : "<< karray[v] << endl;
			for (int g = 0; g < karray[v]-1; g++)
			{
				cout << p[count] << " ";
				count++;
				//cout << count << endl;
			}
			if (v == (k-1))
			{
				cout << p[count] << endl;;
			}
			else
			{
				cout << p[count] << " / ";
				count++;
			}			
		}
		//if (i < TC -1)
		//{
		//cout << endl;
		//}
	}
	return 0;
}
