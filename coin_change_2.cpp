//coin_change.cpp

#include<iostream>
#include<vector>

//in this coin change problem we would be given a target sum and we would want to know how many minimum number of coins to achieve that target 
//here we will focus purely on the memoization or the tabulation approach 
using namespace std;

//here we will maintain a 1d array , 
void minimum_sum_coin(int target , vector<int> &dp  ) //here we have the coin changes of 1 ,2 and 5 rupees 
{
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for(int index = 3 ; index <= target ; index++)
	{
		if(index <5)
		{
			//then you can only use the 1 re or 2 rs coin 
			dp[index] = min(1+dp[index-2] , 1+dp[index - 1]);
		}
		else
		{
			dp[index] = min(1+dp[index-1] , 1+dp[index-2] , 1+dp[index-5]); //find the min among using the 1,2 or 5 coin 
		}
	}

}
int main()
{
	//now lets see how it works 
	int target = 45;
	vector<int> sum_target (0,target+1);

	minimum_sum_coin(target , sum_target);

	//now lets see the minimum number of coins required 
	cout<<"THE MINIMUM NUMBER OF COINS REQUIRED FOR "<<sum_target[target];
}