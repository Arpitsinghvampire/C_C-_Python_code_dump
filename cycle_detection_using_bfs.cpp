//cycle_detection_using_bfs.cpp

//here we want to detect the cycles using the bfs traversal 
#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<map>
using namespace std;

void cycle_detection(vector<vector<int>> adj , int number_nodes) //here adj is the adjacency list
{
	vector<bool> visited(number_nodes , false);
	//if two nodes have the same child then we can say that the cycle is detected 
	//so lets start depthwise 
	//here each element of the adj contains the nodes , to which it is connected 
	//here by default 0 is the starting node 
	queue<pair<int , int>> s1 ; //first one tells the node , and the second one tells the parent 

	s1.push({0 , -1});

	//if one node  has two parents then cycle detected 
	while(!s1.empty())
	{
		pair<int , int> front_node = s1.front();
		int current_index = front_node.first;
		int parent_node = front_node.second;
		s1.pop();

		for(auto x: adj[current_index])
		{
			if(!visited[x])
			{
				visited[x] = true;
				s1.push({ x, current_index});
			}
			else if(x!= parent_node) //if i am able to reach a node from its parent and other way , then cycle exits 
			{
				cout<<"THE CYCLE EXISTS "<<endl;
			}
		}
		

		
	}
} 