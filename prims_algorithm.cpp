//prims_algorithm.cpp

//here we want to create a minimum spanning tree , given the nodes
//so here we would use the priority queue
//the core intuition of the problem is that , add the least edge weight of the connected components see if it creates a cycle or not 
//if it creates a cycle do not take that element , else take that element 
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<climits>
#include<stack>
using namespace std;

//not needed in the prims algorithm  ,every node is visited once 
bool cycle_exists(vector<pair<int , int>> current_graph , int parent_node , int child_node , vector<vector<int>> &adj) //for the undirected graph 
{
	//we firs t conver the type of the current graph 
	vector<vector<int>>graph(adj.size() , vector<int>({}));
	graph[parent_node].push_back(child_node);

	//now we push all the other elements 
	for(int index = 0 ; index < current_graph.size() ; index++)
	{
		pair<int , int> front_node = current_graph[index];
		graph[front_node.first].push_back(front_node.second);
	}
	//now we applyt he dfs algorithm 
	vector<bool> visited(graph.size() , false);
	vector<int> parent(graph.size() , -1);
	stack<int>  s1;
	s1.push(0);
	while(!s1.empty())
	{
		int front_node = s1.top();
		s1.pop();
		//now we get the neighbours of that node 
		for(int index = 0 ; index < graph[front_node].size() ; index++)
		{
			if(!visited[graph[front_node][index]])
			{
				//visit that node ,and then push them back onto the stack 
				s1.push(graph[front_node][index]);
				parent[graph[front_node][index]] = front_node;
				visited[graph[front_node][index]] = true;
			}
			else
			{
				//if you have visited that node 
				//chekc for the parent 
				if(parent[graph[front_node][index]] != front_node)
				{
					return true ;
				}
			}
		}
	}
	return false;
}

vector<pair<int , int>> prims(vector<vector<pair<int , int>>> &adj)//this is the adjacency list 
{
	//here we would have the elemetns in the priority queue as edge_weight , node ,parent because we might need to backtrack 
	priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
	//the nodes are of the structure (edge_weight  , node ,parent_node)
	vector<bool> visited(adj.size() , false);
	vector<pair<int,int>> mst ; //each pair contains the parent and the corresponding child 

	//we then push the first node into the priority queue
	pq.push({0 , {0 , -1}});
	int min_weight = 0 ;
	while(!pq.empty())
	{
		pair<int , pair<int , int>> front_node = pq.top();
		int edge_weight = front_node.first;
		int child_node = front_node.second.first;
		int parent_node = front_node.second.second;
		//push into the mst 
		if(parent_node != -1)
		{
			mst.push_back({parent_node , child_node});
		}
		min_weight += edge_weight;
		pq.pop();

		if(visited[child_node])
		{
			continue ;  //do not hassle forward if already visited ;
		}
		visited[child_node] = true;
		for(int index =0 ; index <adj[child_node].size() ; index++)
		{
			pair<int , int> nodes = adj[child_node][index];
			int current_node = nodes.first;
			int current_weight = nodes.second;
			//if the current_node is unvisited , then we need to visit it 
			if(visited[current_node])
			{
				continue ;
			}

			if(!visited[current_node]) 
			{
				//visit the node ,and also push into the queue
				pq.push({current_weight , {current_node , child_node}});
			}
		}

	}
	return mst;

}