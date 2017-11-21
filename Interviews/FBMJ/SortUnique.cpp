/*
 * SortUnique.cpp
given a sorted number [1,1,2,2,3,4,4,5,5,5] return the total unique numbers and put them in the left side.
i.e. return 5 and the left 5 numbers will be [1,2,3,4,5,The_rest_doesnt_matter]
 */

#include <vector>

using namespace std;

int sortUnique(vector<int>& array)
{
  int unique = 0, fast = 1, slow = 0;

  while(fast < array.size())
  {
    if(array[fast] != array[slow])
    {
      array[++slow] = array[fast];
    }
    fast++;
  }

  return slow+1;
}




