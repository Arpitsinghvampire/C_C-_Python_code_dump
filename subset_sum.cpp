//subset_sum.cpp
#include<iostream>
#include<vector>
using namespace std;

//here we will be given a target and then we need to find whether a subset eqwual to that target exists or not 
void subset_sum(vector<int> s , int target , int current_index ,int sum)
{
	//so either you pick that element or you dont pick that element 
	int flag = 0 ;
	//start from the bottom up 
	//either you select that element , or you dont seclect that element 
	//if you selct that element  then you need to update the target  , else you dont 
	//base case is the fact that sum == target
	if(sum == target)
	{
		cout<<"SUBSET SUM TARGET FOUND";
		flag = 1;
		return ;
	}

	else if(current_index >s.size()-1)
	{
		return ;
	}

	else
	{
		subset_sum(s , target  , current_index+1 , sum) ; //you dont take this element 

		subset_sum(s , target ,current_index+1  , s[current_index] + sum) ;//you take that element 
	}
	return;

}


int main()
{
	vector<int> s { 23 , 34 , 35 ,45, 10  , 1 };

	int target = 2000;

	subset_sum(s , target , 0 , 0);
}