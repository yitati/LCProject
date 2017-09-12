/******************************************************************************
 * Question #593 Valid Square
 * company tag: PureStorage
 * Given the coordinates of four points in 2D space, return whether the four points could construct a square.
 * The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

 * All the input integers are in the range [-10000, 10000].
 * A valid square has four equal sides with positive length and four equal angles (90-degree angles).
 * Input points have no order.
 *
 * Follow-up:
 * company tag: PureStorage
 * What if you are given a lot of points and count how many valid squares inside.
 ************************************************************************************/

#include <vector>
#include <climits>

using namespace std;

/*
 * calculate the length between every two dots, there should be 2 lengths
 * Number of shorter length : 4
 * Number of longer length : 2
 */

long long distance(const vector<int>& p1, const vector<int>& p2)
{
	long long dx = p1[0]-p2[0];
	long long dy = p1[1]-p2[1];
	return dx*dx + dy*dy;
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
{
	int minLen = INT_MAX, maxLen = INT_MIN;
	int counts = 0, countl = 0;
	// push all possible length
	vector<vector<int>> points = {p1, p2, p3, p4};
	vector<long long> length;
	for(int i=0; i<4; i++)
	{
		for(int j=i+1; j<4; j++)
		{
			int len = distance(points[i], points[j]);
			length.push_back(len);
			maxLen = max(maxLen, len);
			minLen = min(minLen, len);
		}
	}

	for(auto len : length)
	{
		if(len == minLen) counts++;
		else countl++;
	}
	if(counts==4 && countl == 2) return true;
	return false;
}


