//number_of_islands.cpp

//here we want to calculate the number of islands 
#include<iostream>
#include<vector>
#include<stack>
#include<utility>

using namespace std;

void number_of_islands(vector<vector<int>> adj)
{
	//here in the matrix , the positions where we have 0 is water , and the positions where there is 1 is land 
	//now we want to find the number of islands , islands are the lands surounded by the water 
	//lets created a visited matrix 

	stack<pair<int ,int>> s1 ;
	int number_islands = 0 ;
	vector<vector<bool>> visited(adj.size() , vector<bool>(adj[0].size() , false));
	int flag = 0 ;

	for(int row = 0 ; row < adj.size() ; row++)
	{	
		for(int column = 0 ; column < adj[0].size() ; column++)
		{
			if(adj[row][column] == 1 && visited[row][column] == false)
			{
				//we need to visit that node , and also its neighbours 
		
				
				s1.push(make_pair(row , column));

				while(!s1.empty())
				{
					flag = 1 ; //used for checking if the stack was initially empty and then populated 
					//need to push the neighbours into it ;
					 pair<int , int> front_coord = s1.top();
					 int row1 = front_coord.first;
					 int column1 = front_coord.second;

					 s1.pop();

					 visited[row1][column1] = true;

					for(int index = -1 ; index <=1 ; index++)
					{
						for(int index1 = -1 ; index1 <=1 ; index1++)
						{
							if(row1+index >=0 && row1+index <adj.size() && column1+index1 >=0 && column1+index1 <adj[0].size())
							{
								int final_row = row1+index;
								int final_column = column1+ index1;
								if(adj[final_row][final_column] == 1 && visited[final_row][final_column] == false)
								{
									s1.push(make_pair(final_row , final_column));
								}
							}
						}
					}
					//the above part pushes the neighbours into the stack 
				}

				if(flag == 1)
				{
					number_islands ++ ; //increase the number of islands 
					flag = 0 ;
				}


			}
		}
	}

	cout<<"THE NUMBER OF ISLANDS IS "<<number_islands<<endl;
}