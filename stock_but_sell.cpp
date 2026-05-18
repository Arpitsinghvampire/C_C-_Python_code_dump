#include<iostream>
#include<vector>

using namespace std;

int buy_sell_stock(vector<int> s) // brute force approach with a complexity of O(n^2)
{
    vector<int> profits ;
    // basically find the min and the max , their difference is the maximum profit they can obtain 
    for(int index  = 0 ; index < s.size() ; index++)
    {
        for(int index1 = index+1 ; index1 < s.size() ; index1++)
        {
            profits.push_back(s[index1]-s[index]);
        }
    }
    // now we need to choose the max among the profits ;
    int max = profits[0];
    for(int index  = 0 ; index< profits.size() ; index++)
    {
            if(profits[index]>= max)
            max = profits[index];
    }

    return max ;
}

//optimized approach O(n)
int buy_sell_stock1(vector<int> s) // here we try to use a more optimized part of the code for finding the max difference 
{
    int min = INT_MAX ;
    int max_profit = 0 ;
     
     for(int index = 0 ; index< s.size() ; index++)
    {
        if(s[index]<=min)
        {
        min = s[index];
        }
        max_profit = max(max_profit , s[index]-min);
    }

    return max_profit ;

}


int main()
{
    vector<int> stock_prices { 23 ,34 , 45 , 10 , 12 , 1 , 0 , 0 , 100};

    int max_profit = buy_sell_stock(stock_prices);

    cout<<max_profit <<endl;

    int max_profit_opt =buy_sell_stock1(stock_prices);

    cout<<max_profit_opt;
}