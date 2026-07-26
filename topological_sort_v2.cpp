//topological_sort_v2.cpp

//here we want to have a  topological sort algorithm  
#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

void dfs(int index , vector<int> &visited , stack<int> &st , vector<vector<int>> adj)
{
	visited[index] = 1;

	for(int value : adj[index]){
		if(!visited[value])
		dfs(value , visited , st , adj)
	}
	st.push(index);
}

vector<int> topological_sort(int v , vector<int> adj)
{
	vector<int> visited(adj.size(),0);

	stack<int> st;

	for(int i = 0 ; i< v; i++)
	{
		if(!visited[i])
		{
			dfs(i , vis , st , adj);
		}
	}

	vector<int> ans;

	while(!st.empty())
	{
		int front_node = st.top();
		ans.push_back(front_node);
		st.pop();
	}

	return ans ;
}