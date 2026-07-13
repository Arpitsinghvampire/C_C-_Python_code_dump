//partition_two_subset_dp.cpp
//in this code we have to partition a vector into two sub vectors so that we have the absolute min sum possible 
#include<iostream>
#include<vector>

using namespace std;

//the basci approach for this problem is that , we find all the sums which are possible using all the elemtns of the 
//vector 
void subset_sum(vector<int> &s1 , int target , vector<vector<bool>> &dp , int rows , int columns )
{
	int sum_obtained = 0 ;
	for(int x : s1)
		sum_obtained += x;
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

	//now from the last row , we get all the elements that are true , that is the sum which is possible 
	vector<int> s2;
	//from here we get each element of the row 
	for(int index = 0 ; index < columns ; index++)
	{
		if(dp[rows-1][index] == true)
		{
			s2.push_back(index);
		}
	}
	int minsum = INT_MAX;
	vector<int> s3;
	for(int x :s2)
	{
		int diff = abs(sum_obtained-x);
		minsum = min(minsum , diff);
		s3.push_back(abs(sum_obtained-x));
	}

	//and then choose the min among them 
	cout<<"THE MINIMUM DIFFERENCE WE GOT IS "<<minsum<<endl;
}