//graph_input.cpp

//in this code block we try to take input the edges of the graph 
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n,m;
	cin>>n;
	cin>>m;

	vector<vector<int>> adj(n , vector<int>(m , 0));

	for(int index = 0 ; index < m ; index++)
	{
		int node1 , node2 ;

		cin>>node1>>node2;

		//then change the edges 
		adj[node1][node2] = 1;
		adj[node2][node1] = 1;

	}
}