/************************************************************************************
 * Question #170 Two Sum III - Data structure design
 * company tag: LinkedIn
 * Design and implement a TwoSum class. It should support the following operations: add and find.
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
 *
 ************************************************************************************/

#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// TODO - discuss this with BAOBAO

// solution 1 - O(n) time for the add and O(1) time for the find
class TwoSumI {
public:
    /** Initialize your data structure here. */
	TwoSumI() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
    	if(nums.count(number)) twosum.insert(number+number);
    	else
    	{
    		for(auto it = nums.begin(); it != nums.end(); it++) twosum.insert(*it+number);
    		nums.insert(number);
    	}
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
    	return twosum.count(value);
    }

    //vector<int> nums;
    unordered_set<int> nums;
    unordered_set<long> twosum;
};

// solution 2 - O(1) time for the add and O(n) time for the find
class TwoSum{
public:
	/** Initialize your data structure here */
	TwoSum(){

	}

	/** Add the number to an internal data structure **/
	void add(int number){
		nums[number]++;
	}

	/** Find if there exits any pair of numbers which sum is equal to the value **/
	bool find(int value){
		for(auto it=nums.begin(); it != nums.end(); it++){
			int num = it->first;
			int target = value-num;
			if((target == num && it->second > 1) || (target != num && nums.count(target))) return true;
		}
        return false;
	}

private:
	unordered_map<int, int> nums;
};




/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */


