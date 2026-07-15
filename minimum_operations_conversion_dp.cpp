//minimum_operations_conversion_dp.cpp

//here in this code , we have to find the minimm number of operations either insertion or deletion to 
//convert one string to another 
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void convert_string(vector<vector<int>> &dp , string s1 , string s2)
{
	//so here we try to find the longest common subsequence between the two , and then we perform the
	//operations on the non common ones
	int max_common_size = 0 ;
	for(int row = 0 ; row<= s1.size() ; row++)
	{
		dp[row][0] = 0 ;
	}

	for(int column = 0 ; column <= s2.size() ; column++)
	{
		dp[0][column] = 0 ;  //this deals with the empty string 
	}

	//now lets fill for the general case 
	for(int row = 1 ; row<= s1.size() ; row++)
	{
		for(int column =1 ; column<= s2.size() ; column++)
		{
			if(s1[row-1] == s2[column-1])
			{
				dp[row][column] = 1+ dp[row-1][column-1];
				if(dp[row][column]>max_common_size)
				{
					max_common_size = dp[row][column];
				}
			}
			else
			{
				//ignore the last element of the first string , or ignore the last element of the second string 
				//and then try to find the common element 
				dp[row][column] = max(dp[row-1][column] , dp[row][column-1]);
			}

		}
	}

	cout<<"THE NUMBER OF OPERATIONS REQUIRED IS "<<s1.size()+s2.size()-max_common_size*2;
}
