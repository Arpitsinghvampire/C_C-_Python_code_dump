//bipartite_graph.cpp

//here want to check whether the graph is bipartite or not , 
//bipartite means that the graph is 2 colourable , that is you can cover the whole graph using 2 colors
//an odd cycle graph cannot be a bipartite graph  , hence we can say that if there is odd cycle then it cannot be bipartite 
#include<iostream>
#include<queue>
#include<map>
#include<set>
using namespace std;

void bipartite_graph(vector<vector<int> adj) //here we are given the adjacency list 
{
	//for checking the bipartiteness ,we will use the bfs traversal 
	//here initially the nodes are uncolored with color -1 , we then need to put the colors 0 or 1 
	//initially all nodes are uncolored 
	vector<int> colors(adj.size() , -1);

	queue<int> s1;
	s1.push(0);
	colors[0] = 0 ;
	int flag =1 ;

	while(!s1.empty() && flag)
	{
		int front_node = s1.front();
		s1.pop();

		//we then put its neighbours 
		vector<int> neighbours(adj[front_node]);
		//color the neighbours with the same color and then put them into the queue
		
		for(int index = 0 ; index < neighbours.size() ; index++)
		{
			if(colors[neighbours[index]] == -1)
			{
				//initially uncolored , we then need to provide the complementary color of the parent 
				if(colors[front_node] == 0)
				{
					colors[neighbours[index]] = 1;
					s1.push(neighbours[index]);
				}
				else if(colors[front_node] == 1)
				{
					colors[neighbourhood[index]] = 0 ;
					s1.push(neighbours[index]);
				}
			}
			else
			{
				//now if the neighbourhood is already covered , then check whether the color of the node and the parent is 
				//same or not . If it is same , then not two colorable , two adjacent nodes have the same color
				if(colors[front_node] == colors[neighbourhood[index]])
				{
					cout<<"NOT TWO COLORABLE , ADJACENT NODES HAVE THE SAME COLOR , HENCE NOT BIPARTITE "<<endl;
					flag = 0 ;
					break;
				}
				
			}
		}
	}
	
}
