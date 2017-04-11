/*
Get the Kth number in the Fibonacci Sequences. (k is 0-indexed, the 0th Fibonacci and 
the 1st Fibonacci number is 1).
Example:
- 0th Fibonacci number is 0
- 1st Fibonacci number is 1
- 2nd Fibonacci number is 1
- 3rd Finonacci number is 2
- 6th Fibonacci number is 8

Corner Cases:
- What if K<0? In this case, we should always return 0.
- Is it possible the result fibonacci number is overflowed? How to use BigInteger?
*/

#include <iostream>
#include <vector>

using namespace std;

// using dp
long fibonacci_dp(int K)
{
	if (K < 0) return 0;
	if (K < 2) return (long)K;
	int i;
	vector<long> result(K+1, 0);
	result[0] = 0;
	result[1] = 1;
	for (i = 2; i < K+1; i++)
	{
		result[i] = result[i - 1] + result[i - 2];
	}
	return result[K];
}

// using recursion
long fibonacci_recursion(int K)
{
	if (K < 0) return 0;
	if (K < 2) return (long)K;
	return fibonacci_recursion(K - 1) + fibonacci_recursion(K - 2);
}


// using iteration
long fibonacci_iteration(int K)
{
	if (K < 0) return 0;
	if (K < 2) return (long)K;
	int fn_2 = 0, fn_1 = 1;
	int fn;
	while (K >= 2)
	{
	    fn = fn_2 + fn_1;
		fn_2 = fn_1;
		fn_1 = fn;
		K--;
	}
	return fn;
}

/*
int main(int argc, char ** argv)
{
	cout << "0 th Fibonacci number is " << fibonacci_iteration(0) << endl;
	cout << "1 th Fibonacci number is " << fibonacci_iteration(1) << endl;
	cout << "2 th Fibonacci number is " << fibonacci_iteration(2) << endl;
	cout << "3 th Fibonacci number is " << fibonacci_iteration(3) << endl;
	cout << "6 th Fibonacci number is " << fibonacci_iteration(6) << endl;
	system("pause");
}
*/