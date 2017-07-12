/*****************************************************************************************
 * Question #244 Shortest Word Distance II
 * company tag: LinkedIn
 * This is a follow up of Shortest Word Distance. The only difference is now you are given
 * the list of words and your method will be called repeatedly many times with different parameters.
 * How would you optimize it?
 * Design a class which receives a list of words in the constructor, and implements a method that
 * takes two words word1 and word2 and return the shortest distance between these two words
 * in the list.

 For example,
 Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

 Given word1 = “coding”, word2 = “practice”, return 3.
 Given word1 = "makes", word2 = "coding", return 1.

 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 ****************************************************************************************/

#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

class WordDistance {
public:
    WordDistance(vector<string> words)
    {
        // log word and its index array
        for(int i=0; i<words.size(); i++)
        {
            table[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2)
    {
        vector<int>& array1 = table[word1];
        vector<int>& array2 = table[word2];
        int minDis = INT_MAX, p1 = 0, p2 = 0;
        while(p1 < array1.size() && p2 < array2.size())
        {
            minDis = min(minDis, abs(array1[p1]-array2[p2]));
            if(array1[p1] < array2[p2]) p1++;
            else p2++;
        }

        return minDis;
    }
private:
    unordered_map<string, vector<int>> table;
};




