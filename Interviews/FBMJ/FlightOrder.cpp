/*
给你一堆飞机票排序，A--》B， B--》C  输出 A,B,C 我直接说用拓扑排序，他说太复杂了，我就蒙蔽了，跟他说怎么复杂了？
你想让我优化时间复杂度还是空间复杂度，他说就是太复杂了。
后来搞了半天才明白他的意思是每个城市只会在他的输入中出现一次，不用统计入度。
我最后还是用dict 存a-->b 关系，用set找出start point， 然后进入dict从头走到尾。
求问这题还能怎么优化？

http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=295682&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
*/

#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector<char> getFlightOrder(vector<pair<char, char>> flights)
{
  unordered_map<char, char> table;
  vector<int> freq(flights.size(), 0);

  for(auto f : flights)
  {
    table[f.first] = f.second;
    freq[f.first-'A']++;
    freq[f.second-'A']++;
  }

  char start = 'A';
  for(int i=0; i<flights.size(); i++)
  {
    if(freq[i] == 1 && table.count(i+'A'))
    {
      start = i + 'A';
      break;
    }
  }

  vector<char> order;
  order.push_back(start);
  while(order.size() <= flights.size())
  {
    order.push_back(table[start]);
    start = table[start];
  }

  return order;
}
