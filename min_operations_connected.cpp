//min_operations_connected.cpp
//here we would be given a number of components , in this question we need to connect those components 

//if there are n components we need to use n-1 additional edges to connect them , these n-1 additional edges shouldcome from the existing graph
//this is similar to the previous problem we did  to find hte number of connected components
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

//here we would be given an adjacency matrix  , with binary inputs , , we now want to apply the union and the find set problem 
void union_algorithm(vector<int> &size1 , vector<int> &parent , int node1 , int node2)
{
	if(parent[node1] != parent[node2])
	{
		//check whichever size is large 
		if(size1[node1] >= size1[node2])
		{
			size1[node1] += size1[node2];
			parent[node2]= parent[node1];
		}
		else
		{
			size1[node2] += size1[node2];
			parent[node1]= parent[node2];
		}
	}
}

bool same_component(vector<int> parent , int node1 , int node2)
{
	if(parent[node1] == parent[node2])
	{
		return true;
	}
	return false;
}
//so we need to fins the number of extraneous edges if the number of extraneus edge is greater than the required n-1 then okay else
//return -1 
int extraneous_edges(vector<vector<int>> &adj)
{
	//we can calculate the number of extra edges by seeing the edges and if the two elements are alreasy in the same component then extra edge 
	int extra_edge = 0 ;
	vector<int> parent;
	vector<int> size1(adj.size() , 0);
	for(int index = 0 ;index < adj.size() ; index++)
	{
		parent.push_back(index);
	}
	for(int index = 0 ; index < adj.size() ; index++)
	{
		for(int index1 = index ; index1 < adj[0].size() ; index1++)
		{
			if(adj[index][index1] ==1) //no self edges 
			{
				//first check if they belong to the same component or not 
				if(parent[index] == parent[index1])
				{
					extra_edge ++ ;
				}
				else
				{
					union_algorithm(size1 , parent , index , index1);
				}
				
			}
		}
	}
	return extra_edge ; 

}
int   min_operations(vector<vector<int> &adj)
{
	int extra_edges = extraneous_edges(adj);
	vector<int> parent;
	for(int index = 0 ; index < adj.size() ; index++)
	{
		parent.push_back(index);
	}
	vector<int> size1(adj.size() , 0); //by default the size is 0 

	//now for eahc entry of the  get the components that are connected 
	for(int row = 0 ; row < adj.size() ; row++)
	{
		for(int column = 0 ; column < adj[0].size() ; column++)
		{
			//if the entry is 1 , then use the union algorithm 
			if(adj[row][column] == 1)
			{
				union_algorithm(size1 , parent , row , column);
			}
		}
	}
	set<int> s1(parent.begin() parent.end());
	if(extra_edge>= s1.size())
	{
		return s1.size();
	}
	else
	{
		return -1 ;
	}
}
