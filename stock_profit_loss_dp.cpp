//stock_profit_loss_dp.cpp

//in this code , we would be given certain stocks  and their prices , we have to find the max profit , we can obtain 
//we can  buy or sell many times 
#include<iostream>
#include<vector>

using namespace std;

void max_profit(vector<int> stock_price)
{
	//some basic intuition , you cannot buy another stock without selling the previous stock 
	//so i can have a stock today or i dont 
	//if i have a stock today , then i can sell it today or i dont 
	//if i dont have a stock today , i can buy today or i dont 
	//so we maintain two arrays one for if we  are able to buy or we are not
	int n = stock_price.size();

	vector<vector<int>> dp(n+1 , vector<int>(2,0));

	dp[n][0] = 0 ;
	dp[n][1] = 0 ;

	for(int day = n-1 ; day>=0 ; day--)
	{
	    //if i can buy  i  have two options , either i buy or i dont 
	    //if i buy
	    dp[day][1] = max(-price[day] + dp[day+1][0] , dp[day+1][1]) ; //if i buy at that day , then i cannot buy 
	    //in the coming days , but if i dont buy at that day , then i can buy in the coming days 

	    //if i have a stock at that day , then either i can sell or i wont sell 
	    dp[day][0] = max(price[day] + dp[day+1][1] , dp[day+1][0]) //if i wont sell , then i cant buy in the upcoming days 
	    
	}

}