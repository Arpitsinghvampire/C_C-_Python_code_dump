//topological_sort_kahns_algorithm.cpp

//in this code , we try to get the topological sort using the kahns algorithm  , which uses the idea of indegree
#include<iostream>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

vector<int> get_indegree(vector<vector<int>> adj)
{
	//if there is an edge to that node , basically that contributes to the indegree
	vector<int> indegree(adj.size() , 0);
	for(int index = 0 ; index < adj.size() ; index++)
	{
		for(int index1 = 0 ; index1 < adj[index].size() ; index1++)
		{
			indegree[adj[index][index1]] ++;
		}
	}

	return indegree;
}


void kahns_algorithm(vector<vector<int>> adj)
{
	//now we push into the stack the elements with the indegree 0 ;

	queue<int> s1;
	
	vector<int> indegree_node = get_indegree(adj);

	vector<bool> into_stack(adj.size() , false) ;
	//now lets look into the nodes which have indegree 0 
	for(int index = 0 ; index < adj.size() ; index++)
	{
		if(indegree_node[index] == 0)
		{
			s1.push(index);
			into_stack[index] = true;
		}
	}

	//after this we will get all the nodes which have indegree of 0 into the stack 
	vector<int> answer ;

	while(!s1.empty())
	{
		//we would need to get the connections to the node , and then subtract the indegrees of the corresponding node by 1 
		int front_node = s1.front();
		answer.push_back(front_node);
		s1.pop();

		//now subtract all the edges from that node 
		for(int index = 0 ; index < adj[front_node].size() ; index++)
		{
				indegree_node[adj[front_node][index]] --;

				if(indegree_node[adj[front_node][index]] == 0 && !into_stack[adj[front_node][index]])
				{
					into_stack[adj[front_node][index]]= true;
					s1.push(adj[front_node][index]);
				}
		}

	}

	//now i think we just need to return the vector and all our work is done 

	return answer;

}
