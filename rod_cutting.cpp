//rod_cutting.cpp
#include<iostream>
#include<vector>

using namespace std;

//in this problem statement we are given the different rod lengths and their profits , we have to find the maximum profit from them 
//i believe this is the extension of the preceding problem of coin change 
// first find the different ways to cut the rod , and then get the profits and then get the max of those profits 

int max_profit_rod_cutting(vector<int> profits_per_rod ,int target , int profit_accumulated , int index )
{
	//now lets define the base case scenario 
	int prof = 0;
	int picked = 0 ;
	int not_picked = 0;
	if(target == 0)
	{
		return profit_accumulated;
	}
	else if(target<0)

	{
		return 0 ;
	}

	else if(index == profits_per_rod.size())
	{
		index = 1;
	}

	else
	{
		//so now you have two chances either reject the index or accept the index 
		picked  = max_profit_rod_cutting(profits_per_rod , target - index , profit_accumulated+profits_per_rod[index] , index+1);
		not_picked= max_profit_rod_cutting(profits_per_rod , target , profit_accumulated , index+1);
	}
	return max(picked , not_picked);
}
int main()
{
		vector<int> profits_per_length {0 ,1 ,4 , 10 , 100 , 5 , 6 , 8 , 100 , 101 , 1000};

		int target = 10;

		int res = max_profit_rod_cutting(profits_per_length , target , 0 ,0);

		cout<<"THE MAXIMU PROFIT IS GIVEN AS "<<res<<endl;
}