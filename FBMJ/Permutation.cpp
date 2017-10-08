/*
 * Permutatoin I
 * Given a collection of distinct numbers, return all possible permutations.
 */

#include <vector>
#include <unordered_set>

using namespace std;

void fillPermutation(vector<vector<int>>& results, vector<int>& nums, int pos)
{
	if(pos == nums.size())
	{
		results.push_back(nums);
		return;
	}

	for(int i=pos; i<nums.size(); i++)
	{
		swap(nums[i], nums[pos]);
		fillPermutation(results, nums, pos+1);
		swap(nums[i], nums[pos]);
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> results;
    fillPermutation(results, nums, 0);
    return results;
}

/*
 * Permutations II
 * consider duplicates exists in the array
 */
void fillPermutationII(vector<vector<int>>& results, vector<int>& nums, int pos)
{
	if(pos == nums.size())
	{
		results.push_back(nums);
		return;
	}

	unordered_set<int> visited;
	for(int i=pos; i<nums.size(); i++)
	{
		if(visited.count(nums[i])) continue;
		visited.insert(nums[i]);
		swap(nums[i], nums[pos]);
		fillPermutation(results, nums, pos+1);
		swap(nums[i], nums[pos]);
	}
}

vector<vector<int>> permuteII(vector<int>& nums)
{
    vector<vector<int>> results;
    fillPermutation(results, nums, 0);
    return results;
}

// if we want to imporve the space complexity then

void fillPermutations2(vector<vector<int>>& results, vector<int> nums, int pos)
{
    if(pos == nums.size())
    {
        results.push_back(nums);
        return;
    }
    for(int i=pos; i < nums.size(); i++)
    {
        if(i != pos && nums[i] == nums[pos]) continue;
        swap(nums[i], nums[pos]);
        fillPermutations2(results, nums, pos+1);
    }

}
vector<vector<int>> permuteUnique(vector<int>& nums)
{
    if(nums.empty()) return results;
    sort(nums.begin(), nums.end());
    fillPermutations2(results, nums, 0);
    return results;
}



