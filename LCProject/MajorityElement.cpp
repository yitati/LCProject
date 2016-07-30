/******************************************************************************/
/**
* Question: #169 Majority Element
* Given an array of size n, find the majority element. The majority element is the element that
* appears more than n/2 times.
* You may assume that the array is non-empty and the majority element always exist in the array.
*
* Question: #229 Majority Element II
* Given an integer array of size n, find all elements that appear more than n/3 times. The algorithm
* should run in linear time and in O(1) space.
*
*/
/*****************************************************************************/

#include <iostream>
#include <vector>

using namespace std;



class MajorityElement {
public:
	int majorityElement(vector<int>& nums) {
		int count = 1;
		int champion = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == champion) { count++; continue; }
			else {
				count--;
				if (count == 0) { champion = nums[i]; count++; }
			}
		}
		return champion;

	}

	int majorityElementII(vector<int>& nums) {
		int count = 1;
		int champion = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == champion) { count++; continue; }
			else {
				count--;
				if (count == 0) { champion = nums[i]; count++; }
			}
		}
		return champion;

	}
};

int main(int argc, char * argv[])
{
	cout << "Main starts" << endl;
	MajorityElement major;
	vector<int> num = { 1, 1, 3, 4, 5, 1, 1 };

	cout << major.majorityElement(num) << endl;

	system("pause");

}


