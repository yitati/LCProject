/******************************************************************************/
/*
* Question: #275 H-Index II
* Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm? 
* Hint:
* 1.Expected runtime complexity is in O(log n) and the input is sorted.
*/
/*****************************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

int hIndexII(vector<int>& citations) 
{
	int len = citations.size();
	if (len == 0) return 0;
	int lhs = 0, rhs = len - 1, result = 0;
	while (lhs <= rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		if (citations[mid] >= (len - mid))
		{
			result = max(result, len - mid);
			rhs = mid - 1;
		}
		else
		{
			lhs = mid + 1;
		}
	}
	return result;
}
