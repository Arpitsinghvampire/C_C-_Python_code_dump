//0_1_knapsack_problem.cpp
#include<iostream>
#include<vector>

using namespace std;

//here we will be given two vectors , one vector for the profit and one vector for the weight , we are given the weight which the bag 
//can carry given the weight you need to maximize the profit you can get 

int max_profit(vector<int> weights ,vector<int> profits, int total_profit_accumulated , int current_index , int capacity)
{
	//we will start from the bottom up approach that is we will start from the starting index , 
	//so our base case would be the last index 
	int picked = 0;
	int not_picked = 0;
	//for the base case scanrio the weight_accumulated should be less than the capacity and also the current index should be less than the last element 
	if(capacity<0)
	{
		// we should return the profit for weight_accumulated - last weight , because of which it got more than the capacity 
		return total_profit_accumulated - profits[current_index];
	}

// one more base case would be the current_index , current_index should be equal to the size of the weight
	else if(current_index == weights.size()-1)
	{
		// this means that the weight of the bag is still less than  or equal to the capacity of the bag 
		//check for the capacity manually after either picking or not pick 
		if(capacity>= weights[current_index])
		{
			//you can add hte weight and. hence the profit 
			total_profit_accumulated += profits[current_index];
		}
		//else you cant add the weight and hence the profit , then return the total_profit_accumulated 
		return total_profit_accumulated;
	}
	

	else
	{
		picked = profits[current_index]+ max_profit(weights , profits , total_profit_accumulated  , current_index+1 , capacity-weights[current_index]);
		not_picked = max_profit(weights , profits , total_profit_accumulated  ,  current_index+1 , capacity);

	}
	return max(picked , not_picked);

}

int main()
{
	vector<int> weights {20,30,40,50};
	vector<int> profits {30 , 50 , 40 , 60};


	int max_profit1 = max_profit(weights , profits , 0 , 0  , 50);

	cout<<"THE MAX PROFIT IS "<<max_profit1<<endl;
}