/*
Given a random generator random5(), the return value of random5() is 0 - 4 with equal probability. 
Use random5() to implement random1000()
*/


#include <algorithm>
#include <time.h>

using namespace std;

class Rand1000UsingRand5
{

private:
	int rand5()
	{
		return rand() % 5;
	}

	int rand3125()
	{
		int base = 1, seed = 0;
		for (int i = 0; i<5; i++)
		{
			seed += rand5()*base;
			base *= 5;
		}
		return seed;
	}
public:
	Rand1000UsingRand5()
	{
		srand(time(NULL));
	}
	// 5^5 = 3125 > 1000
	// so we need bit here
	int rand1000()
	{
		int seed = rand3125();
		while (seed >= 1000)
		{
			seed = rand3125();
		}
		return seed;
	}

};