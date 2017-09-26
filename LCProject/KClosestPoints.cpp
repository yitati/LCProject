/*
 * Mianjing: K ClosestPoints
 * company tag: LinkedIn, Facebook
 * Find the K closest points to the origin in a 2D plane, given an array containing N points.
 * Follow-up:
 * If we are not given the origin point, instead we are given one point with its location?
 * company tag: LinkedIn
 * Find the closest k points if we are given a vector of points
 *
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// we need to implement the < function
class Point
{
public:
	Point(int a, int b): x(a), y(b) {};
	// max heap we are implementing here
	bool operator < (const Point& point) const
	{
		return x*x + y*y < point.x*point.x + point.y*point.y;
	}
	int x;
	int y;
};


/*
 * this is very similar to problem #347 Top K Frequent Elements
 * we set a max heap of size k, then keep push points into it
 * if the heap size is larger than k we start poping out element.
 * Then we should have kept the minimal k elements.
 */
vector<Point> findKClosest(vector<Point> points, int k)
{
	priority_queue<Point> maxHeap;
	vector<Point> result;

	for(auto point : points)
	{
		maxHeap.push(point);
		if(maxHeap.size() > k) maxHeap.pop();
	}

	while(!maxHeap.empty())
	{
		result.push_back(maxHeap.top());
		maxHeap.pop();
	}

	return result;
}


//////////////////////////////////////  division ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

/*
 * If we use pair<int, int> to represent one point then we need to build the comparator and build
 * the maxHeap
 */

class PointComp{
public:
	PointComp(const pair<int, int>& ctr){
		center = ctr;
	}

	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) const{
		return getDist(lhs) < getDist(rhs);
	}

private:
	// helper function that calculate the distance from the center
	long getDist(const pair<int, int>& point) const {
		long dx = point.first-center.first;
		long dy = point.second-center.second;
		return dx*dx + dy*dy;
	}
	pair<int, int> center;
};


vector<pair<int, int>> getKClosestPoints(vector<pair<int, int>> points, pair<int, int> center, int k){
	PointComp comp(center);
	priority_queue<pair<int, int>, vector<pair<int, int>>, PointComp> maxHeap(comp);

	for(auto point : points){
		maxHeap.push(point);
		if(maxHeap.size() > k) maxHeap.pop();
	}

	vector<pair<int, int>> result;
	while(!maxHeap.empty()){
		result.push_back(maxHeap.top());
		if(maxHeap.size() > k) maxHeap.pop();
	}
}

/*
 * Use quick selection method to get k closest points
 * company tag: Facebook
 * Similar to KthLargestElementInArray
 */

/*
 * utility function that returns distance
 */
int getDistance(const pair<int,int>& point, const pair<int, int>& center)
{
	int dx = point[0]-center[0];
	int dy = point[1]-center[1];
	return dx*dx + dy*dy;
}

/*
 * [0, lhs)    <= target distance
 * (rhs, n-1]  >  target distance
 */
void selectKPoints(vector<pair<int, int>>& points, pair<int, int>& center, int start, int end, int k)
{
	if(start > end) return;
	int dist = getDistance(points[end], center);
	int lhs = start, rhs = end-1;
	while(lhs <= rhs)
	{
		if(getDistance(points[lhs], center) <= dist) lhs++;
		else if(getDistance(points[rhs], center) >= dist) rhs--;
		else
		{
			swap(points[lhs], points[rhs]);
		}
	}
	// put
	swap(points[lhs], points[end]);
	int count = lhs - start + 1;
	if(count == k) return;
	else if(count < k)
	{
		selectKPoints(points, center, lhs+1, end, k-count);
	}
	else
	{
		selectKPoints(points, center, start, lhs, k);
	}

}

vector<pair<int, int>> getKClosetPoinsts_selectionSort(vector<pair<int, int>> points, pair<int, int> center, int k)
{
	// select the quilified points and put them in the first k spots
	if(points.size() <= k) return points;
	selectKPoints(points, center, 0, points.size()-1, k);
	vector<pair<int, int>> result;
	for(int i=0; i<k; i++)
	{
		result.push_back(points[i]);
	}
	return result;
}


/*
int main(int argc, char ** argv)
{
	vector<Point> points;
	Point point0(0, 0);
	points.push_back(point0);

	Point point1(1, 1);
	points.push_back(point1);

	Point point2(2, 4);
	points.push_back(point2);

	Point point3(3, 5);
	points.push_back(point3);

	Point point4(4, 7);
	points.push_back(point4);

	Point point5(5, 10);
	points.push_back(point5);

	vector<Point> collection = findKClosest(points, 3);

	for(auto point : collection)
	{
		cout << point.x << "  " << point.y << endl;
	}
}
*/



