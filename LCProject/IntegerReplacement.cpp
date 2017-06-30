/******************************************************************************/
/*
* Question: #397 Integer Replacement
* Given a positive integer n and you can do operations as follow: 
* 1.If n is even, replace n with n/2.
* 2.If n is odd, you can replace n with either n + 1 or n - 1.
* What is the minimum number of replacements needed for n to become 1? 


Example 1: 
Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1



Example 2: 
Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1

*/
/*****************************************************************************/

#include <algorithm>
#include <climits>

using namespace std;

// for odd numbers
// if n+1 is power of 4 then do n+1
// else do n-1
// but 3 is a exception
static int c = 0;

int integerReplacement(int n)
{
	if (n == 1) return c;
	if (n == INT_MAX) return 32;
	if (n == 3) { c += 2; return c; }
	c++;
	if (n % 2 == 0) return integerReplacement(n / 2);
	else if ((n + 1) % 4 == 0) return integerReplacement(n + 1);
	else return integerReplacement(n - 1);

	return c;
}
