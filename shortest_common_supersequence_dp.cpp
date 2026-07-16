//shortest_common_supersequence_dp.cpp

//here we want to  find the minimal supersequence which contains both the strings and also its length 
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void shortest_supersequence_length(string s1 , string s2 , vector<vector<int>> &dp)
{
	//so here we first need to find the longest common subsequence 
	for(int column = 0 ; column < s2.size() ; column++)
	{
		if(s1[0] == s2[column])
			dp[0][column] = 1;
	}

	for(int row = 1 ; row< s1.size(); row++)
	{
		for(int column = 0 ; column < s2.size() ; column++)
		{
			if(s1[row] == s2[column])
			{
				if(column>=1)
				dp[row][column] = 1+ dp[row-1][column-1];

				else
					dp[row][column] = 1; //since dp[row-1][column-1] wont exist 
			}

			else
			{
				//either ignore the last character of the first string or ignore the last character of the second string 
				if(row >=1 && column >=1)
					dp[row][column] = max(dp[row-1][column] , dp[row][column-1]);
				else
					dp[row][column] = dp[row-1][column];
			}
		}
	}
	//after this we will get the longest common subsequence length 
	cout<<"the number of elements in shortest common supersequence is "<<s1.size() + s2.size() - dp[s1.size()-1][s2.size()-1];
}

void print_shortest_supersequence(vector<vector<int>> &dp)
{
	//for this purpose we will consult the dp table , we start form the extreme down portion 
	int row = s1.size()-1;
	int column = s2.size()-1;
	string ans = "";
	while(row> 0 &&column>0)
	{
		if(s1[row] != s2[column])
		{
			//we then need to see where the max is 
			if(dp[row-1][column] > dp[row][column-1])
			{
				ans += s1[row];
				row--;
			}
			else
			{
				ans += s2[column];
				column--;
			}
		}
		else
		{
			ans += s1[row];
			row--;
			column--;
		}
	}

	//now if we end the row and column is not zero , then we need to put the remaining elements into it 
	while(row >= 0)
{
    ans += s1[row];
    row--;
}

	while(column >= 0)
	{
    ans += s2[column];
    column--;
	}	
	//now we need to reverse the string 
	reverse(ans.begin() , ans.end());

	cout<<ans<<endl;
}