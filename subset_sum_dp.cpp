//subset_sum_dp.cpp

//in this code , we have to get whether there exists a sequence of numbers whose target is equal to a number or not 
#include<iostream>
#include<vector>
using namespace std;

void subset_sum(vector<int> &s1 , int target , vector<vector<bool>> &dp , int rows , int columns )
{
	//the dp here is a boolean vector<vector>> it will have the target number of columns and the number of
	//rows as  size of s1
	//basically using only that index , are we able to get the target or not 
	//bascially we fill the first row 
	for(int index = 0 ; index < columns+1 ; index++)
	{
		if(index == 0)
			dp[0][index] = true;
		else if(s1[0] != index)
			dp[0][index] = false;
		else
			dp[0][index] = true;
	}

	for(int row = 1 ; row<s1.size() ; row++)
	{
		dp[row][0] = true;
	}
	//so we have filled the first row , we now want to fill the second row and so on 
	//this means whether we are able to  get to the target using the following  indices from 1 to index 
	for(int index = 1 , index < rows+1 ; index++)
	{
		for(int index1 = 1 ; index1 < columns+1 ; index1++)
		{
			bool  take = false
			if(s[index] <= target)
				take = dp[index-1][target-s[index]];
			dp[index][index1] = dp[index-1][index1] ||take ;
		}
	}

	return dp[rows-1][target];
}