/*
 * Laicode_SquareRootI.cpp
 *

Given an integer number n, find its integer square root.

Assumption:

n is guaranteed to be >= 0.
Example:

Input: 18, Return: 4

Input: 4, Return: 2

 */

#include <iostream>

using namespace std;

// Binary search solution
int sqrt(int x)
{
	long lhs = 1, rhs = x;
	while(lhs + 1  < rhs)
	{
		long mid = lhs + (rhs-lhs)/2;
		if(mid*mid == x) return mid;
		else if(mid*mid > x)
		{
			rhs = mid-1;
		}
		else
		{
			if((mid+1)*(mid+1) > x) return mid;
			else lhs = mid+1;
		}
	}
	if(rhs*rhs <= x) return rhs;
	return lhs;
}

int newTonSqrt(int x)
{
	int r = x;
	while(r*r > x)
	{
		r = (r + x/r)/2;
	}
	return r;
}


