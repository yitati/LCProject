/******************************************************************************
 * Question: #69 Sqrt(x)
 * Given n points on a 2D plane, find the maximum number of points that lie
 * on the same straight line.
 */
/*****************************************************************************/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

struct Point{
  int x;
  int y;
  Point(): x(0), y(0){}
  Point(int a, int b):x(a), y(b){}
};

int maxPoints(vector<Point>& points)
{
	if (points.empty()) return 0;
	if (points.size() == 1) return INT_MAX;

	int n = points.size();
	unordered_map<double, int> slopes;
	int result = 0, dup = 0, vir = 0, num = 0;
	double k = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		slopes.clear();
		dup = 1;
		vir = 0;
		num = 0;
		for (int j = i + 1; j < n; j++)
		{
			double dx = (double)(points[j].x - points[i].x);
			double dy = (double)(points[j].y - points[i].y);
			if(dx == 0)
			{
				if (dy == 0) dup++;
				else 
				{
					vir++;
					num = max(num, vir);
				}
			}
			else
			{
				double k = (double)(1000 * dy / dx);
				slopes[k]++;
				num = max(num, slopes[k]);
			}
		}
		result = max(result, num + dup);
	}
	return result;
}
