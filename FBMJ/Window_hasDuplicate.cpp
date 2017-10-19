
#include <vector>
#include <unordered_map>

using namespace std;

/*
给一个array, 然后给一个k, 让你check 连续的k个integer是否含有dulplicate
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=175190&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3090%5D%5Bvalue%5D%3D1%26searchoption%5B3090%5D%5Btype%5D%3Dradio%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
*/

bool hasDuplicate(vector<int>& nums, int k)
{
	int lhs = 0, rhs = 0;
	unordered_set<int> visit;

	while(rhs < nums.size())
	{
		if(!visit.count(nums[rhs]))
		{
			visit.insert(nums[rhs]);
			rhs++;
		}
		else
		{
			visit.erase(nums[lhs]);
			lhs++;
		}
		if(rhs-lhs >= k) return true;
	}

	return false;
}
