//flloyd_warshall_algorithm.cpp

//in this code block we would be given some nodes , we have to find the smallest distance from all the other nodes to all the other nodes 
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

void flloyd(vector<vector<pair<int , int>>> &adj , int rows , int columns , int current_matrix_index ) //here adj is the adjacency list with entries as the edge weight 
//when no edge weight exists by default infinity 
{
	for(int k = 0 ; k< adj.size() ; k++)
	{
		for(int i = 0 ; i< adj.size() ; i++)
		{
			for(int j = 0 ; j<adj.size() ; j++)
			{
				if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX)
				{
					adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
				}
			}
		}
	}
}