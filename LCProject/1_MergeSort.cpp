// main function that calls merge_sort
// left: the left index of the sub vector
// right: the right index of the sub vector
// Time complexity is O(nlgn), space complexity is O(n)
#include <iostream>
#include <vector>
using namespace std;
// combine function -> move smaller one
vector<int> combine(vector<int> & lhs, vector<int>& rhs)
{
	int i = 0, j = 0, k = 0;
	int m = lhs.size(), n = rhs.size();
	// if we want to use result[k] then must initialize the size of the result 
	vector<int>result(m + n, 0);

	while (i < m || j < n)
	{
		int item1 = i < m ? lhs[i] : INT_MAX;
		int item2 = j < n ? rhs[j] : INT_MAX;
		if (item1 <= item2)
		{
			result[k++] = item1;
			i = i == m ? m : i + 1;
		}
		else
		{
			result[k++] = item2;
			j = j == n ? n : j + 1;

		}
	}
	return result;
}

vector<int> mergeSort(vector<int> &nums, int left, int right)
{
	vector<int> solution; // store the final solution
	if(left == right)
	{
		solution.push_back(nums[left]);
		return solution;
	}
	int mid = left + (right - left) / 2;
	vector<int> solu_left = mergeSort(nums, left, mid);
	vector<int> solu_right = mergeSort(nums, mid + 1, right);
	solution = combine(solu_left, solu_right); // who small move who
	return solution;
}

/*
// test the combine function
int main(int argc, char * argv)
{
	int i;
	int sample1[] = { 1, 3, 5, 7, 9 };
	int sample2[] = { 0, 2, 4, 6, 8 };

	vector<int> nums1(sample1, sample1 + sizeof(sample1)/sizeof(int));
	vector<int> nums2(sample2, sample2 + sizeof(sample2) / sizeof(int));

	vector<int>result = combine(nums1, nums2);

	int n = result.size();
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << endl;
	}

	system("pause");
}



int main(int argc, char* argv)
{
	int i;
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(8);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(6);

	int n = nums.size();
	nums = mergeSort(nums, 0, n - 1);

	for (i = 0; i < n; i++)
	{
		cout << nums[i] << endl;
	}

	system("pause");
}
*/


// Discuss
// 1. Could you use Merge Sort to sort a linked list? What is the time complexity if so?
// 2. similar problems - 
// 2.1 e.g., A1B2C3D4 - > ABCD1234  - only combine function is changed
// 2.2 (advanced topic) count-array problem

