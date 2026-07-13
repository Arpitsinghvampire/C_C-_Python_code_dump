//difference_given_dp.cpp

//here we want to find the number of subsets with a given difference 
#include<iostream>
#include<vector>

using namespace std;

int number_of_ways_sum(vector<int> &s1 , vector<vector<int>> &dp , int target)
{
	//so by default we have the number of rows as the number of elements in s1 and the number of columns as 
	//number from 0 to the target 
	for(int column = 1 ; column < target + 1; column++)
	{
		
		if(s1[0] == column)
			dp[0][column] = 1;
	}

	for(int row = 0 ; row<s1.size() ;row++)
	{
		dp[row][0] = 1;
	}

	for(int row = 1 ; row < s1.size() ; row++)
	{
		for(int column = 1 ; column < target+1 ; column++)
		{
			int not_take = dp[row-1][column];

			int take = 0 ;

			if(s1[row] <= target)
				take = dp[row-1][target-s1[row]];

			dp[row][column] = take + not_take;
		}
	}

	return dp[rows-1][target];
}

void difference_given(vector<int> &s1 , int diff , vector<vector<int>> &dp)
{
	int tot_sum = 0 ;
	for(int x: s1)
		tot_sum += x;

	if((tot_sum + diff)%2 !=0)
		return ;

	int target = (tot_sum + diff)/2;

	number_of_ways_sum(s1 , dp , target);

}