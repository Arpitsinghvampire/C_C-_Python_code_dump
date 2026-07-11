//house_robber_dp.cpp

//in this code the houses are in a circle , the robber wants to maximize his gains 
#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &s1 , int index , int end)
{
	if(index > end)
		return 0 ;

	int taken  = s1[index] + solve(s1 , index + 2 , end);
	int not_taken = solve(s1 , index + 1 , end);

	return max(taken, not_taken);
}

int max_profit(vector<int> &nums)
{
	if(nums.size() ==1)
		return nums[0];
	int taken = solve(nums , 0 , n-2);
	int not_taken = solve(nums , 1, n-1);

	return max(taken , not_taken);
}

int max_gain(vector<int> &s1 ,int start_index , int end_index )
{
	if(start_index > end_index)
		return 0 ;
	if(start_index == 0)
	{
		//since the first house is  circular , if you steal from it then you cant steal from the end house 
		
		int not_taken = max_gain(s1 , start_index+1 , end_index);
		int taken = s1[start_index] + max_gain(s1 , start_index + 2 , end_index-1);
		return max(taken , not_taken);
	}
		int taken1 = s1[start_index] + max_gain(s1 , start_index+2 , end_index);
		int not_taken1 = max_gain(s1 , start_index +1 , end_index);
	

	return max(taken1 , not_taken1);
}

//now lets use the dp approach 
int approach_dp(vector<int> &s1 )
{
	if(s1.size() == 1)
		return s1[0];
	vector<int> s2(s1.size()-1,0);
	vector<int> s3(s1.size()-1,0);
	//case 1 , you remove the last element 
	s2[0] = s1[0];
	s2[1] = max(s2[0] , s1[1]);

	for(int index1 = 2 ;index1 <s2.size() ; index1++ )
	{
		s2[index1] = max(s2[index1-1] , s2[index1-2] + s1[index1]);
	}

	//case 2 ,you remove the first element and then check the max among the last number
	s2[0] = s1[1];
	s2[1] = max(s1[1] , s1[2]);

	for(int index2 = 2 ; index2 <s3.size() ; index2++)
	{
		s3[index2] = max(s3[index2-1] , s3[index2-2] + s1[index2+1]);
	}

	//return the max of the two values obtained at the last 
	return max(s2[s2.size()-1] , s3[s3.size()-1]);
}

