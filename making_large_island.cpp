//making_large_island.cpp

//in this question we would be given a binary matrix with some connected ones , we need to find the max connected component we can get 
//after converting one zero to 1 
#include<iostream>
#include<queue>
#include<map>
#include<utility>
#include<stack>

using namespace std;

//returns the final parent and the size 

vector<pair<int , int>> find_neighbours(vector<vector<int>> &binary_matrix , pair<int , int> current_index)
{
	int x = current_index.first;
	int y = current_index.second;
	vector<pair<int , int>> result ;


	if(x>=1 && binary_matrix[x-1][y] == 1)
		result.push_back({x-1 , y});
	if(x+1 < binary_matrix.size() && binary_matrix[x+1][y] == 1)
	{
		result.push_back({x+1 , y});
	}

	if(y-1 >=0 && binary_matrix[x][y-1] == 1)
	{
		result.push_back({x , y-1});
	}

	if(y+1 < binary_matrix[0].size() && binary_matrix[x][y+1] == 1)
	{
		result.push_back({x , y+1});
	}

	return result ;

}

void union_operation(vector<vector<int>> &binary_matrix , vector<int>&parent , vector<int>& size1)
{
	for(int row =0 ; row< binary_matrix.size() ; row++)
	{
		for(int column = 0 ; column < binary_matrix[0].size() ; column++)
		{
			if(binary_matrix[row][column] == 1)
			{
				//check for the nighbours 
				int earlier_parent = parent[binary_matrix.size()* row + column];
				int size_taken = size1[binary_matrix.size()* row + column];
				vector<pair<int , int>> neighbours = find_neighbours(binary_matrix , {row , column});
				//we then need to get the maximum 
				for(int index = 0 ; index < neighbours.size() ;index++)
				{
					if(size1[parent[neighbours[index].first* binary_matrix.size() + neighbours[index].second]] > size_taken)
					{
						size_taken = size1[parent[neighbours[index].first* binary_matrix.size() + neighbours[index].second]];
						earlier_parent = parent[neighbours[index].first* binary_matrix.size() + neighbours[index].second];

					}
				}

				//we then set all the nodes to that parent and the size of the nodes 
				parent[row*binary_matrix.size() + column] = earlier_parent;
				int new_size = size1[row*binary_matrix.size() + column];
				for(int index = 0 ; index < neighbours.size() ; index++)
				{
					new_size += size1[parent[neighbours[index].first* binary_matrix.size() + neighbours[index].second]];
					parent[[neighbours[index].first* binary_matrix.size() + neighbours[index].second]] = earlier_parent;
				}
				size1[earlier_parent] = new_size;
			}
		}
	}
	//this does all the union operations
}


pair<int , pair<int , int>> connected_components(vector<vector<int>> &binary_matrix)
{
 // this part calculates all the 
	vector<int> parent;
	vector<int> size1(binary_matrix.size()* binary_matrix[0].size() , 1);
	for(int row = 0 ; row < binary_matrix.size() ; row++)
	{
		for(int column = 0 ; column <binary_matrix[0].size() ; column++)
		{
			parent.push_back(row* binary_matrix[0].size() + column); //all are the parents of themselves initially 
		}
	}

	//now after getting the parents , we now need to 
	//now we would perform the union operation 
	union_operation(binary_matrix , vector<int> &parent , vector<int> &size1);

	//so we would have the parent and the size .
	//now we would need to look at the elemeents and go over all the 0's
	int max_size = 0 ;
	pair<int ,int> required_coordinate({0,0});
	vector<bool> visited(binary_matrix.size()* binary_matrix[0].size() , false);
	for(int row = 0 ; row < binary_matrix.size() ; row++)
	{
		for(int column = 0 ; column < binary_matrix[0].size() ; column++)
		{
			if(binary_matrix[row][column] == 1)
				continue ;

			else
			{
				//get the neighbours 
				int intermediate_size = 1 ;
				vector<pair<int , int>> neighbours = get_neighbours(binary_matrix , {row , column});
				//after getting the neighours , we need to add the size of the parent of that node  but if they are from the same group dont add twice 
				for(int index = 0 ; index < neighbours.size() ; index++)
				{
					if(!visited[parent[neighbours[index].first*binary_matrix.size()+neighbours[index].second]])
					{
						intermediate_size += size1[parent[neighbours[index].first*binary_matrix.size()+neighbours[index].second]];
						//then we visit that component 
						visited[parent[neighbours[index].first*binary_matrix.size()+neighbours[index].second]] = true;
					}
					
				}
				if(intermediate_size > max_size)
				{
					required_coordinate = {row , column};
					max_size = intermediate_size;
				}

			}
		}
	}
	return {max_size , {required_coordinate.first , required_coordinate.second}};

}