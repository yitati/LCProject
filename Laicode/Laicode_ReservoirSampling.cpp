/*
 * Laicode_ReservoirSampling.cpp
 *

Consider an unlimited flow of data elements. How do you sample one element from this flow,
such that at any point during the processing of the flow, you can return a random element
from the n elements read so far.

You will implement two methods for a sampling class:

read(int value) - read one number from the flow
sample() - return at any time the sample, if n values have been read, the probability of
returning any one of the n values is 1/n, return null(Java)/INT_MIN(C++) if there is no value read so far
You may need to add more fields for the class.

 */

#include <cstdlib>
#include <climits>
#include <ctime>

class ReservoirSample {
public:
	ReservoirSample() : sampled(0), resultSoFar(INT_MIN) {
		srand (time(NULL));}
		int sample()
		{
			return resultSoFar;
		}

		void read(int i)
		{
			sampled++;
			if(rand()%sampled == 0)
			{
				resultSoFar = i;
			}
		}

		// counter for number that has been read
		int sampled;
		// result to store current sampled number
		int resultSoFar;
	};
