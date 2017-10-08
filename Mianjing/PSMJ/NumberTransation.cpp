/*
 * NumberTransation.cpp
 *
Given a number, it will go through the following transition:
if it is odd: n * 3 + 1, otherwise n / 2.
Write a function that returns how many transitions would a number take to get to 1.
For example, given 3, it will go through the following: 3 - 10 - 5 - 16 - 8 - 4 - 2 - 1, thus the answer is 7.

Follow up: If you need to call this function many many times, how can you optimize it?
Use a cache to store number.

Follow up: Any different data structure/approach?
We can use unordered map to store integer and count.

Follow up: If the memory is limited, what would you do?
We can store 2^n for say, 1000.

 */

#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

//https://en.wikipedia.org/wiki/Collatz_conjecture
//https://careercup.appspot.com/question?id=5717938125406208

/*
 * a very basic solution
 */
int countTransition(int n)
{
	int count = 0;
	while(n > 1)
	{
		if(n%2 == 0)
		{
			n /=2;
		}
		else n = n*3 + 1;
		count++;
	}
	return count;
}


unordered_map<int, int> cache;

int countTransitionMem(int n)
{
	if(n < 1) return INT_MAX;
	int count = 0;

	while(n > 1)
	{
		// optimization: the nums that already been calculated before
		if(cache.count(n))
		{
			count += cache[n];
			break;
		}
		count++;
		if(n%2 == 0) n/=2;
		else n = n*3 + 1;
	}
	cache[n] = count;
	return count;
}

