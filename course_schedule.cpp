//course_schedule.cpp

//in this code block we have been given some courses and pre requisites , we want to know whether we can take all the courses 
//this is basically the previous code , if there is a cyclic dependency then you wont be able to complete all the courses 
//this course prerequisite is bascially a dag(a topological sort works in dag)
//if the toppological sort does not exist then then the cycle is there , and hence you cant finish the course
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> indegree_nodes(vector<vector<int>> adj)
{
	vector<int> indegree_node(adj.size() , 0);

	for(int index = 0 ; index < adj.size() ; index++)
	{
		for(int index1 = 0  ; index1 < adj[index].size() ; index1++)
		{
			indegree_nodes[adj[index][index1]] ++ ;
		}
	}
	return indegree_node;
}

bool kahns_algorithm(vector<vector<int>> adj)
{
	queue<int> s1;

	vector<int> indegree_node = indegree_nodes(adj);
	vector<bool> visited(adj.size() , false);
	for(int index = 0 ; index < adj.size() ; index++)
	{
		if(indegree_node[index] == 0)
		{
			s1.push(index);
			visited[index] = true;
		}
	}

	//now after getting the intial nodes , which have indegree of 0 , lets get the nodes to which they are connected
	int count = 0 ;
	while(!s1.empty())	
	{	
		int front_node = s1.front();
		count ++ ;
		s1.pop();

		for(int index = 0 ; index < adj[front_node].size(); index++)
		{
			indegree_node[adj[front_node][index]] -- ;

			if(indegree_node[adj[front_node][index]] == 0 && !visited[adj[front_node][index]])
			{
				s1.push_back(adj[front_node][index]);
				visited[adj[front_node][index]] = true;
			}
		}
	}

	if(count == adj.size())
		return false;
	return true;
	//if they are equal then cycle does not exist , if they are not equal then cycle exists 
	
}
