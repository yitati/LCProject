/*
 * Laicode_KClosestPointsTo000.cpp
 *

Given three arrays sorted in ascending order. Pull one number from each array to
form a coordinate <x,y,z> in a 3D space.
Find the coordinates of the points that is k-th closest to <0,0,0>.

We are using euclidean distance here.

Assumptions

The three given arrays are not null or empty
K >= 1 and K <= a.length * b.length * c.length
Return

a size 3 integer list, the first element should be from the first array, the second
element should be from the second array and the third should be from the third array
Examples

A = {1, 3, 5}, B = {2, 4}, C = {3, 6}

The closest is <1, 2, 3>, distance is sqrt(1 + 4 + 9)

The 2nd closest is <3, 2, 3>, distance is sqrt(9 + 4 + 9)

 */
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;


/*
 * since the array is sorted in ascending order, so we can just proceed the last one
 * that we calculated
 */

int getHash(vector<int>& input, int sizeb, int sizec)
{
	return input[0]*sizeb*sizec + input[1]*sizec + input[2];
}

vector<int> closest(vector<int> a, vector<int> b, vector<int> c, int k)
{
	int sizea = a.size(), sizeb = b.size(), sizec = c.size();
	vector<int> sizes = {sizea, sizeb, sizec};
	// write a comparator for the min heap, return lhs > rhs
	auto comp = [&](const vector<int>& lhs, const vector<int>& rhs) -> bool {
		int dist1 = a[lhs[0]] * a[lhs[0]] + b[lhs[1]] * b[lhs[1]] + c[lhs[2]] * c[lhs[2]];
		int dist2 = a[rhs[0]] * a[rhs[0]] + b[rhs[1]] * b[rhs[1]] + c[rhs[2]] * c[rhs[2]];
		return dist1 > dist2;
	};

	priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);

	minHeap.push({0, 0, 0});

	unordered_set<long long> visited;

	visited.insert(0);

	while(k > 1)
	{
		auto curr = minHeap.top();
		minHeap.pop();
		int rep = 0;
		for(int i=0; i<3; i++)
		{
			if(curr[i] + 1 < sizes[i])
			{
				curr[i]++;
				rep = getHash(curr, sizeb, sizec);
				if(!visited.count(rep))
				{
					minHeap.push(curr);
					visited.insert(rep);
				}
				curr[i]--;
			}
		}
		k--;
	}

	vector<int> result = minHeap.top();
	result[0] = a[result[0]];
	result[1] = b[result[1]];
	result[2] = c[result[2]];
	return result;
}

/*
int main(int argc, char ** argv)
{
	vector<int> a = {1, 3};
	vector<int> b = {2, 3};
	vector<int> c = {2, 4};

	vector<int> result = closest(a, b, c, 8);

	cout << result[0] << "  "<< result[1] << "  "<< result[2] << endl;;
}
*/





