//maximum_minimum_sum.cpp

//here in this question we are given a n*m matrix , and we can traverse in 3 directions  here 
//one is down , left diagonal and the right diagonal , we have to find the max/min_sum obtained by such traversal 
#include<iostream>
#include<vector>

using namespace std;

int max_sum(vector<vector<int> &s1 , vector<vector<int>> &dp  ,int rows , int columns)
{
	for(int column = 0 ; column < columns ; column++)
	{
		dp[0][column] = s1[0][column];
	}

	int max_sum_found = 0 ;
	for(int index = 1 ; index < s1.size() ;index++)
	{
		for(int index1 = 0 ; index1 <s1[index].size(); index1++)
		{
			if(index1 == 0)
			{
				//we need to find the min of either straight down or right down 
				dp[index][index1] = max(dp[index-1][index1] , dp[index-1][index1+1]) + s1[index][index1];
				if(index == s1.size()-1)
				{
					max_sum_found = max(max_sum_found , dp[index][index1]);
				}
			}
			else if(index1 == columns-1)
			{
				dp[index][index1] = max(dp[index-1][index1-1] , dp[index-1][index1]) + s1[index][index1];
				if(index == s1.size()-1)
				{
					max_sum_found = max(max_sum_found , dp[index][index1]);
				}
			}
			else
			{
				dp[index][index1] = max(dp[index-1][index1], dp[index-1][index1-1] , dp[index-1][index1+1]) + s1[index][index1];
				if(index == s1.size()-1)
				{
					max_sum_found = max(max_sum_found , dp[index][index1]);
				}
			}


		}
	}

	cout<<"THE MAX SUM FOUND IS "<<max_sum_found<<endl;

}

int min_sum(vector<vector<int> &s1 , vector<vector<int>> &dp  ,int rows , int columns)
{
	for(int column = 0 ; column < columns ; column++)
	{
		dp[0][column] = s1[0][column];
	}

	int min_sum_found = INT_MAX ;
	for(int index = 1 ; index < s1.size() ;index++)
	{
		for(int index1 = 0 ; index1 <s1[index].size(); index1++)
		{
			if(index1 == 0)
			{
				//we need to find the min of either straight down or right down 
				dp[index][index1] = min(dp[index-1][index1] , dp[index-1][index1+1]) + s1[index][index1];
				if(index == s1.size()-1)
				{
					max_sum_found = min(max_sum_found , dp[index][index1]);
				}
			}
			else if(index1 == columns-1)
			{
				dp[index][index1] = min(dp[index-1][index1-1] , dp[index-1][index1]) + s1[index][index1];
				if(index == s1.size()-1)
				{
					max_sum_found = min(max_sum_found , dp[index][index1]);
				}
			}
			else
			{
				dp[index][index1] = min(dp[index-1][index1], dp[index-1][index1-1] , dp[index-1][index1+1]) + s1[index][index1];
				if(index == s1.size()-1)
				{
					max_sum_found = min(max_sum_found , dp[index][index1]);
				}
			}


		}

	}

	cout<<"THE MIN SUM FOUND IS "<<min_sum_found<<endl;

}


