//kruskals_algorithm.cpp

//here we will be given a set of edges , we now need to find the minimum spanning tree for the same 
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<utility>
using namespace std;

void union_by_size(vector<int> &size1 ,vector<int> &parent ,  int node1 , int node2)
{
	//first check if the parent is same or not 
	if(parent[node1] != parent[node2])
	{
		//then check the size which one is larger 
		if(size1[node1] >= size1[node2])
		{
			size1[node1] += size1[node2];
			parent[node2] = parent[node1];
		}
		else
		{
			size1[node1] += size1[node1];
			parent[node1] = parent[node2];
		}
	}
	//if you are uniioning elements that are in the same set , then no change there 
}

bool creates_cycle(vector<int> &parent , int node1 , int node2 )
{
	if(parent[node1] == parent[node2])
	{
		return true;
	}
	return false;
}

vector<pair<int ,int>> kruskals_algorithm(vector<vector<pair<int ,int>>> &adj)
{
	//here we will be given a veector of vector containing the pairs , we just have  to  elements into the decreasing order og the edges 
	//the first part is the edge weight , the second will be the current node , and the third would be the parent node 
	vector<int> parent;
	int mst_weight= 0 ;
	for(int index =0 ;index < adj.size() ; index++)
	{
		parent.push_back(index); //each element is its own parent ;
	}

	vector<int> rank(adj.size() , 0);
	vector<int> mst;

	priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
	for(int index = 0 ; index < adj.size() ; index++)
	{
		for(int index1 = 0 ; index1 < adj[index].size() ; index1++)
		{
			pq.push({adj[index][index1].first , {adj[index][index1].second , index}});
		}
	}
	//now after this  pop the edges 
	while(!pq.empty())
	{
		pair<int , pair<int , int>> front_node  = pq.top();
		int edge_weight = front_node.first;
		int current_node = front_node.second.first;
		int parent_node = front_node.second.second ;
		pq.pop();

		//now we need to see whether that edge addition creates a cycle or not , if yes do not add in the mst 
		//else add in the mst 
		if(!creates_cycle(parent , current_node , parent_node))
		{
			mst_weight += edge_weight ;
			union_by_size(rank , parent , current_node , parent_node);
			//also add them to the mst 
			mst.push_back({parent_node , current_node});
		}
	}
	return mst;
}
