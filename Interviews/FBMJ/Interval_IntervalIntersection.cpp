#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <cassert>

using namespace std;


/*
Intersection of two sorted interval lists, A=[(1,2), (5,7)..] B=[(2,6)...]  return [(5,6)..]
*/

struct Interval {
  Interval() : start(0), end(0) {};
  Interval(int s, int e) : start(s), end(e) {};
  int start;
  int end;
};


vector<Interval> intervalOverlap(vector<Interval> intervals1, vector<Interval> intervals2)
{
  vector<int> starts;
  vector<int> ends;

  for (auto inter : intervals1) {
    starts.push_back(inter.start);
    ends.push_back(inter.end);
  }

  for (auto inter : intervals2) {
    starts.push_back(inter.start);
    ends.push_back(inter.end);
  }

  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());

  int room = 0;
  int i = 0, j = 0;
  vector<Interval> results;

  while (i < starts.size() && j < ends.size())
  {
    if (starts[i] < ends[j]) {
      room++;
      if (room == 2)
      {
        Interval newInterval;
        newInterval.start = starts[i];
        results.push_back(newInterval);
      }
      i++;
    }
    else {
      room--;
      if (room == 1)
      {
        results.back().end = ends[j];
      }
      j++;
    }
  }
  return results;
}


vector<Interval> intervalIntersection(vector<Interval> intervals1, vector<Interval> intervals2)
{
  map<int, int> slots;

  for(auto inter : intervals1)
  {
    slots[inter.start]++;
    slots[inter.end]--;
  }

  for(auto inter : intervals2)
  {
    slots[inter.start]++;
    slots[inter.end]--;
  }

  int room = 0;
  vector<Interval> results;

  for(auto it = slots.begin(); it != slots.end(); it++)
  {
    int prevRoom = room;
    room += it->second;
    if(room == 2)
    {
      Interval newInterval;
      newInterval.start = it->first;
      results.push_back(newInterval);
    }
    else if(room == 1 && prevRoom == 2)
    {
      results.back().end = it->first;
    }
  }

  return results;
}

/*
int main(int argc, char** argv)
{
  vector<Interval> i1 = {
    {1, 4},
    {5, 7},
    {9, 12}
  };
  vector<Interval> i2 = {
    {1, 3},
    {5, 6},
    {44, 55}
  };

  for (auto ol : intervalIntersection(i1, i2)) {
    cout << ol.start << " " << ol.end << endl;
  }
}
*/

