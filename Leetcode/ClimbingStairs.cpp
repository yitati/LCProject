/******************************************************************************/
/*
* Question: #70 Climbing Stairs
* You are climbing a stair case. It takes n steps to reach to the top.
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
* Note: Given n will be a positive integer. 
*/
/*****************************************************************************/

using namespace std;

int climbStairs(int n) 
{
	if (n <= 2) return n;
	int fn_1 = 2, fn_2 = 1, fn = 0, step = 0;
	while (n-2)
	{
		fn = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
		n--;
	}

	return fn;
}