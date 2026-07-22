//number_of_enclaves.cpp

//here in this question we would be given a binary matrix , we want to find the number of land cells , through which we cannot move to the boundary 
//so this question is basically the converse of the previous question convert_O_to_x.cpp
//in the previous question we found the O's which are on the boundary  , and then connected all the O's connected to it 
//here if the 1's are surrounded by the 0's then we wont be able to move to the boundary , so we start with the 
//1's that are on the boundary and then we connect other 1's which can lead to the boundary 
#include<iostream>
#include<stack>
#include<map>
#include<pair>
#include<vector>

using namespace std;

void enclaves(vector<vector<int>> binary_matrix , int rows , int columns)
{
	vector<vector<bool>> visited(rows , vector<bool>(columns , false));
	stack<pair<int , int>> s1;

	//first take the ones which are in the boundary 
	for(int column = 0 ; column < columns ; column++)
	{
		if(binary_matrix[0][column] == 1)
		{
			visited[0][column] = true;
			s1.push({0,column});
		}

		if(binary_matrix[rows-1][column] ==1)
		{
			visited[rows-1][column] = true;
			s1.push({rows-1 , column});
		}
	}

	for(int row = 1 ; row < rows-1 ; row++)
	{
		if(binary_matrix[row][0] == 1)
		{
			visited[row][0] = true;
			s1.push({row , 0});
		}

		if(binary_matrix[row][columns-1] == 1)
		{
			visited[row][columns-1] = true;
			s1.push({row , columns-1});
		}
	}

	//now after getting the boundary 1's we now connect the 1's that are connected to these boundary 1's

	while(!s1.empty())
	{
		pair<int , int> front_node = s1.top();

		int present_x = front_node.first;
		int present_y = front_node.second ;

		s1.pop();

		//now push the neighbourhood 
		if(present_x-1 >=0 && !visited[present_x-1][present_y])
		{
			if(binary_matrix[present_x-1][present_y] == 1)
			{
				s1.push({present_x-1 ,present_y});
				visited[present_x-1][present_y] = true;
			}
			else
			{
				visited[present_x-1][present_y] = true;
			}
		}


		if(present_x+1 <rows && !visited[present_x+1][present_y])
		{
			if(binary_matrix[present_x+1][present_y] == 1)
			{
				s1.push({present_x+1 ,present_y});
				visited[present_x+1][present_y] = true;
			}
			else
			{
				visited[present_x+1][present_y] = true;
			}
		}

		if(present_y-1 >=0 && !visited[present_x][present_y-1])
		{
			if(binary_matrix[present_x][present_y-1] == 1)
			{
				s1.push({present_x ,present_y-1});
				visited[present_x][present_y-1] = true;
			}
			else
			{
				visited[present_x][present_y-1] = true;
			}
		}

		if(present_y+1<columns && !visited[present_x][present_y+1])
		{
			if(binary_matrix[present_x][present_y+1] == 1)
			{
				s1.push({present_x ,present_y+1});
				visited[present_x][present_y+1] = true;
			}
			else
			{
				visited[present_x][present_y+1] = true;
			}
		}
	}
	int lands = 0 ;
	//now we scan for those 1's which have not been visited since they ar enot connected to the boundary 1's
	for(int row = 0 ; row < rows ; row++)
	{
		for(int column = 0 ; column < columns ; column++)
		{
			if(binary_matrix[row][column] == 1 && !visited[row][column])
				lands++;
		}
	}

	cout<<"WE CANNOT REACH THE BOUNDARY FROM "<<lands<< "LANDS"<<endl;
}