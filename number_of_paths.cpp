//number_of_paths.cpp
#include<iostream>
#include<vector>

using namespace std;

// this function takes in the number of rows and columns 
vector<vector<int>> number_of_ways(int rows , int columns) // start from the left most upper side , this will be our base case 
{
	// they can  only move downwards or rightwards
	//start with the base case 
	vector<vector<int>> dp(rows, vector<int>(columns, 0)); ;

	for(int i = 0 ; i < rows ;i++)
	{
		for(int j =0 ; j<columns ; j++)
		{
			if(i == 0 || j== 0)
			{
				dp[i][j] = 1;
			}
			// else we define the non boundary cases 
			else
			{
				dp[i][j] = dp[i-1][j] + dp[i][j-1]; // either come from the left or come from above 
			}
			
		}
	}

	return dp;

}

int main()
{
	int rows , columns ;
 cout<<"ENTER THE NUMBER OF ROWS YOU WANT  ::  ";
 cin>> rows;

 cout<<"ENTER THE NUMBER OF COLUMNS YOU WANT ::  ";
 cin>> columns;

 vector<vector<int>> dp = number_of_ways(rows , columns);

 for(int index = 0 ; index < rows ; index++)
 {
 	for(int index1 = 0 ; index1 < columns ; index1++)
 	{
 		if(index1 == columns - 1)
 		{
 			cout<< dp[index][index1];
 			cout<<endl;
 		}
 		else
 		{
 			cout<<dp[index][index1];
 		}
 	}
 }
}