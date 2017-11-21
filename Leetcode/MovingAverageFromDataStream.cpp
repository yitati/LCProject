/******************************************************************************/
/*
* Question: #346 Moving Average from Data Stream
* Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/
/*****************************************************************************/

#include <queue>

using namespace std;

class MovingAverage 
{
public:
	/** Initialize your data structure here. */
	MovingAverage(int size) 
	{
		capacity = size;
		currSum = 0;
	}

	double next(int val) 
	{
		if (table.size() == capacity)
		{
			table.pop();
		}
		table.push(val);
		currSum += val;
		return double(currSum / table.size());
	}

private:
	queue<int> table;
	int currSum;
	int capacity;
};