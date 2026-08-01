//number_of_ways_destination.cpp

//here we want to get the number of ways by which we can reach the destination node from the source node 
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<map>
using namespace std;

//we want to get the number of ways we can get to each node  using the min distance 
int number_paths(vector<vector<pair<int ,int>>> &adj)
{
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	//this stores the distance and the node 
	vector<int> path_length(adj.size() , INT_MAX);
	vector<int> count_path(adj.size() , 0);

	count_path[0] = 1;
	path_length[0] = 0 ;
	pq.push({0,0});

	while(!pq.empty())
	{
		//we then get the neighbours 
		pair<int , int>  front_node = pq.top();
		int current_path_length = front_node.first;
		int current_node = front_node.second;
		pq.pop();

		//now we then get the neighbours of that node
		for(int index = 0 ; index < adj[current_node].size() ; index++)
		{
			pair<int , int> node = adj[current_node][index];
			int distance = node.second;
			int next_node = node.first;

			//now we see the distance to the next node 
			if(current_path_length + distance < path_length[adj[current_node][index].first])
			{
				path_length[adj[current_node][index].first] = current_path_length+ distance ; //need to update the shortest path 
				count_path[adj[current_node][index].first] = count_path[current_node]; //this depends on the number of ways we reach the parent of that node 
				pq.push({current_path_length+ distance , next_node});

			}
			else if(current_path_length + distance == path_length[adj[current_node][index].first])
			{
				//if the distance is the same , we do not have to push into the queueu because the elements would be the same 
				//if we are able to reach to that node using that node and the distance is  the smallest distance 
				//then we need to add the number of ways we can reach the parent node , because that is just an extension 
				count_path[adj[current_node][index].first] += count_path[current_node];

			}
		}

	}
	//after getting the number of ways we can reach the element  , just return the last element of the count_path to get the number of ways 
	return count_path.back();

}