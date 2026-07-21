//optimized_approach_nearest_1.cpp

#include<map>
#include<iostream>
#include<queue>
#include<utility>
#include<vector>

using namespace std;

vector<vector<int>> optimized_approach(vector<vector<int>> binary_matrix , int rows , int columns)
{
	//lets create a visited matrix 
	//we also need to do the queue
	queue<pair<int , pair<int,int>>> s1; //row , column , level
	vector<vector<bool>> visited(rows , vector<bool>(columns , false));
	vector<vector<int>> nearest_1(rows , vector<int>(columns , INT_MAX));

	for(int row = 0 ; row<rows ; row++)
	{
		for(int column =0 ; column <columns ; column++)
		{
			//search for the 1's
			if(binary_matrix[row][column] == 1)
			{
				s1.push({row , {column , 0}});
				nearest_1[row][column] = 0 ;
				visited[row][column] = true;
			}
		}
	}
	//now after getting the initial values of 1 we now focus on the positions where we do not have 1's
	while(!s1.empty())
	{
		pair<int , pair<int , int>> front_node = s1.front();
		s1.pop();
		int x_coor = front_node.first;
		int y_coor = front_node.second.first;
		int level = front_node.second.second;

		//now check for the neighbours 
		if(x_coor-1>=0 && binary_matrix[x_coor-1][y_coor] == 0 &&!visited[x_coor-1][y_coor])
		{
			s1.push({x_coor-1 , {y_coor , level+1}});
			nearest_1[x_coor-1][y_coor] = level+1; //bfs traversal is level wise 
			//that is all nodes of a certain distance from the 1's are travelled 
		}

		if(y_coor-1>=0 && binary_matrix[x_coor][y_coor-1] == 0 &&!visited[x_coor][y_coor-1])
		{
			s1.push({x_coor , {y_coor-1, level+1}});
			nearest_1[x_coor][y_coor-1] = level+1;
		}

		if(x_coor+1<rows && binary_matrix[x_coor+1][y_coor] == 0 &&!visited[x_coor+1][y_coor])
		{
			s1.push({x_coor+1 , {y_coor , level+1}});
			nearest_1[x_coor+1][y_coor] =level+1;
		}

		if(y_coor+1<columns && binary_matrix[x_coor][y_coor+1] == 0 &&!visited[x_coor][y_coor+1])
		{
			s1.push({x_coor , {y_coor+1 , level+1}});
			nearest_1[x_coor][y_coor+1] = level+1;
		}

	}
	return nearest_1;

}