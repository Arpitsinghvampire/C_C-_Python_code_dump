//coin_change.cpp

//here we are given unlimited supply of coins , we want to know in. how many ways can we get the exact change 
//this is also a problem of dp 

#include<iostream>
#include<vector>

using namespace std;

int coin_change_problem(vector<int> changes_available , int target)
{
	int result = 0 ;
	if(target == 0) //base case scenario 
	{
		
		return 1 ;
	}

	else if(target < 0) //base case scenario 
	{
		return 0 ;
	}

	else
	{
		
		for(int index = 0 ; index <changes_available.size() ; index++)
			{
		//you pick from the different values 
				result += coin_change_problem(changes_available , target - changes_available[index]);
			}
	}
	return result ;
	
}


int main()
{
	vector<int> changes_available {1 ,2 ,3};

	int target = 5;

	int number_of_values = coin_change_problem(changes_available , target);

	cout<<"THE NUMBER OF VALUES ARE  "<<number_of_values<<endl;
}