//find_neighbours_threshold.cpp

//in this question we would be given a graph , and then we  would need to find the city with the minimum neighbourhood 
//a city is said to be a neighbour if the distance is less than the threshold
//so basically we need to find the distance of each node with all the other node ,and then count the number of neighbourhood for each node 
//flloyd_warshall_algorithm.cpp

//in this code block we would be given some nodes , we have to find the smallest distance from all the other nodes to all the other nodes 
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int flloyd(vector<vector<pair<int , int>>> &adj , int rows , int columns , int current_matrix_index , int threshold ) //here adj is the adjacency list with entries as the edge weight 
//when no edge weight exists by default infinity \
{

	vector<int> neighbours(adj.size() , 0);
	for(int k = 0 ; k< adj.size() ; k++) //for teh intermediate node 
	{
		for(int i = 0 ; i< adj.size() ; i++) //for the node as the starting point 
		{
			for(int j = 0 ; j<adj.size() ; j++) // for the node as the ending point 
			{
				if(adj[i][k] != INT_MAX && adj[k][j] != INT_MAX)
				{
					adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
				}
			}
		}
	}
	//after getting the minimum distance of all the nodes with respect to the other node , we now find the number of nodes in its ieghbour 
	for(int row = 0 ; row < rows; row++)
	{
		int min_index = 0 ;
		int minimum_value = INT_MAX;
		int intermediate = 0;
		for(int column = 0 ; column < columns ; column++)
		{
			if(adj[row][column] <= threshold)
			{
				intermediate++;
			}
		}
		neighbours.push_back[row] = intermediate;
		if(minimum_value >= intermediate)
		{
			minimum_value = intermediate ;
			min_index = row;
		}
	}
	return min_index ;
}
