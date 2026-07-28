//shortest_path_unit_length.cpp

//so basically we would be given an undirected graph, and each edge weight is 1 , we want to find the  path lenth to all the other nodes 
#include<iostream>
#include<utility>
#include<queue>
using namespace std;

vector<int> path_length(vector<vector<int>> adj , int source_node)
{
	vector<bool> visited(adj.size() , false);
	vector<int> path_length(adj.size() , -1);
	queue<pair<int , int>> d1;

	visited[source_node] = true;
	d1.push({source_node , 0});

	while(!d1.empty())
	{
		pair<int , int> front_node = d1.front();
		d1.pop();

		int parent_node = front_node.front;
		int current_level = front_node.second;

		for(int index = 0 ; index < adj[parent_node].size() ; index++)
		{
			if(!visited[adj[parent_node][index]])
			{
				visited[adj[parent_node][index]] = true;
				d1.push({adj[parent_node][index] , current_level+1});
				path_length[adj[parent_node][index]] = current_level+1;
			}
		}
	}

	//for all the nodes whose distance is -1 , that nodes cannot be reached hence we change those path length to infinity
	for(int index = 0 ; index < path_length.size() ; index++)
	{
		if(path_length[index] == -1)
		{
			path_length[index] = INT_MAX;
		}
	}

	return path_length
}