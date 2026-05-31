//triangle.cpp

#include<iostream>
#include<vector>

using namespace std;

//we are given a traingualr array , we have to find the minimum path sum from top to bottom 
int min_sum_top_bottom(vector<vector<int>> s , int current_row ) // here we can work greedily
//here we will use the top to bottom approach 
{
	int minimum = INT_MAX;
	//lets work greedily
	if(current_row == 0)
	{
		return s[0][0];
	}
	else
	{
		
		for(int index  = 0 ; index <= current_row ; index++)
		{
			minimum = min(minimum , s[current_row][index]);
		}
		// then we add the minimum to the sum and then move to the previous row 
	}
	return  minimum + min_sum_top_bottom(s , current_row-1) ;
}

int main()
{
	vector<vector<int>> s {{1} , {2,3} ,{4 ,5 ,6} , {10 ,8 ,9 ,100}};

	int min_sum  =  min_sum_top_bottom(s , 3);

	cout<<"the min sum is given as "<<min_sum ;
}