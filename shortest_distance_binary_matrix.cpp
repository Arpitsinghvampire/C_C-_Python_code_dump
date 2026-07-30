//shortest_distance_binary_matrix.cpp

/*
in this question we would be given a binary matrix  , and we want to find the minimum distance from the initial node to the final node 
you can only traverse if the element is 1 , if 0 is there then you cannot traverse 
*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

/* this question is similar to the previous question we had on the vocab list  , here we also add teh pairs into the vector list , until
we get our final node*/

//we create a function that generates all the valid neighbours 
vector<pair<int,int>> valid_neighbours(vector<vector<int>> &binary_matrix , pair<int ,int> current_node)
{
	vector<pair<int , int>> result ;
	int present_x = current_node.first;
	int present_y = current_node.second;

	if(present_x-1>=0 && binary_matrix[present_x-1][present_y] == 1)
	{
		result.push_back({present_x-1 , present_y});
	}

	if(present_x+1 < binary_matrix.size() && binary_matrix[present_x+1][present_y] == 1)
	{
		result.push_back({present_x+1 , present_y});
	}

	if(present_y-1>=0 && binary_matrix[present_x][present_y-1] == 1)
	{
		result.push_back({present_x , present_y-1});
	}

	if(present_y+1 < binary_matrix[0].size() && binary_matrix[present_x][present_y+1] == 1)
	{
		result.push_back({present_x , present_y+1});
	}

	return result;

}

int shortest_distance(vector<vector<int>> &binary_matrix , pair<int , int> starting_node , pair<int , int > final_node)
{
	//start from the final node , and then add them to the queue
	queue<pair<pair<int , int>,int>>  q1;
	vector<vector<int>> path_length(binary_matrix.size() , vector<int>(binary_matrix[0].size() , INT_MAX);

	path_length[starting_node.first][starting_node.second] = 0;

    if(binary_matrix[starting_node.first][starting_node.second] == 0)
    {
    	//then we cant traverse the list 
    	return path_length[final_node.first][final_node.second];
    }
    q1.push({{starting_node.first ,starting_node.second} , 0});
    //this is at the zero level 

    //now we move breadth wise and then update the path length for the node 
    while(!q1.empty())
    {
    	pair<pair<int , int> , int> front_node = q1.front();
    	int parent_x = front_node.first.first;
    	int parent_y = front_node.first.second;

    	int parent_level = front_node.second;
    	q1.pop();

    	if(parent_x == final_node.first && parent_y == final_node.second)
    		break;
    	//we now get the neighbours of the parent 
    	vector<pair<int , int>> neighbours = valid_neighbours(binary_matrix , {parent_x , parent_y});

    	//now we scan the neighbours 
    	for(int index = 0 ; index < neighbours.size() ; index++)
    	{
    		pair<int , int> current_node = neighbours[index];
    		if(path_length[current_node.first][current_node.second] < parent_level+1)
    			continue;
    		path_length[current_node.first][current_node.second] = parent_level+1;
    		q1.push({{current_node.first , current_node.second} , parent_level+1});
    	}
    }

    return path_length[final_node.first][final_node.second];
}

