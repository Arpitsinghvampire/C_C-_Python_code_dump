//directed_cyclic_graph.cpp

//here we want to find the cyclicity in a directed graph 
//in the directed graph, the nodes would be in the cyclic graph , if they lie on the same path 
#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

bool directed_cyclic(vector<vector<int>> &adj , vector<bool> &visited , vector<bool> &path_visited , int index)
{
	//visited tells us whether the node is visited or not 
	//path visited tells us whether it is visited on the same path or not 
	//here adj is the adjacency list 
	visited[index] = true;
	path_visited[index] = true;

	for(int index1 = index ; index1 < adj.size() ; index1++)
	{
		//either that index can be visited or it might not be visited 
		if(visited[index1])
		{
			//run dfs for that index , if the index returns true then the cycle exists 
			if(dfs(adj , visited , path_visited , index1))
				return true ;

			else if(path_visited[index1])
				return true;
		}
	}
	
	//when we retrace back , we want path visited to be false , because it wont be on the same path 
	path_visited[index] = false;
	return false;
}