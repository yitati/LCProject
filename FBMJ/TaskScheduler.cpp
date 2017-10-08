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

using namespace std;

// 1. tasks need to follow the certain order
int taskScheduler1(vector<char>& tasks, int n)
{
  int time = 1;
  for(int i = 1; i < tasks.size(); i++)
  {
    if(tasks[i] == tasks[i-1]) time += n;
    time += 1;
  }
  return time;
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
  int round = 0;
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
