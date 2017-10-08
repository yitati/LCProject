/*
 * MovieNetwork.cpp
 *
 *  Created on: Sep 23, 2017
 *      Author: JoanneY1
 */

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Movie
{
	int id;
	float rate;
	vector<Movie*> similarMovies;
};

vector<Movie*> findHighRates(Movie* movie, int k)
{
	auto comp = [&](const Movie* lhs, const Movie* rhs) -> bool {
		return lhs->rate > rhs->rate;
	};

	priority_queue<Movie*, vector<Movie*>, decltype(comp)> minHeap(comp);

	// bfs iterate through the network
	unordered_set<int> visited;
	queue<Movie*> layer;
	layer.push(movie);
	visited.insert(movie->id);

	while(!layer.empty())
	{
		int layerSize = layer.size();
		for(int i=0; i<layerSize; i++)
		{
			Movie* curr = layer.front();
			layer.pop();
			for(auto neigh : curr->similarMovies)
			{
				if(visited.count(neigh->id)) continue;
				visited.insert(neigh->id);
				minHeap.push(neigh);
				if(minHeap.size() > k)
				{
					minHeap.pop();
				}
				layer.push(neigh);
			}
		}
	}

	vector<Movie*> result;
	while (!minHeap.empty())
	{
		result.push_back(minHeap.top());
		minHeap.pop();
	}

	return result;
}


