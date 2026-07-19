//graph_dfs_traversal.cpp

//in this code block we will talk about the depth first traversal 
#include<iostream>
#include<vector>
#include<map>

using namespace std;

void depth_traversal(vector<vector<int>> adj , int starting_node)
{
	//here in place of the queue , we will use the stack data structure 
	stack<int> traversal ;
	map<int , bool> visited ;

	

	traversal.push(starting_node);

	vector<int> traversal_vector ;

	while(!traversal.empty())
	{
		int front_node = traversal.top();

		traversal_vector.push_back(front_node);

		visted[front_node]= true;
		traversal.pop();

		for(int index = 0  ; index < adj[front_node][index] ; index++)
		{
		 	if(!visited(adj[front_node][index]))
		 	{
		 		traversal.push(ad[front_node][index]);
		 	}
		}
	}

	for(int x : traversal_vector)
	{
		cout<<x<<endl;
	}


}

