/******************************************************************************/
/**
* Question: #179 Largest Number
* Given a list of non negative integers, arrange them such that they form the largest number.
* For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*
* Note:
* The result may be very large, so you need to return a string instead of an integer.
*
*/
/*****************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LargestNum {
public:
	string largestNumber(vector<int>& nums) {
		string ret;
		int n = nums.size();
		if (n == 0) return ret;

		std::sort(nums.begin(), nums.end(), my_cmp2);

		for (int i = 0; i<nums.size(); i++)
		{
			ret += to_string(nums[i]);
		}

		if (ret[0] == '0') return "0";

		return ret;
	}

	static inline long long catNum(int lhs, int rhs)
	{
		if (rhs == 0) return lhs * 10;
		int tmp = rhs;
		long long base = 1;
		while (tmp) {
			tmp /= 10;
			base *= 10;
		}
		return lhs*base + rhs;
	}

	static bool my_cmp1(const int a, const int b)
	{
		string s_a = to_string(a);
		string s_b = to_string(b);

		return (s_a + s_b) > (s_b + s_a);
	}

	// my_cmp2 is faster!!
	static bool my_cmp2(int a, int b)
	{
		long long ab = catNum(a, b);
		long long ba = catNum(b, a);
		return (ab > ba);
	}


};


/*
int main(int argc, char * argv)
{
	vector<int> nums = { 3, 30, 34, 9, 5 };

	LargestNum lNum;
	cout << lNum.largestNumber(nums) << endl;

	system("pause");

}
*/