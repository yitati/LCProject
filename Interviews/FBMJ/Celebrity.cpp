/*
 * Celebrity.cpp
 *
 *  Created on: Oct 9, 2017
 *      Author: JoanneY1
 */

bool knows(int i, int j)
{
	return true;  // fake function
}

int findCelebrity(int n)
{
	int cand = 0;
	// choose the protential candidate
	for(int i=1; i<n; i++)
	{
		if(knows(cand, i)) cand = i;
	}

	// make sure candidate does not know anyone before previous check
	for(int i=0; i<cand; i++)
	{
		if(knows(cand, i)) return false;
	}

	// make sure that everyone knows the celebrity
	for(int i=0; i<n; i++)
	{
		if(!knows(i, cand)) return false;
	}

	return cand;
}


