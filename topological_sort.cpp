//topological_sort.cpp
// here we will try to find the topological sort for a directed acyclic graph 
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs(int node,
         vector<vector<int>>& adj,
         vector<bool>& visited,
         stack<int>& st)
{
    visited[node] = true;

    for(int neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            dfs(neighbour, adj, visited, st);
        }
    }

    st.push(node);
}


void top_sort(vector<vector<int>> &adj ,int number_nodes)
{
	vector<bool> visited(number_nodes , false);

	stack<int> st;

	for(int index = 0 ; index < number_nodes ; index++)
	{
		if(!visited[index])
		{
			dfs(index , adj , visited , st);
		}
	}

	cout<<"THE TOPOLOGICAL SORTING ORDER IS "<<endl;
	vector<int> rev_ans ;
	while(!st.empty())
	{
		cout<st.top()<<endl;
		st.pop();
	}

	
}