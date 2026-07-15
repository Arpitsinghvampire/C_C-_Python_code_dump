//longest_common_substring.cpp

//in this code , we have to find the longest common substring , that is it should be contigous and ,
//we have to find the maximal such substring 

//here one thing to note is that they should be continguous you cannot take non contigouous to be in the solution 
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void longest_common_substr(vector<vector<int>> &dp , string s1 , string s2)
{
	int max_size = INT_MIN;

	int start_index = 0; // for the purpose of finding where to start the substring 
	//and then printing it 
	//lets fill the empty string first 
	for(int row = 0 ; row< s1.size() ; row++)
	{
		dp[row][0] = 0;
	}
	for(int column = 0 ; column < s2.size() ; column++)
	{
		dp[0][column] = 0 ;
	}

	//now lets fill the general values 

	for(int row = 1 ; row < s1.size() ;row++ )
	{
		for(int column = 1 ; column < s2.size() ; column++)

		{
			if(s1[row-1] == s2[column-1])
			{
				dp[row][column] = 1+ dp[row-1][column-1];

				if(dp[row][column] > max_size)
				{
					max_size = dp[row][column];
					start_index = row-1 ; //store the row for which we get  the max 
				}
			}

			else
			{
				dp[row][column] = 0 ; // we dont put the max of  ignoring the last string of either the strings 
				//because we want it to be contiguous 
				max_size = max(max_size , dp[row][column]);
			}
		}
	}

	cout<<max_size<<endl;

	//we then need to print the  elements from start_index- max_length+1 , max_length ;
	string longest_string = s1.substr(start_index-max_length+1 , max_length);
}
