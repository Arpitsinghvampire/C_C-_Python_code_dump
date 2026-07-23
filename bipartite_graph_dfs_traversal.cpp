//bipartite_graph_dfs_traversal.cpp

//here we  will find whether the graph is bipartite or not  ,using the dfs traversal 
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<utility>

using namespace std;

void bipartite_graph(vector<vector<int>> adj)//here we are given the adjacency list for the graph
{
	vector<int> colors(adj.size() , -1);
	stack<int> s1;

	s1.push(0);
	colors[0] = 1;

	while(!s1.empty())
	{
		int front_node = s1.top();
		s1.pop();

		//now we want to see the neighbours and then push them into the stack 
		vector<int> neighbours(adj[front_node]);

		for(int index = 0 ; index < neighbours.size() ; index++)
		{
			if(colors[neighbours[index]] == -1)
			{
				//then color it complementary to the parent 
				if(colors[front_node] == 0)
				{
					s1.push(neighbours[index]);
					colors[neighbours[index]] = 1;
				}
				else if(colors[front_node] == 1)
				{
					s1.push(neighbours[index]);
					colors[neighbours[index]] = 0;
				}
			}
			else
			{
				//if the node is already covered , then you need to check whether the color is same as that of node being popped or not 
				if(colors[front_node] == colors[neighbours[index]])
				{
					cout<<"NOT A BIPARTITE GRAPH"<<endl;
					break;
				}
					
			}
		}
	}
}