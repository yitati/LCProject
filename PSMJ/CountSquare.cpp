/*
 * CountSqsuare.cpp
 *
1. Decide if 4 points can make a valid square.
2. If you are given many points, how to find the number of valid squares?
 */

#include <vector>
#include <climits>
#include <set>

using namespace std;

class Point{
public:
    int x, y;
    Point(int a, int b){
        x = a;
        y = b;
    }
    bool operator <(const Point& other)
    {
    	return x < other.x || (x == other.x && y < other.y);
    }
};

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

/*
 * follow-up: find the count of valid squares in the given points
 */
// O(n) + O(n*n) time, O(n) space
int findSqures(vector<Point> &points)
{
    int n = points.size(), count = 0;
    // fill points with order
    set<Point> pset(points.begin(), points.end());

    for(int i=0; i<n; i++){
        Point p1 = points[i];
        for(int j=i+1; j<n; j++){
            Point p2 = points[j];
            Point p12(p2.x - p1.x, p2.y - p1.y); // vector p1 -> p2
            Point p21(p1.x - p2.x, p1.y - p2.y); // vector p2 -> p1
            /*
             * count only the bottom two points: a vector(x, y), and another vector
             * perpendicular to it with same length should be (-y, x)
             */
            Point p3(p1.x - p12.y, p1.y + p12.x); // up left
            Point p4(p2.x + p21.y, p2.y - p21.x); // up right
            if(pset.count(p3) && pset.count(p4)) count++;
        }
        pset.erase(p1); // must delete this point as this point has been checked, otherwise will have duplicate
    }
    return count;
}
