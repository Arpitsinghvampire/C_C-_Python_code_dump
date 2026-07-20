//number_of_provinces.cpp

//in this question we willbe given a graph , we have to find the number of provinces 
//two nodes are in the same province , if we are able to reach from one province to another 
#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;

void number_of_provinces(vector<vector<int>> adj , int starting_node , int number_nodes) //here adj is the adjacency list 
{
	//in order to get the nodes in a province , we will use the depth first traversal 
	map<int , bool> visited ;

	int province = 0 ;


	for(int index = 0 ; index < number_nodes ; index++)
	{
		visited[index] = false;
	}
	visited[starting_node] = true;
	stack<int> yet_visited ;

	yet_visited.push(starting_node);
	province += 1;
	while(!yet_visited.empty())
	{
		int front_node = yet_visited.top();

		yet_visited.pop();
		vector<int> children_nodes = adj[front_node];

		for(int index = 0 ; index < children_nodes.size() ; index++)
		{
			if(!visited[children_nodes[index]])
			{
				visited[children_nodes[index]] = true;
				yet_visited.push(children_nodes[index]);
			}
		}
	}
	//now after getting the initial province  , we now check for the unvisited ones and do the same 
	//search for the nodes , which have not yet been traversed and then traverse them  , and then visit them 
	for(int index = 0 ; index < number_nodes; index++)
	{
		if(visited[index] == false)
		{
			//then look for the children and then traverse them 
			yet_visited.push(index);
			province += 1;
			while(!yet_visited.empty())
			{				
				int front_node = yet_visited.top();

				yet_visited.pop();
				vector<int> children_nodes = adj[front_node];

				for(int index = 0 ; index < children_nodes.size() ; index++)
				{
					if(!visited[children_nodes[index]])
					{		
						visited[children_nodes[index]] = true;
						yet_visited.push(children_nodes[index]);
					}	
				}		
			}

		}
	}
}