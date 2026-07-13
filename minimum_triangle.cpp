//minimum_triangle.cpp

//here we would be given a traingle with some weights , we have to reach from the top row to the bottom most row in the min cost 
#include<iostream>
#include<vector>
using namespace std;

void min_triangle(vector<vector<int>> &s1 , vector<vector<int>> &dp)
{
	dp[0][0] = s1[0][0];
	for(int index1 = 1 ; index1 < s1.size() ; index1++)
	{
		dp[index1][0] = s1[index1][0] ; //initialize the first element with the same elment 
	}

	for(int index = 1; index < s1.size() ; index++)
	{
		for(int index1= 1 ; index1 <= index ; index1++)
		{
			if(index ==1)
			{
				//we are in the second column
				dp[index][index1] = dp[index-1][index1-1] + s1[index][index1];
			}
			else
			{
			  if(index != index1)
			  {
			  	//you can go diagonally as well as the straight down 
			  	dp[index][index1] = min(dp[index-1][index1] , dp[index-1][index1-1]) + s1[index][index1];
			  }
			  else
			  {
			  	// you can move only diagonally 
			  	dp[index][index1] = dp[index-1][index1-1] + s1[index][index1];
			  }
			}
		}
	}
}