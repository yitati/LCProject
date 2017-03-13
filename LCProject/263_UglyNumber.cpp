/******************************************************************************/
/**
* Question: #263 Ugly Number
* Write a program to check whether a given number is an ugly number.
* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
* For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
* Note that 1 is typically treated as an ugly number.
*/
/*****************************************************************************/

#include <unordered_set>

using namespace std;

bool isUgly(int num) {

	for (int i = 2; (i < 6) && num; i++)
	{
		while (num % i == 0) num = num / i;
	}
	return (num == 1);
}