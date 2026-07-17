//stock_profit_liss_dp_k.cpp

//here we are allowed to do k transactions 
//stock_profit_loss_dp_2.cpp

//here we have the transactions limited to 2 , we can only buy or sell twice , not more than that 
#include<iostream>
#include<vector>

using namespace std;

int  max_profit(vector<int> profits , int k )
{
	vector<vector<int>> s1(profits.size() , vector<int>(k+1,0));
	//some basic intuition , you cannot buy another stock without selling the previous stock 
	//so i can have a stock today or i dont 
	//if i have a stock today , then i can sell it today or i dont 
	//if i dont have a stock today , i can buy today or i dont 
	//so we maintain two arrays one for if we  are able to buy or we are not


	for(int day = n-1 ; day>=0 ; day--)
	{
		for(int cap = 1; cap <=k ; cap++)
		{
			//if i can buy  i  have two options , either i buy or i dont 
	    //if i buy
	    dp[day][1] = max(-price[day] + dp[day+1][0][cap] , dp[day+1][1][cap]) ; //if i buy at that day , then i cannot buy 
	    //in the coming days , but if i dont buy at that day , then i can buy in the coming days 

	    //if i have a stock at that day , then either i can sell or i wont sell 
	    dp[day][0] = max(price[day] + dp[day+1][1][cap-1] , dp[day+1][0][cap]) //if i wont sell , then i cant buy in the upcoming days 

		}
	 
	}

	return dp[0][1][k];


}