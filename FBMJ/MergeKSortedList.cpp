/*
 * MergeKSortedList.cpp
 */


/*
 * 给两个递增的arrayList, 实现Iterator的next() function... followup, K个list， 继续实现next() function...
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TwoArrayIterator {
public:
  TwoArrayIterator(vector<int>& a1, vector<int>& a2) :
  a1Ref(a1), a2Ref(a2) {
    pos1 = 0;
    pos2 = 0;
  }

  int next() {
    //Please implement
    //if(!hasNext()) return -1;   // this is not good since we need to let it crash / throw exception
    if(pos1 >= a1Ref.size()) return a2Ref[pos2++];
    else if(pos2 >= a2Ref.size()) return a1Ref[pos1++];
    else
    {
      return a1Ref[pos1] <= a2Ref[pos2] ? a1Ref[pos1++] : a2Ref[pos2++];
    }
  }

  bool hasNext() {
    //Please implement
    if(pos1 >= a1Ref.size() && pos2 >= a2Ref.size()) return false;
    return true;
  }

private:
  vector<int>& a1Ref;
  vector<int>& a2Ref;
  int pos1;
  int pos2;
};


class KArrayIterator {
public:
  KArrayIterator(vector<vector<int>>& arrays)
  {
    for(int i=0; i<arrays.size(); i++)
    {
      if(!arrays[i].empty())
      {
        minHeap.push(make_pair(arrays[i].begin(), arrays[i].end()));
      }
    }
  }

  int next()
  {
    auto top = minHeap.top();
    minHeap.pop();
    int val = *top.first;
    top.first++;
    if(top.first != top.second)
    {
      minHeap.push(top);
    }
    return val;
  }

  bool hasNext()
  {
    return !minHeap.empty();
  }

private:
  typedef vector<int>::const_iterator Iterator;
  typedef pair<Iterator, Iterator> Ipair;

  class Comp
  {
  public:
    bool operator()(const Ipair& lhs, const Ipair& rhs) const
    {
      return *lhs.first > *rhs.first;
    }
  };

  priority_queue<Ipair, vector<Ipair>, Comp> minHeap;

};
