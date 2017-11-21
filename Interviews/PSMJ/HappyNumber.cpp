/*
 * HappyNumber.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: JoanneY1
 */

/*
 * the math behind this https://en.wikipedia.org/wiki/Happy_number
 * No matter what number we start with, we eventually drop below 100.
 */
#include <unordered_set>
#include <iostream>

using namespace std;

bool isHappy(int n)
{
	unordered_set<int> nums;
	int num = n;

	while(true)
	{
		int sum = 0;
		while(num)
		{
			sum += (num%10)*(num%10);
			num /= 10;
		}
		num = sum;
		if(num == 1) return true;
		if(nums.count(num)) return false;
		nums.insert(num);
	}
	return false;
}

/*
 * Math Prove:
 * 1. If 1 appears in the loop, then it must be happy number.
 * 2. If there is a loop without 1, then it must not be happy because after k steps it will become a non-zero number.
 * But does all non-happy number has a loop?
 * 3. A seed number will have infinite sequence, if we can prove that value in sequence is bounded, then there must be
 * a duplicate/loop.
 * 4. Let's take 3-digit num, it can only go descendingly, why?
 *    - the max next num of 3-digit num, is from 3-digit num 999, which is 81*3 = 243, smaller than 999
 *    - that means the value in sequence can never exceed 999, so sum of square sequence is bounded, so must have loop
 *    - if a seed num ends up looping 1 then it's a happy number, it ends up looping other num, so it's not happy
 */



