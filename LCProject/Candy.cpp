/******************************************************************************/
/*
* Question: #135 Candy
* There are N children standing in a line. Each child is assigned a rating value. 

* You are giving candies to these children subjected to the following requirements: 
* Each child must have at least one candy.
* Children with a higher rating get more candies than their neighbors.

* What is the minimum candies you must give? 
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

int candy(vector<int>& ratings) 
{
	int sum = 0, n = ratings.size();
	vector<int> candy(n, 1);
	// first loop
	for (int i = 1; i < n; i++)
	{
		if (ratings[i] > ratings[i - 1]) candy[i] = candy[i - 1] + 1;
		else candy[i] = candy[i - 1] - 1;
	}
	// second loop - fix the forward peaks
	for (int i = 0; i < n; i++)
	{
		if (candy[i] < 1) candy[i] = 1;
		if (i > 0 && candy[i] > candy[i - 1]) candy[i] = candy[i - 1] + 1;
	}
	// third loop - fix the backward peaks
	sum = candy[n - 1];
	for (int i = n - 2; i >= 0; i++)
	{
		if (candy[i] > candy[i + 1]) candy[i] = max(candy[i], candy[i + 1] + 1);
		sum += candy[i];
	}
	
	return sum;
}