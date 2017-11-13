/*
 * Laicode_GeneralizedReservoirSampling.cpp
 * company tag: eBay
Consider an unlimited flow of data elements.
How do you sample k element from this flow, such that at any point during
the processing of the flow, you can return a random set of k elements from
the n elements read so far.

Assumptions

k >= 1
You will implement two methods for a sampling class:

read(int value) - read one number from the flow
sample() - return at any time the k samples as a list, return the list of
all values read when the number of values read so fas <= k.
You may need to add more fields for the class.

 */

// http://www.geeksforgeeks.org/reservoir-sampling/


#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * This O(n) solution can be used if the data is very large or when dealing with data stream
 * 1. Create data reservoir[0...k-1] and copy first k items of stream[] to it
 * 2. Now one by one consider all items from (k+1)th to nth item.
 *    a. Generate a random number from 0 to i where i is the index of current item in stream[]. Let the
 *    the generated random number is j
 *    b. If j is in range 0 to k-1, replace reservoir[j] with stream[i]
 */

class KSample
{
private:
  int k;
  vector<int> sampled;
  int total;
public:
  KSample (int size)
  {
    k = size;
    total = 0;
    // initialize random seed
    srand(time(NULL));
  }
  vector<int> sample()
  {
    return sampled;
  }

  void read(int i)
  {
	  total++;
	  if(sampled.size() < k)
	  {
		  sampled.push_back(i);
	  }
	  else
	  {
		  int picked = rand()%total;
		  if(picked < k)
		  {
			  sampled[picked] = i;
		  }
	  }
  }

};

