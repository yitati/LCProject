/******************************************************************************************************
 * Question #295 Find Median From Data Stream
 * company tag: Facebook, eBay
 * Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value.
 * So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

 * Design a data structure that supports the following two operations:
 * void addNum(int num) - Add a integer number from the data stream to the data structure.
 * double findMedian() - Return the median of all elements so far.
 *
For example:
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
 ******************************************************************************************************/

#include <queue>

using namespace std;

/*
 * the median of an array of numbers is the middle number if the array has odd number of elements,
 * or average of the middle two number if we have even number of elements.
 * Keep two heaps to store numbers
 * small - it is a max heap, will store the smaller half of the numbers
 * large - it is the min heap, will store the larger half of the numbers
 * to avoid makeing special comparators we can use max heap to store negative numbers , so the top
 * will be the smallest in its value before negation.
 * One thing to notice is that we want to keep small.size() >= large.size()
 * Also we need to store long instead of int to avoid overflowing.
 */

class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num)
    {
        // first push it to small pile
        small.push(num);
        large.push(-small.top());
        small.pop();
        while(small.size() < large.size())
        {
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian()
    {
        return small.size() > large.size() ? small.top() : 0.5 *(small.top()-large.top());
    }
private:
    priority_queue<long> small, large;
};

