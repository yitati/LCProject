/******************************************************************************/
/*
* Question: #218 Skyline Problem
* A city's skyline is the outer contour of the silhouette formed by all the buildings in
* that city when viewed from a distance.
* Now suppose you are given the locations and height of all the buildings as shown on a
* cityscape photo (Figure A),
* write a program to output the skyline formed by these buildings collectively (Figure B).
* 
* The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], 
* where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, 
* and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. 
* You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

* For instance, the dimensions of all buildings in Figure A are recorded as: 
* [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

* The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] 
* that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. 
* Note that the last key point, where the rightmost building ends, is merely used to mark the termination of 
* the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be 
* considered part of the skyline contour. 

* For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

* Notes: 
* The number of buildings in any input list is guaranteed to be in the range [0, 10000].
* The input list is already sorted in ascending order by the left x position Li. 
* The output list must be sorted by the x position. 
* There must be no consecutive horizontal lines of equal height in the output skyline. 
* For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of 
* height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/
/*****************************************************************************/

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

// scan the horizontall left and right boundries, but we need to keep the highest one so far
// and make sure that when one height ends, we need to remove that from the height set
// use a set to store all "active" heights, and use stack to store the heightest one each time
vector<pair<int, int>> getSkylineProblem(vector<vector<int>>& buildings)
{
	vector<pair<int, int>> lines;
	// we need to use start point to overlap end point, so here lhs value should be negative
	for(auto& building : buildings)
	{
		lines.emplace_back(building[0], -building[2]);    // collect the left point and the height
		lines.emplace_back(building[1], building[2]);   // collect the right point and the negative height
	}
	sort(lines.begin(), lines.end());  // sort it by horizontal order
	multiset<int> height;
	vector<pair<int, int>> results;

	for(auto& it : lines)
	{
		if(it.second < 0)  // when there is a left point, need to enqueue
		{
			if(results.empty() || (-it.second) > results.back().second)  // new highest point
			{
				results.emplace_back(it.first, -it.second);
			}
			height.insert(-it.second);
		}
		else   // when there is a right point, we need to pop it out
		{
			height.erase(height.find(it.second));   // erase only one occurance
			if(height.empty()) results.emplace_back(it.first, 0);   // one corner case is 0 !!!
			else if(results.back().second > *height.rbegin())
			{
				results.emplace_back(it.first, *height.rbegin());
			}
		}
	}

	return results;
}
/*
int main(int argc, char**argv)
{
	// [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
	vector<vector<int>> buildings;
	vector<int> bd1;
	vector<int> bd2;
	vector<int> bd3;
	vector<int> bd4;
	vector<int> bd5;

	bd1.push_back(2);
	bd1.push_back(9);
	bd1.push_back(10);

	bd2.push_back(3);
	bd2.push_back(7);
	bd2.push_back(15);

	bd3.push_back(5);
	bd3.push_back(12);
	bd3.push_back(12);

	bd4.push_back(15);
	bd4.push_back(20);
	bd4.push_back(10);

	bd5.push_back(19);
	bd5.push_back(24);
	bd5.push_back(8);

	buildings.push_back(bd1);
	buildings.push_back(bd2);
	buildings.push_back(bd3);
	buildings.push_back(bd4);
	buildings.push_back(bd5);

	vector<pair<int, int>> skyline = getSkyline(buildings);


	// [ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

	for(int i=0; i<skyline.size(); i++)
	{
		cout << "["<<skyline[i].first<<" ,"<<skyline[i].second<<" ]"<< endl;
	}
}

*/

