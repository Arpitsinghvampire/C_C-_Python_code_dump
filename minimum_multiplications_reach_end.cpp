//minimum_multiplications_reach_end.cpp

//in this code block we would be given an initial number  , we owuld be given some set of numbers 
//we would be given an end number , we want to get the number of minimum multiplications to reach that number 
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
#include<map>
using namespace std;

vector<int> get_neighbours(vector<int> &list_numbers , int  current_number)
{
	vector<int> result ;
	for(int index = 0 ; index < list_numbers.size() ; index++)
	{
		result.push_back((current_number*list_numbers[index])%100000);
	}
	return result;
}

int min_multiplications(vector<int> &list_numbers , int initial_number , int final_number)
{

	vector<int> distance(100000 , INT_MAX);
	distance[0] = 0 ;
	if(initial_number== final_number)
	{
		return 0 ;
	}
	//we need the nuber of operations , the resultant product 
	priority_queue<pair<int, long long>,vector<pair<int, long long>>,greater<pair<int, long long>>> pq;

	pq.push({0 , initial_number});

	while(!pq.empty())
	{
		pair<int , long long> front_node = pq.top();
		int number_operations = front_node.first;
		long long  resultant_product = front_node.second;
		pq.pop();
		if(resultant_product == final_number)
		{
			return number_operations;
		}
		//else we need to get the noieghbours and then push into the priority queue
		vector<int> neighbour = get_neighbours(list_numbers , resultant_product);
		for(int index = 0 ; index < neighbour.size(); index++)
		{
			if(distance[neighbour[index]] > number_operations+1])
			{
				distance[neighbour[index]] = number_operations+1;
				pq.push({number_operations+1 , neighbour[index]});
			}
			
		}
	}
	return -1;

}