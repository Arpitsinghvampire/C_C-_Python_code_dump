//here we will store the maximum sum we get and also the running sum if the running sum becomes zero , we diregrard the runnning sum 
//that is we convert that runnning sum to 0 if it is less than 0 
#include<iostream>
#include<vector>

using namespace std;

int kadanes_algorithm(vector<int> sums_array)
{
	int max_sum = INT_MIN;
	int running_sum =0 ;

	for(int index = 0 ; index < sums_array.size() ; index++)
	{
		running_sum += sums_array[index];
		if(max_sum < running_sum) //update the running sum 
		{
			max_sum = running_sum ;
		}
		if(running_sum < 0) //however we only propagate teh running sum if the running sum is greater than 0  , because if not it will reduce the value 
		{
			running_sum = 0 ;
		}
	}
	return max_sum ;
}
int main()
{
	vector<int> output_array({-2,-3 , 4,-1,-2 , 1,5,-3});

	int result = kadanes_algorithm(output_array);

	cout<<result;
}
