/*
Consider an unlimited flow of data elements. How do you sample one element from this flow, 
such that at any point during the processing of the flow, you can return a random element from the n elements read so far.

You will implement two methods for a sampling class:

read(int value) - read one number from the flow
sample() - return at any time the sample, if n values have been read, the probability of 
returning any one of the n values is 1/n, return null(Java)/INT_MIN(C++) if there is no value read so far
You may need to add more fields for the class.
*/

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;


// std::srand(time(NULL)); is called for you.

class ReservoirSample
{
public:
	ReservoirSample() : sampled(0), resultSoFar(INT_MIN) { srand(time(NULL)); }
	int sample()
	{
		return resultSoFar;
	}

	void read(int i)
	{
		sampled++;
		if (rand() % sampled == 0)
		{
			resultSoFar = i;
		}
	}

	int sampled;
	int resultSoFar;
};

/* 
about srand(time(NULL))

A PRNG (pseudo-random number generator) generates a deterministic sequence of numbers dependent on the algorithm used. 
A given algorithm will always produce the same sequence from a given starting point (seed). If you don't explicitly seed 
the PRNG then it will usually start from the same default seed every time an application is run, resulting the same 
sequence of numbers being used.

To fix this you need to seed the PRNG yourself with a different seed (to give a different sequence) each time the 
application is run. The usual approach is to use time(NULL) which sets the seed based on the current time. As long as 
you don't start two instances of the application within a second of each other, you'll be guaranteed a different random sequence.

There's no need to seed the sequence each time you want a new random number. And I'm not sure about this, but I 
have the feeling that depending on the PRNG algorithm being used re-seeding for every new number may actually result 
in lower randomness in the resulting sequence.

*/
