#include<iostream>
#include<vector>

using namespace std;

// we are given a 2d array each having the rewards for each activity each day , and the ninja cannot do the same activity two days
//we have to  find the maximum reward he can get 

//this is the bottom up approach 
int max_reward(int current_day  , vector<vector<int>> rewards_per_day , int last_work )//last work will track the  last work done 
{
	//no lets write the base case scenario , here the base case scenario is the last day 
	int picked_zero = 0;
	int picked_one = 0 ;
	int picked_two = 0;

	if(current_day == rewards_per_day.size()-1)
	{
		vector<int> possible_works ;
		for(int index = 0 ; index <3  ;index++)
			{
				if(index!= last_work)
					possible_works.push_back(index); //we will have the possible works 
			}
	//this will give us the possible works which can be done 
		return max(rewards_per_day[current_day][possible_works[0]] ,rewards_per_day[current_day][possible_works[1]]);
	}
	
	else if(current_day == 0)
	{
		//you can choose from either activity 
		picked_zero   = rewards_per_day[current_day][0] + max_reward(current_day+1 , rewards_per_day , 0);
		picked_one = rewards_per_day[current_day][1] + max_reward(current_day + 1 , rewards_per_day ,1);
		picked_two = rewards_per_day[current_day][2] + max_reward(current_day + 1 , rewards_per_day ,2);

		//now we would want to return the max among them , this is not the base case scenario 
		int max1 = max(picked_zero , picked_one);
		return max(max1 ,  picked_two);
	}

	else
	{
		vector<int> possible_works ;
		for(int index = 0 ; index <3  ;index++)
			{
				if(index!= last_work)
					possible_works.push_back(index); //we will have the possible works 
			}
			//this will give us the possible works which can be done 
			picked_one = rewards_per_day[current_day][possible_works[0]]+max_reward(current_day+1 , rewards_per_day  , possible_works[0]);
			picked_two= rewards_per_day[current_day][possible_works[1]]+max_reward(current_day+1 , rewards_per_day  , possible_works[1]);
	}
	return max(picked_one , picked_two);
	
}

int main()
{
		vector<vector<int>> rewards_per_day {{11,10,9} , {5 ,100 , 40} , {50 ,51 , 91} , {24 , 28 , 35}};

		int maximum_reward = max_reward(0 ,rewards_per_day, 0); //here the last day =0 bears no affect for day 0 
		//this is then translated 

		cout<<"THE MAXIMUM REWARD FOR THE ABOVE REWARDS PER DAY PER ACTIVITY IS GIVEN AS "<< maximum_reward;
}