/******************************************************************************/
/*
* Question: #355 Design Twitter
* Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and 
* is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:
* 1.postTweet(userId, tweetId): Compose a new tweet.
* 2.getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed
* must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to
* least recent.
* 3.follow(followerId, followeeId): Follower follows a followee.
* 4.unfollow(followerId, followeeId): Follower unfollows a followee.

Example:
Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);

*/
/*****************************************************************************/

#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter()
	{
		time = 0;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId)
	{
		time++;
		user[userId].insert(Tweet(time, tweetId));
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId)
	{
		vector<int> feed;
		priority_queue<Record> maxHeap;
		// push all current user's tweets into the maxHeap
		auto it = user.find(userId);
		if(it != user.end())
		{
			maxHeap.push(Record(it->second.begin(), it->second.end()));
		}
		// push all its followee's tweets into the maxHeap
		auto follows = relation.find(userId);
		if(follows != relation.end())
		{
			for(int followId : follows->second)
			{
				auto it = user.find(followId);
				if(it != user.end())
				{
					maxHeap.push(Record(it->second.begin(), it->second.end()));
				}
			}
		}

		while(feed.size() < 10 && !maxHeap.empty())
		{
			Record top = maxHeap.top();
			maxHeap.pop();
			feed.push_back(top.begin->tweetId);
			top.begin++;
			if(top.begin != top.end) maxHeap.push(top);
		}

		return feed;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId)
	{
		if(followerId == followeeId) return;
		relation[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId)
	{
		if(followerId == followeeId) return;
		relation[followerId].erase(followeeId);
	}

private:
	struct Tweet;
	struct Record;
	typedef set<Tweet>::iterator TweetIter;
	typedef unordered_map<int, unordered_set<int>>::iterator RelationIter;
	typedef unordered_map<int, set<Tweet>>::iterator UserIter;

	/** Tweet struct **/
	struct Tweet
	{
		int timestamp;
		int tweetId;
		inline Tweet(int t, int tid):timestamp(t), tweetId(tid){};
		// this < operator is used to order from latest tweet to oldest
		inline bool operator<(const Tweet& rhs) const
		{
			return timestamp > rhs.timestamp;
		}
	};

	/** Record struct **/
	struct Record
	{
		TweetIter begin;
		TweetIter end;
		inline Record(const TweetIter& b, const TweetIter& e): begin(b), end(e){};
		// user to find the latest tweet in heap
		inline bool operator<(const Record& rhs) const
		{
			return begin->timestamp < rhs.begin->timestamp;
		}
	};

	int time;
	unordered_map<int, unordered_set<int>> relation;
	unordered_map<int, set<Tweet>> user;
};
