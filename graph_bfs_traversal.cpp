//graph_bfs_traversal.cpp

//in this code base lets try the breadth first search traversal 
#include<iostream>
#include<vector>
#include<map>

using namespace std;

void breadth_first_graph(vector<vector<int>> adj , int starting_node) //here adj is the adjacency list 
{
	map<int , bool> visited ;

	//now we explore all the other elements in the queue
	queue<int> yet_to_be_visited ;
	yet_to_be_visited.push(starting_node);


	vector<int> breadth_first_search ;
	while(!yet_to_be_visited.empty())
	{
		int front_node = yet_to_be_visited.front();
		visited[front_node] = true;
		yet_to_be_visited.pop();

		breadth_first_search.push_back(front_node);

		for(int index = 0 ; index < adj[front_node].size() ; index++)

		{
			if(!visited(adj[front_node][index]))
				yet_to_be_visited.push(adj[front_node][index]);
		}
	}

	//then lets print the breadth first graph traversal 
	for(int x : breadth_first_search)
	{
		cout<<x<<endl;
	}



}

int main()
{

}
