/******************************************************************************
 * Question: #69 Sqrt(x)
 * company tag: LinkedIn
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
    if(points.empty() || points.size() == 1) return points.size();

    unordered_map<double, int> slope;  // for slope of one line we need to use double

    int vir = 0, dup = 0, num = 0, result = 0;
    double k = 0;

    for(int i=0; i<points.size(); i++)
    {
        // we start with a new point
        vir = 0;
        dup = 1;
        num = 0;
        slope.clear();

        for(int j=i+1; j<points.size(); j++)
        {
            double dx = double(points[j].x - points[i].x);
            double dy = double(points[j].y - points[i].y);

            if(dx == 0 && dy == 0) dup++; //we found one more duplicates
            else if(dx == 0)
            {
                vir++;
                num = max(num, vir);
            }
            else {
                double k = 1000*dy/dx;
                slope[k]++;
                num = max(num, slope[k]);
            }
        }
        result = max(result, num+dup);
    }
    return result;
}
