/*
You have 4 types of lego blocks, of sizes given as (1 x 1 x 1), (1 x 1 x 2), (1 x 1 x 3), and (1 x 1 x 4). 
Assume that you have an infinite number of blocks of each type.

Using these blocks, you want to make a wall of height N and width M. The wall should not have any holes in it. 
The wall you build should be one solid structure. A solid structure can be interpreted in one of the following ways:
(1)It should not be possible to separate the wall along any vertical line without cutting any lego block used to build the wall.
(2)You cannot make a vertical cut from top to bottom without cutting one or more lego blocks.

The blocks can only be placed horizontally. In how many ways can the wall be built?

Input Format

The first line contains the number of test cases T. T test cases follow. Each case contains two integers N and M.

Constraints

1 <= T <= 100
1 <= N,M <= 1000

Output Format

Output T lines, one for each test case containing the number of ways to build the wall. 
As the numbers can be very large, output the result modulo 1000000007.
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define MOD 1000000007

unsigned long long power(unsigned long long num, int p) {

	if (p == 0) return 1;
	if (p == 1) return num;

	unsigned long long number = num;
	for (int i = 2; i <= p; i++) {
		num *= number;
		num %= MOD;
	}
	return num;
}

/*
int main(void) 
{

	int N = 100;
	int M = 100;
	int Tt = 1;

	vector<long long> T(1001);
	vector<long long> S(1001);
	vector<long long> P(1001);

	T[0] = T[1] = 1;
	T[2] = 2;
	T[3] = 4;
	T[4] = 8;

	P[0] = P[1] = 1;

	for (int i = 5; i <= 1000; i++)
		T[i] = (T[i - 1] + T[i - 2] + T[i - 3] + T[i - 4]) % MOD;

	S[0] = 1;
	S[1] = 1;

	long long sum;


	for (int t = 0; t<Tt; t++) {

		for (int i = 0; i <= M; i++)
			P[i] = (long long)power(T[i], N);

		for (int i = 2; i <= M; i++) {
			sum = 0;
			for (int j = 1; j<i; j++) {
				sum += (S[j] * P[i - j]) % MOD;
				sum %= MOD;
			}
			S[i] = (P[i] - sum);
			S[i] = S[i] % MOD;
		}
		while (S[M] < 0)
			S[M] += MOD;
		cout << S[M] << endl;
	}

	system("pause");
}
*/