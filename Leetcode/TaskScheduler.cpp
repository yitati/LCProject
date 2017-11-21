/********************************************************************************
 * Question: #621 Task Scheduler
 * company tag: Facebook
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different
 * letters represent different tasks.Tasks could be done without original order. Each task could be done in
 * one interval. For each interval, CPU could finish one task or just be idle.
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be at
 * least n intervals that CPU are doing different tasks or just be idle.
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*****************************************************************************/

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
 * in this problem, we are free to change the order of all tasks.
 * Get the frequency of each task, then we can calculate the time interval according to the most
 * frequent one.
 */
int leastInterval(vector<char>& tasks, int n)
{
    int maxFreq = 0, countFreq = 0;
    vector<int> freq(26, 0);
    for(char task : tasks)
    {
        freq[task-'A']++;
        maxFreq = max(maxFreq, freq[task-'A']);
    }
    for(int i=0; i<26; i++)
    {
        if(freq[i] == maxFreq) countFreq++;
    }

    int maxLen = (maxFreq-1)*(n+1) + countFreq;
    int len = tasks.size();
    return max(len, maxLen);
}





