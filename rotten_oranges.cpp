//rotten_oranges.cpp

//in this code block , we would be given some rotten oranges , we want to know when the oranges will rot 
#include<iostream>
#include<map>
#include<utility>
#include<queue>
#include<vector>

using namespace std;

void rotten_oranges(vector<vector<int>> &graph , int rows , int columns)
{
	//2 means we that position has a rotten orange 
	//1 means okay orange 
	//0 means no orange is there in that position 
	//so basically all the oranges neighbourhood of the rotten orange will rot first 
	//so this is a kind of  breadth first traversal 
	int time_taken = 0 ;
	queue<pair<int, pair<int , int >>> s1;
	for(int row = 0 ; row < rows ; row++)
	{
		for(int column = 0 ; column < columns ; column++)
		{
			if(graph[row][column] == 2)
			{
				s1.push({row ,{column , time_taken}});
				
			}

			
		}
	}

	
	//so we get the initial  rotten oranges 

	while(!s1.empty())
	{
		pair<int, pair<int,int>> front_node  = s1.front();
		int x_coor = front_node.first;
		int y_coor = front_node.second.first;
		int time_taken_parent = front_node.second.second;
		time_taken = time_taken_parent;
		//now we need to change the visited status 
		
		graph[x_coor][y_coor] = 2;
		s1.pop();

		//now we push the neighbours 
		//we then need to push the elements into the queue
			if(x_coor-1 >=0 && graph[x_coor-1][y_coor] == 1 )
			{
			
					s1.push({x_coor-1,{y_coor, time_taken_parent+1}});
			}
				if(y_coor-1 >=0 && graph[x_coor][y_coor-1] == 1)
				{
				
					s1.push({x_coor , {y_coor-1 , time_taken_parent+1}});
				}
				if(y_coor+1 <columns && graph[x_coor][y_coor+1] == 1)
				{
					
					s1.push({x_coor , {y_coor+1 , time_taken_parent+1}});
				}

				if(x_coor+1 < rows && graph[x_coor+1][y_coor] == 1)
				{
				

					s1.push({x_coor+1 , {y_coor , time_taken_parent+1}});
				}

	}

	cout<<"THE TIME TAKEN TO  ROT THE ENTIRE ORANGE IS "<<time_taken<<endl;


}