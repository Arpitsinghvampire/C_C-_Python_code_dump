//cheapest_node_k_stops.cpp

//here we have to find the cheapest way to travel , we would be given some number of stops  , and we have to reach the destination in the least cost possible
#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<climits>

using namespace std;

int  cheapest_node(vector<vector<pair<int , int>>> &adj , int steps1)
{	
	priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
	vector<int> path_length(adj.size() , INT_MAX);
	//(distance ,(node , stop));
	//the source node is always the first node that is the index node 
	pq.push({0,{0 , 0}});
	while(!pq.empty())
	{
		//get the front_node 
		pair<int , pair<int , int>> front_node = pq.top();
		//get the attributes from the dataset 
		int price = front_node.first;
		int  present_node = front_node.first.second;
		int steps = front_node.second.second;
		pq.pop();

		if(present_node == adj.size()-1 && steps <= steps1)
		{
			return price ;
		}
		//else we would need to find the neighbours and then do that 
		for(int index = 0 ; index< adj[present_node].size() ; index++)
		{
			//if the steps is equal to steps1 then you cant get to the node 
			if(steps >= steps1)
			{
				//then we cant push anything into the stack 
				continue;
			}
			else
			{
				//we need to unpack the elements in that idnex 
				pair<int , int> node = adj[present_node][index];
				if(path_length[node.first] > price + node.second)
				{
					path_length[node.first] = price+node.second;
					pq.push({price+node.second , {node.first , steps+1}});
				}

			}

		}
	}
	return -1;
}