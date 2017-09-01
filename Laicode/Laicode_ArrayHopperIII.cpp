/*
 * Laicode_ArrayHopperIII.cpp
 *

Given an array of non-negative integers, you are initially positioned at index 0 of the array.
A[i] means the maximum jump distance from that position (you can only jump towards the end of the array).
Determine the minimum number of jumps you need to jump out of the array.

By jump out, it means you can not stay at the end of the array. Return -1 if you can not do so.

Assumptions

The given array is not null and has length of at least 1.
Examples

{1, 3, 2, 0, 2}, the minimum number of jumps needed is 3 (jump to index 1 then to the end of array, then jump out)

{3, 2, 1, 1, 0}, you are not able to jump out of array, return -1 in this case.

 */

#include <vector>

using namespace std;

/*
 * bfs solution
 */
int minJump(vector<int> input)
{
    if(input.empty()) return -1;
  	int i = 0, step = 0, currReach = 0, nextReach = 0;
  	while(currReach - i + 1 > 0)
  	{
  		step++;
  		for(; i < input.size() && i <= currReach; i++)
  		{
  			nextReach = max(i+input[i], nextReach);
  			if(nextReach >= input.size()) return step;
  		}
  		currReach = nextReach;
  	}
  	return -1;
}


