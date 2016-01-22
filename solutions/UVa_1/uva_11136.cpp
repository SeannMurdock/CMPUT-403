/* UVa problem: 11136
 *
 * Topic: Data Structures
 *
 * Level: 1 point
 * 
 * Brief problem description: 
 *
 * Determine the amount of money that a Walmart will pay out to cover the expense
 * of a shifty sounding promotion   
 *
 * Solution Summary:
 *
 * I used a multiset so that I could save multiple copies of the same number in
 * the set then I subtracted the first value (minimum) from the last value (max)
 * and kept track of the total for each promotion period. Then return the total.
 *
 * Used Resources:
 *
 *  Basic info on sets and multisets
 *  https://www.cs.duke.edu/courses/cps149s/fall99/resources/n10_3.html
 *
 *  More basic multiset info
 *  https://www.youtube.com/watch?v=VhwLLc42rrU
 *
 *  Information about string input streams
 * http://www.cplusplus.com/reference/sstream/istringstream/
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Seann Murdock
 */

#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace std;

int main()
{
   
	string line;
    long long int day, i, a, total, max, min;
	multiset<int>::iterator it;
	multiset<int>::reverse_iterator rit;

    cin >> day; // get the number of days in the test case
    while ( day != 0) // make sure it's not equal to 0
	{
		multiset<int> set;
		total = 0;    // initialize total to 0
		cin.ignore();  // ignore leading whitespace
        for (i = 0; i < day; ++i)  // For each day in number of days
		{

			if(getline(cin, line))  // get a new line from std in
			{
				istringstream iss(line);  // convert line to input string stream
				iss >> a;                 // get rid of the first number
				while(iss >> a)           // get all the other numbers
				{
					set.insert(a);   //add the number to the multiset
				}
			}
			rit = set.rbegin();   // reverse iterator for max value
			max = *rit;           // set max to highest in set
			set.erase(set.find(max));  // erase only one copy of max from set
			it = set.begin();  // regular iterator for min
			min = *it;    // set min to lowest in set
			set.erase(set.find(min));  // erase only one copy of min from set
			total += (max - min);  // add daily max - min to total 
		}
		cout << total << endl;  // at end of promotion period print total
		cin >> day;  // get the new number of days
		
	}	
	return 0;
}
