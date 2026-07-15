//longest_common_subsequence_dp.cpp

//here we wwould be given two strings , we need to find the maximal common subsequence between the two 
#include<iostream>
#include<vector>	
#include<string>

using namespace std;

void longest_common_sequence(str string1 , str string2 , vector<vector<int>> &dp)
{
	//here the number of rows is the size of the string1 , and the number of columns is string2
	for(int column = 0 ; column < string2.size() ; column++)
	{
		if(string1[0] == string2[column])
			dp[0][column] = 1;
	}

	//now lets focus on the other 
	for(int row = 0 ; row < string1.size(); row++)
	{
		for(int column = 0 ; column < string2.size() ; column++)
		{
			if(string1[row] == string2[column])
				dp[row][column] = 1+ dp[row-1][column-1]; // add one to common subsequence diagonally smaller

			else
			{
				//now we have two cases ,we either ignore the last element of the second string 
				//or we ignore teh last element of the first string and then 
				//ignore the second strings last element 
				int ignore_last_string = dp[row][column-1];
				//ignore the  first strings last element , then update with the max 
				int ignore_first_string = dp[row-1][column];

				dp[row][column] = max(ignore_last_string , ignore_first_string);
			}
		}
	}
}
