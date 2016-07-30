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

	// there could be at most 2 majority elements in array
	vector<int> majorityElementII(vector<int>& nums) {
		vector<int> champions;
		if (nums.size() == 0) return champions;
		int champion1 = nums[0], champion2 = nums[0];
		int count1 = 0, count2 = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] != champion1 && nums[i] != champion2) {
				if (count1 == 0) { champion1 = nums[i];  count1 = 1; }
				else if (count2 == 0) { champion2 = nums[i]; count2 = 1; }
				else { count1--; count2--; }
			}
			else if (nums[i] == champion1) { count1++; continue; }
			else if (nums[i] == champion2) { count2++; continue; }
		}
		count1 = 0;
		count2 = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == champion1) count1++;
			else if (nums[i] == champion2) count2++;
		}

		if (count1 > nums.size() / 3) champions.push_back(champion1);
		if (count2 > nums.size() / 3) champions.push_back(champion2);
		return champions;

	}
};

int main(int argc, char * argv[])
{
	cout << "Main starts" << endl;
	MajorityElement major;
	vector<int> num = { 1, 1, 3, 4, 5, 1, 1, 3, 3, 3, 1 };

	vector<int> champions = major.majorityElementII(num);
	for (int i = 0; i < champions.size(); i++) 
	{
		cout << champions[i] << endl;
	}
	

	system("pause");

}


