/******************************************************************************/
/**
* Question: #204 Count Primes
* Count the number of prime numbers less than a non-negative number, n.
*/
/*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Prime {
public:
	int countPrimes1(int n)
	{
		int count = 0;
		// x from 0 ~ n-1, if x is prime, dp[x] = 1; otherwise dp[x] = 0 
		vector<int> dp(n, 1);
		dp[0] = 0;
		dp[1] = 0;

		for (int i = 2; i < n; i++)
		{
			if (dp[i] == 1) count++;
			for (int j = 2; i*j < n; j++)
			{
				dp[i*j] = 0;
			}
		}

		return count;
	}

	// optimize by counting j = i * (i+2k)
	int countPrimes2(int n) {
		vector<bool> table(n, true);
		if (n <= 2) return 0;
		int count = n - 1;
		/* skip all even numbers */
		for (int i = 3; i*i < n; i += 2) {
			if (table[i] == false) continue;
			/* j = i * (i + 2k), odd numbers less than i*i will be covered by (i-2) * ((i-2) + 2k) */
			/* or say there exists a k where (i-2)*(i-2 + 2k) > i*i, so possible prime odd numbers will be covered */
			for (int j = i * i; j < n; j += 2*i) {
				if (table[j] == true) {
					table[j] = false;
					count--;
				}
			}
		}

		count -= (n + 1) / 2 - 1;

		return count;
	}

};

/*
int main(int argc, char * argv[]) 
{
	Prime prime;
	cout << "when it is 2" << endl << " " << prime.countPrimes1(2) << " " <<prime.countPrimes2(2) << endl;
	cout << "when it is 3" << endl << " " << prime.countPrimes1(3) << " " << prime.countPrimes2(3) << endl;
	cout << "when it is 5" << endl << " " << prime.countPrimes1(5) << " " << prime.countPrimes2(5) << endl;
	cout << "when it is 20" << endl << " " << prime.countPrimes1(20) << " " << prime.countPrimes2(20) << endl;
	cout << "when it is 10000" << endl << " " << prime.countPrimes1(10000) << " " << prime.countPrimes2(10000) << endl;

	system("pause");

}
*/

