/*
 * RandomPickNonEmpty.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: JoanneY1
 */

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

给你一个数字n, 代表从1->n  n个slot， 再给一个数组存着空slot的id. 让你同概率下randomly 返回一个非空的slot。
example:
n = 8, slots: 1,2,3,4,5,6,7,8
emptycells = {3, 5}
non empty cells: 1,2,4,6,7,8
return one of non empty cells randomly with equal probability.
*/

int sampleNonEmpty(int n, vector<int> emptyCells)
{
  unordered_set<int> empty;
  for(int em : emptyCells) empty.insert(em);

  int slot;
  while(1)
  {
    slot = rand()%n + 1;
    if(!empty.count(slot)) break;
  }

  return slot;
}


