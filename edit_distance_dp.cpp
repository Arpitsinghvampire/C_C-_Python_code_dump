//edit_distance_dp.cpp

//in this code , we can either remove a character , update a character or insert a character , 
//we need to find min number of such operations 
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void edit_distance(vector<vector<int>> &dp , string s1 , string s2) //s1 string is fixed all operations on only string s2 
{
	for(int row = 0 ; row<s1.size() ; row++)
	{
		dp[row][0] = 0 ;
	}

	for(int column = 0 ; column < s2.size() ; column++)
	{
		dp[0][column] = 0 ;
	}

	for(int row = 1 ; row<=s1.size() ; row++)
	{
		for(int column = 1 ; column <= s2.size() ; column++)
		{
			if(s1[row-1] == s2[column-1])
			{
				dp[i][j] = dp[i-1][j-1]; // , we wont need to change the common element 
			}
			else
			{
				// we need to find the min among the replace , insert and delete operation 
				//if you  insert  , then the last element will become equal 
				int insert_element  = 1+ dp[row-1][column]; //the last element is taken to be same , so you only take elements in string s2 till the previous column
				int delete_element  = 1 + dp[row][column-1] ; // we delete from the column side 
				int  replace_element = 1+ dp[row-1][column-1];

				dp[row][column] = min(insert_element , delete_element , replace_element);
			}
		}
	}
}