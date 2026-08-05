//most_stones_removed.cpp

//here in this question we are given some stones , but they can only be removed if there are other sotnes in the sme row or the same column 
//we want to find the number of stones we can remove 
//so basically we can remove all except one in each connected component 
#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

int connected_component(vector<vector<int>> coordinates)
{
	//this contains the coordinates where the stone is located 
	//this function will return us the parent and the size of the connected component 
	vector<int> size1(coordinates.size() , 1);
	vector<in> parent;
	vector<int> previous_x;
	vector<int> previous_y ;
	for(int index = 0 ; index < coordinates.size() ; index++)
	{
		parent.push_back(index);
	}

	//now we check for the same columns or the same row 
	for(int index = 0 ; index < coordinates.size() ; index++)
	{
		if(previous_x.size() == 0)
		{
			//we then add the x cooordinate to the previous x and the y coordinate to the previous y 
			previous_x.push_back(coordinates[index][0]);
			previous_y.push_back(cooordinates[index][1]);
		}
		else
		{
			//whenever you get a new instance , check if the row or column matches the previous coordinates 
			for(int index1 = 0 ; index1 < previous_x.size() ; index1++)
			{
				if(previous_x[index1] == coordinates[index][0])
				{
					//the parent is the same for both 
					parent[index] = parent[index1];
					size1[index1] += 1;
					break;
				}
				else if(previous_y[index1] == coordinates[index][1])
				{
					parent[index] = parent[index1];
					size1[index1] +=1 ;
					break;
				}
				//if no match is there then dont do anything 
			}
		}
	}
	//from here we would get the parents and their sizes , that isfor each unique parent 
	int max_stones = 0 ;
	set<int> set1(parent.begin() , parent.end());
	vector<int> vec1(set1.begin() , set1.end());
	for(int index = 0 ; index < vec1.size() ; index++)
	{
		max_stones += size1[vec1[index]];
	}

	return max_stones ;
}