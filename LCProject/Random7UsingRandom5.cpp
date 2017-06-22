/*
Given a random generator random5(), the return value of random5() is 0 - 4 with equal probability. 
Use random5() to implement random7().
*/

#include <algorithm>

using namespace std;

// call this in solution constructor srand(time(NULL));

// this is the rand5() function we need to use to implement rand7()
int rand5()
{
	return rand() % 5;
}

// helper funtion
int rand25()
{
	return rand5() * 5 + rand5();
}

int rand7()
{
	int seed = rand25();
	while (seed > 20)
	{
		seed = rand25();
	}
	return seed % 7;
}