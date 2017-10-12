/*
 * company tag: Facebook
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

1. Tasks must follow the given order.
2. Tasks do not need to follow the given order.
*/


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// 1. tasks need to follow the certain order
/*
 * 外面试官，给一个String, 如AABACCDCD, 插入'_'使同一个字母间隔为k: 如果k=3: A___AB__AC___CD__CD,
 * 一开始理解有误，认为是要先shuffle字母顺序然后插入'_'，花了不少时间，然后面试官提示字母顺序不变，写出来，
 * 然后直接run出来有bug，在coderpad上调了一会才通过
 */
int taskScheduler(vector<char> tasks, int cooldown)
{
  int time = 0;
  if(tasks.empty()) return time;
  unordered_map<char, int> table;
  table[tasks[0]] = 0;

  // start from the second task
  for(int i=1; i<tasks.size(); i++)
  {
    if(table.count(tasks[i]))
    {
      int diff = time - table[tasks[i]];
      if(diff < cooldown) time = table[tasks[i]] + cooldown;
    }

    // update anyway
    time++;
    // update with latest time
    table[tasks[i]] = time;
  }

  return time;
}


/*
task scheduler 的变种，给出任务单和同种任务之间的cool down间隔，要求计算每个任务的执行时间列表。比如任务单为[1, 1, 2, 1],
cool down间隔为2，那么每个任务的执行时间应该是[0, 3, 4, 6]。这题用hashtable可以得出O(n)的解法。
*/

vector<int> taskScheduler(vector<char> tasks, int cooldown)
{
  vector<int> order;
  if(tasks.empty()) return order;
  int time = 0;
  unordered_map<char, int> table;
  table[tasks[0]] = 0;
  order.push_back(0);

  // start from the second task
  for(int i=1; i<tasks.size(); i++)
  {
    if(table.count(tasks[i]))
    {
      int diff = time - table[tasks[i]];
      if(diff < cooldown) time = table[tasks[i]] + cooldown;
    }

    time++;
    order.push_back(time);
    // update with latest time
    table[tasks[i]] = time;
  }

  return order;
}

// 2. tasks does not need to follow certain order
/*
The idea used here is similar to - https://leetcode.com/problems/rearrange-string-k-distance-apart
We need to arrange the characters in string such that each same character is K distance apart, where distance in this problems is
time b/w two similar task execution.

Idea is to add them to a priority Q and sort based on the highest frequency.
And pick the task in each round of 'n' with highest frequency. As you pick the task, decrease the frequency, and put them back after
the round.
 */
int taskScheduler2(vector<char>& tasks, int n)
{
  // use priority queue to store the frequency
  auto comp = [](const pair<char, int>& lhs, const pair<char, int>& rhs)->bool{
    return lhs.second < rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
  };

  priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> maxHeap(comp);

  vector<int> count(26, 0);
  // count frequency
  for(char c : tasks)
  {
    count[c-'A']++;
  }
  // init heap
  for(int i=0; i<count.size(); i++)
  {
    if(count[i] > 0) maxHeap.push(make_pair(i+'A', count[i]));
  }
  // calculate tasks
  int time = 0;

  while(!maxHeap.empty())
  {
    vector<pair<char, int>> temp;
    for(int i=0; i<=n; i++)
    {
      if(!maxHeap.empty())  // no need to push idle
      {
        auto top = maxHeap.top();
        maxHeap.pop();
        top.second--;
        if(top.second > 0)
        {
          temp.push_back(top);
        }
        time++;
      }
      else // we need to push idle
      {
        if(temp.empty()) break;  // the last round
        else time++;
      }
    }

    for(int i=0; i<temp.size(); i++)
    {
      maxHeap.push(temp[i]);
    }
  }
  return time;
}



int taskScheduler_math(vector<char>& tasks, int n)
{
  vector<int> count(26, 0);
  int maxFreq = 0, maxCount = 0;
  // count frequency
  for(char c : tasks)
  {
    count[c-'A']++;
    maxFreq = max(maxFreq, count[c-'A']);
  }

  for(int freq : count)
  {
    if(freq == maxFreq) maxCount++;
  }

  int idleLen = (maxFreq-1)*(n+1) + maxCount;
  return max(idleLen, (int)tasks.size());

}

/*
int main(int argc, char** argv)
{
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  cout << "taskScheduler1 time is "<< taskScheduler1(tasks, 2) << endl;
  cout << "taskScheduler2 time is "<< taskScheduler2(tasks, 2) << endl;
  cout << "taskSchedule_math time is " << taskScheduler_math(tasks, 2) << endl;
}
*/
