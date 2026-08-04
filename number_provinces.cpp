//number_provinces.cpp

//given an undireccted graph we have to find the number of provinces 
//two provincres are said to be connected if you cona reach from v to u and then u to v vice versa 
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
void provinces(vector<vector<int> &adj)
{
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
	//after this process just count the number of unique parents 
	cout<<"THE NUMBER OF PROVINCES ARE "<< set(parent.begin() , parent.end());
}