//fill_color_graph.cpp

//here we want to change the color of the adjacent  nodes , with the new color 
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<utility>
#include<map>
#include<queue>

using namespace std;

void graph_fill(vector<vector<int>> adj , string new_color  ,string old_color , pair<int,int> starting_node)
{
	//in this question ,we want to change the color of 
	//the neighbouring nodes and their neighbouring nodes 
	queue<pair<int,int>> s1; //here we will use the breadth first search 

	map<pair<int,int> , string> color_nodes;

	vector<pair<int,int> , bool> visited(adj.size() , vector<bool>(adj[0].size(), false));
	for(int index = 0 ; index< adj.size() ; index++)
	{
		for(int index1 = 0 ; index1 < adj[0].size() ; index1++)
		{
			color_nodes[make_pair(index , index1)] = old_color;
		}
	} 

	s1.push(starting_node);

	while(!s1.empty())
	{
		pair<int , int> front_node = s1.front();
		int front_node_x = front_node.first;
		int front_node_y = front_node.second;

		visited[front_node] = true;

		color_nodes[make_pair(front_node_x , front_node_y)] = new_color;
		s1.pop();

		//we now want to insert the neighbours into the queue and then change the colors 
		if(front_node_x-1 >=0 && !visited[make_pair(front_node_x-1 ,front_node_y)]
		 && color_nodes[make_pair(front_node_x-1 ,front_node_y)] == old_color)
			s1.push(make_pair(front_node_x-1 ,front_node_y));
		if(front_node_x+1 <adj.size()  && !visited[make_pair(front_node_x+1 ,front_node_y)]
			&&color_nodes[make_pair(front_node_x+1 ,front_node_y)] == old_color)
			s1.push(make_pair(front_node_x+1 , front_node_y));

		if(front_node_y-1>=0 && !visited[make_pair(front_node_x ,front_node_y-1)]
			&& color_nodes[make_pair(front_node_x ,front_node_y-1)] == old_color)
			s1.push(make_pair(front_node_x , front_node_y-1));

		if(front_node_y+1 < adj.size()  && !visited[make_pair(front_node_x ,front_node_y+1)]
			&& color_nodes[make_pair(front_node_x ,front_node_y+1)] == old_color)
			s1.push(make_pair(front_node_x , front_node_y+1));

	}

}