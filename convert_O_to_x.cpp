//convert_O_to_x.cpp

//in this question we have to convert the o's to x's which are surrounded by x from all the sides(4 directions)
//in order to do this we start with the o's whichare at the boundary , then look at the o's connected to it 
//they wont be changed 
#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

void convert_o(vector<vector<char>> &character_array , int rows , int columns)
{
	vector<vector<bool>> visited(rows , vector<bool>(columns , false));
	stack<pair<int , int>> s1 ;
	//we will push all the o's which are at the boundaries 
	for(int column = 0  ; column < columns ; column++)
	{
		if(character_array[0][column] == 'O')
		{
			s1.push({0,column});
			visited[0][column] = true;
		}

		if(character_array[rows-1][column] == 'O')
		{
			s1.push({rows-1 , column});
			visited[rows-1][column] = true;
		}
	}

	for(int row = 1 ; row<rows-1 ; row++)
	{
		if(character_array[row][0] == 'O')
		{
			s1.push({row , 0});
			visited[row][0] = true;
		}

		if(character_array[row][columns-1] == 'O')
		{
			s1.push({row , columns-1});
			visited[row][columns-1] = true;
		}
	}
	//now after getting the o's in the border we now want to get the connected o's

	while(!s1.empty())
	{
		//push the neighbours of the fornt 
		pair<int ,int> front_node = s1.top();
		int present_x = front_node.first;
		int present_y = front_node.second;

		s1.pop();

		if(present_x-1>=0 && !visited[present_x-1][present_y])
		{
			if(character_array[present_x-1][present_y] == 'O')
			{
				visited[present_x-1][present_y] = true;
				s1.push({present_x-1 , present_y});
			}
			else
			{
				visited[present_x-1][present_y] = true;
			}
		}

		if(present_x+1<rows && !visited[present_x+1][present_y])
		{
			if(character_array[present_x+1][present_y] == 'O')
			{
				visited[present_x+1][present_y] = true;
				s1.push({present_x+1 , present_y});
			}
			else
			{
				visited[present_x+1][present_y] = true;
			}
		}


		if(present_y-1>=0 && !visited[present_x][present_y-1])
		{
			if(character_array[present_x][present_y-1] == 'O')
			{
				visited[present_x][present_y-1] = true;
				s1.push({present_x , present_y-1});
			}
			else
			{
				visited[present_x][present_y-1] = true;
			}
		}


		if(present_y+1<columns && !visited[present_x][present_y+1])
		{
			if(character_array[present_x][present_y+1] == 'O')
			{
				visited[present_x][present_y+1] = true;
				s1.push({present_x , present_y+1});
			}
			else
			{
				visited[present_x][present_y+1] = true;
			}
		}

	}
	//after this step , you can convert all the o's which are not visited 
	for(int row = 0 ; row < rows ; row++)
	{
		for(int column = 0 ; column<columns ; column++)
		{
			if(character_array[row][column] == 'O' && !visited[row][column])
			{
				character_array[row][column] = 'X';
				visited[row][column] = true;
			}
		}
	}
}