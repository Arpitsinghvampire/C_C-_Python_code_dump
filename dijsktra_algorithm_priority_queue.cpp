//dijsktra_algorithm_priority_queue.cpp

//in each path of the algorithm we are trying to store the minimum path length from the source node to all the nodes , at each part will be trying to store the min lenght 
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

//so here we would be using the min heap portion  , which has the minimum distance at the first position 
vector<int> dijsktra_algorithm(vector<vector<pair<int , int>>> adj)
{
	//this is a weighted graph  and we want to store the node as well as the distance from that node to the other node 
	priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;

	//this stores the min heap , we would be storing the data as the distance and the node 
	//the min heap will store the min distance first 
	pq.push({0,0});

	//by default we need to get the distance from the  source node 
	vector<int> path_length(adj.size() , INT_MAX);
	path_length[0] = 0 ;

	while(!pq.empty())
	{
		//get the source node and the  distance to that node and then update the distance 
		//here we do not use the concept of visited  , because we might get even smaller distance than we have right now
		pair<int , int> front_node = pq.top();
		pq.pop();
		//now we have the front node containing the distance and the current node 
		int current_distance = front_node.first;
		int current_node = front_node.second;

		//now we check the neighbours 
		for(int index = 0 ; index < adj[current_node].size() ; index++)
		{
			pair<int , int> pairs1 = adj[current_node][index];
			int distance = pairs1.first;
			int node = pairs1.second;
 

			if(path_length[node] > distance + current_distance)
			{
				pq.push({distance + current_distance  , node});
				path_length[node] = distance+ current_distance;
			}	
			
		}
	}
	return path_length;
}