//print_shortest_path.cpp

//in this code we need to print the shortest path from the initial node to the final node the path length is not required 
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<algorithm>
#include<climits>

using namespace std;

void shortest_path_dijsktra(vector<vector<pair<int , int>>> &adj)
{
	//here we will again use the min heap 
	priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
	vector<int> parent(adj.size() , -1);
	vector<int> path_length(adj.size() , INT_MAX);

	pq.push({0, 0}) ; //distance , node;
	path_length[0] = 0 ;

	while(!pq.empty())
	{
		pair<int,int> front_node = pq.top();
		int current_distance = front_node.first;
		int current_node = front_node.second;
		pq.pop();

		if(current_distance > path_length[node])
				continue;

		//now we need to get the neighbours of that node 
		for(int index = 0 ; index <adj[current_node].size() ; index++)
		{
			pair<int,int > front1 = adj[current_node][index];
			int node = front1.first;
			int distance = front1.second;

			
			if(current_distance + distance < path_length[node])
			{
				parent[node] = current_node;
				path_length[node] = current_distance + distance;
				pq.push({current_distance+ distance , node});
			}
		}
	}

	//now we traverse from backwards
	vector<int> result ;
	//get the parent of the last node and so on 
	int current_node = adj.size()-1;
	while(current_node != -1)
	{
		result.push_back(current_node);
		current_node = parent[current_node];
	}

	if(result.size() == 1)
	{
		cout<<"CANT BE REACHED "<<endl;
		return ;
	}

	//we need to reverse the vector 
	reverse(result.begin() , result.end());

	for(int x : result)
	{
		cout<<x<<endl;
	}
	return;
}