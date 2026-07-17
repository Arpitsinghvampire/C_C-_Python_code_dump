//stock_cooldown.cpp

//in this question you can buy or sell unlimited number of times , but there is a cooldown period , you cannot sell 
//after each buy 

#include<iostream>
#include<vector>

using namespace std;

int cooldown_max(int cool_down_period , vector<int> profits)
{
	vector<vector<int>> s1(profits.size() , vector<int>(2,0));
	//some basic intuition , you cannot buy another stock without selling the previous stock 
	//so i can have a stock today or i dont 
	//if i have a stock today , then i can sell it today or i dont 
	//if i dont have a stock today , i can buy today or i dont 
	//so we maintain two arrays one for if we  are able to buy or we are not

	for(int index = profits.size()-1 ; index>=0 ; index--)
	{
		//you can either have a stock , or you dont , 
		//you can either sell a stok you have or you dont 
		//0 means you have a stock so you cant buy another stock
		if(index + cool_down_period <= profits.size())
			dp[index][0] = max(profits[index] + dp[index+ cool_down_period][1] , dp[index+1][0]);
		//you cann buy after the cool down period  , if you dont sell , then you can sell the next day 
		else
			dp[index][0] = max(profits[index] , dp[index+1][0]);
		//you wont be able to buy before the cool down period 

		//similarly we do the buy side 
		//if you can buy a stock , you can either buy on that day ,or you dont 

		dp[index][1] = max(-profits[index] + dp[index+1][0] , dp[index+1][1]);
		//then you cant buy on the next day , if you buy today 
	}

	return dp[0][1];
	
}