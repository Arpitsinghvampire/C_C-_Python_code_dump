//distance_of_nearest_cell_having_1.cpp

//here we want to get the distance of the nearest 1 
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<utility>

using namespace std;

void nearest_cell(vector<vector<in>> binary_matrix , int rows , int columns)
{
	vector<vector<bool>> visited(rows , vector<int>(columns , false));

	vector<vector<int>> nearest_1(rows , vector<int>(columns , 0));

	//we start with the first node 
	queue<pair<int ,pair<int , int>>> s1; //row , column , level 


	for(int row = 0 ; row<rows ; row++)
	{
		for(int column = 0 ; column < columns ; column++)
		{
			if(binary_matrix[row][column] == 1)
			{
				visited[row][column] = true;
				nearest_1[row][column] = 0 ;
			}
			else
			{
				//look at the surroundings 
				s1.push({row,{column , 0}});
				visited[row][column] = true;

				while(!s1.empty())
				{
					pair<int , pair<int , int>> front_node= s1.front();
					int present_row = front_node.first;
					int present_column = front_node.second;
					int present_level = front_node.second.second ;

					//now we pop 
					s1.pop();

					if(present_row-1>=0)
					{
						if(binary_matrix[present_row-1][present_column] != 1)
						{
							s1.push({present_row-1,{present_column ,present_level+1}});
							visited[present_row-1][present-column] = true;
						}
						else
						{
							//empty the elements of the 
							while(!s1.empty())
								s1.pop();
							nearest_1[row][column] = present_level+1;
						}
					}


					if(present_column-1>=0)
					{
						if(binary_matrix[present_row][present_column-1] != 1)
						{
							s1.push({present_row,{present_column-1,present_level+1}});
							visited[present_row][present_column-1] = true;
						}
						else
						{
							//empty the elements of the 
							while(!s1.empty())
								s1.pop();
							nearest_1[row][column] = present_level+1;
						}
					}

					if(present_row+1< rows)
					{
						if(binary_matrix[present_row+1][present_column] != 1)
						{
							s1.push({present_row+1,{present_column ,present_level+1}});
							visited[present_row+1][present_column] = true;
						}
						else
						{
							//empty the elements of the 
							while(!s1.empty())
								s1.pop();
							nearest_1[row][column] = present_level+1;
						}
					}


					if(present_column+1< columns)
					{
						if(binary_matrix[present_row][present_column+1] != 1)
						{
							s1.push({present_row,{present_column+1 ,present_level+1}});
							visited[present_row][presen_column+1] = true;
						}
						else
						{
							//empty the elements of the 
							while(!s1.empty())
								s1.pop();
							nearest_1[row][column] = present_level+1;
						}
					}
				}


			}
		}
	}

}