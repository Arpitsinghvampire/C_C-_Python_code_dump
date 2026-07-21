//cycle_detection_using_dfs.cpp

//the logic is same as the cycle detectoj using the bfs traveraal , but here we would be using the dfs traversal 
//for each adjacency matrix , check if the node is visited or not 
//if the node is visited , check if it is the parent or not , if not the parent then cycle detected 
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

void cycle_detection_dfs(vector<vector<int> &adj)
{
	vector<bool> visited(adj.size() , false);
	//after filling the values , lets start with the index zero , here we send the node ,and its parent 
	stack<pair<int,int>> s1;

	s1.push({0,-1});
	visited[0] = true;

	while(!s1.empty())
	{
		pair<int , int> front_node = s1.top();
		int current_node = front_node.first;
		int parent_node = front_node.second;

		for(int index = 0 ; index < adj[0].size() ; index++)
		{
			if(!visited[adj[current_node][index]])
			{
			    visited[adj[current_node][index]] = true;
			    s1.push({adj[current_node][index] , current_node});
			}
			else
			{
				//if the node is already visited then we need to check whether its a prent node or not 
				if(adj[current_node][index] != parent_node)
				{
					cout<<"CYCLE DETECTED"<<endl;
					return ;
				}
			}
		}
	}
}