/******************************************************************************/
/**
* Question: #204 Count Primes
* Description:
* Count the number of prime numbers less than a non-negative number, n.
*/
/*****************************************************************************/

#include <vector>

using namespace std;

int countPrimes(int n)
{
	if (n <= 2) return 0;
	if (n == 3) return 1;
	vector<bool>table(n + 1, 0);
	int count = n - 1;
	for (int i = 3; i < n; i += 2)
	{
		for (long long j = i; i*j < n; j += 2)
		{
			if (table[i*j] == 1) continue;
			else
			{
				table[i*j] = 1;
				count--;
			}
		}
	}
	for (int i = 2; i < n; i += 2)
	{
		table[i] = 1;
		count--;
	}

	return count;
}