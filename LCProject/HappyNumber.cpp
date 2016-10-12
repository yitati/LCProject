/******************************************************************************/
/**
* Question: #202 Happy Number
* Write an algorithm to determine if a number is "happy".
* A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the
* sum of the squares of its digits, and repeat the process until the nuber equals 1 (where it will stay), or it loops endlessly 
* in a cycle which does not include 1. Those numbers of which this process ends in 1 are happy numbers.
* Examples: 19 is a happy number
* 12 + 92 = 82
* 82 + 22 = 68
* 62 + 82 = 100
* 12 + 02 + 02 = 1
*/
/*****************************************************************************/

#include <iostream>
#include <unordered_set>

using namespace std;

// dfs problem
class HappyNumber
{
public:
	bool isHappy1(int n)
	{
		unordered_set<int> visited;
		int d = n;
		visited.insert(d);
		while (1)
		{
			d = squareSum(d);
			if (d == 1) return true;
			// if number is already exist in visited
			if (visited.find(d) != visited.end()) {
				return false;
			}
			visited.insert(d);
		}
	}

	bool isHappy2(int n)
	{
		if (n == 0) return false;
		if (n == 1) return true;
		if (n == 4) return false;
		int sum = 0;
		while (n>0)
		{
			sum += (n % 10)*(n % 10);
			n = n / 10;
		}
		return isHappy2(sum);
	}

	// helper function to calculate the sum of the sqare of each digit
	int squareSum(int n)
	{
		int sum = 0;
		while (n > 0)
		{
			int d = n % 10;
			sum += d*d;
			n /= 10;
		}
		return sum;
	}
};

/*
int main(int argc, char * argv[])
{
	HappyNumber happy;
	cout << happy.isHappy1(50) << endl;
	cout << happy.isHappy1(19) << endl;
	system("pause");
}
*/
