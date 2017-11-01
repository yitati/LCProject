/*
 * ABCD.cpp

刚结束的video interview， 是个中国大叔，人很好，口语也很标准。迟到了三分钟，嘘寒问暖两分钟就开始做题。惊到了，竟然是一道LC没有的题。
给一个int[], 输出所有 A + B = C + D 的unique index pairs, A B 下标不同，CD 下标不同， A B C D 输出以后，
就不能输出C D B A了 但是可以ABDC 和BACD这种

写了一个O(N2)的用hashmap得到所有sum 相同的pairs的 lists，但是输出不知道怎么办，硬着头皮写了个O(N4)的，然后时间就到了。
问题环节问大叔说这个你们在日常工作中经常碰到吗，他笑着说不是， 但是很重要，比如你刚写的这个O(N4) is pretty bad......
我看着他左边上扬右边不动的嘴角，我知道我应该move on 了。
求大米，希望大家能从我这里吸取经验。
另外LC没有找到这道题，希望大家能够给我个解法，更高效的，或者告知lc题号，蟹蟹


补充内容 (2017-10-7 10:01):
Sorry, 勘误， 如果输出ABCD就不能输出CDAB, 可以输出ABCD ABDC BADC BACD

http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=296345&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
 */

#include <vector>
#include <unordered_map>

using namespace std;

/*
 * if we always keep the value of a+b and the index of a and b, then we can go through array and try to find a c+d
 * where a+b = c+d
 */

vector<vector<int>> findTwoPairs(const vector<int>& array)
{
	unordered_map<int, vector<pair<int, int>>> table;
	vector<vector<int>> results;
	// align all the possible sum
	for(int i=0; i<array.size(); i++)
	{
		for(int j=i+1; j<array.size(); j++)
		{
			int sum = array[i] + array[j];
			table[sum].push_back(make_pair(i, j));
		}
	}
	// this is at most O(n^3)
	for(auto it = table.begin(); it != table.end(); it++)
	{
		auto list = it->second;
		if(list.size() <= 1) continue;
		for(int i=0; i<list.size(); i++)
		{
			for(int j=i+1; j<list.size(); j++)
			{
				// A != C && B != D
				if(list[i].first == list[j].first || list[i].second == list[j].second) continue;
				vector<int> result = {list[i].first, list[i].second, list[j].first, list[j].second};
			    results.push_back(result);
			}
		}
	}

	return results;
}

vector<vector<int>> findFourPairs(const vector<int>& array)
{
  vector<vector<int>> results;
  if(array.size() < 4) return results;

  vector<pair<int, int>> table;

  for(int i=0; i<array.size(); i++)
  {
    table.push_back(make_pair(array[i], i)); // make val-index pair array
  }

  sort(table.begin(), table.end()); // sort with default comparator

  for(int i=0; i<table.size()-3; i++)
  {
    for(int j=table.size()-1; j > i+2; j--)
    {
      int target = table[i].first + table[j].first;
      int lhs = i+1, rhs = j-1;
      while(lhs < rhs)
      {
        int sum = table[lhs].first + table[rhs].first;
        if(sum == target)
        {
          vector<int> lefts = { lhs };
          vector<int> rights = { rhs };
          while (lhs < rhs && table[lhs+1].first == table[lhs].first) {
            lefts.push_back(++lhs);
          }
          lhs++;

          while (rhs >= lhs && table[rhs-1].first == table[rhs].first) {
            rights.push_back(--rhs);
          }
          rhs--;

          for (int left : lefts) {
            for (int right : rights) {
              if (left >= right) continue;
              results.push_back({
                table[i].second,
                table[j].second,
                table[left].second,
                table[right].second
              });
            }
          }
        }
        else if(sum < target) lhs++;
        else rhs--;
      }
    }
  }

  return results;
}



