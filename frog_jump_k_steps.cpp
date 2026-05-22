//frog_jump_k_steps.cpp
#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

vector<int> frog_jump_tabulation_approach(vector<int> height , int k) // bottom to up approach  and can take k steps in one 
{
	vector<int> result_array ;
	vector<int> index_array ;
	if(height.size() == 1)
	{
		result_array.push_back(0);
	}
	else if(height.size() == 2)
	{
		result_array.push_back(0);
		result_array.push_back(abs(height[1]-height[0]));
	}
	else
	{
		int min_value_result = INT_MAX;
		result_array.push_back(0);
		result_array.push_back(abs(height[1]-height[0]));

		for(int index = 2 ; index < height.size() ; index++)
		{
			for(int j = 1 ; j<=min(k, index) ; j++)
			{
				min_value_result = min(min_value_result , result_array[index - j] + abs(height[index]-height[index-j]));
				// if the min value is updated then push that index into index_array
				if(min_value_result == result_array[index - j] + abs(height[index]-height[index-j]))
				{
					index_array.push_back(index-j);
				}
			}

			// now we push_back the realted value into the vector 
			result_array.push_back(min_value_result);
		}
		//now we sum up the heights of the elements in the index _array to get the path cost 
		int index = index_array[index_array.size()-1];  // find from which position it arrived at the min 
		int summed_height = result_array[index_array[index_array.size()-1]] + abs(height[height.size()-1] - height[index_array[index_array.size()-1]]);
		//we push back this into our result array 
		result_array.push_back(summed_height);

	}

	return result_array;

}

//now lets try solving the above through memoization approach   memoizationis the top bottom approach 
int frog_jump_memoization_approach(vector<int> height , int index , int j , vector<int> &dp) // index is to find the minmum step to reuce to that index , and j is the timestep 
{
	// lets write the base case first 
	if(index == 1)
		return 0;

	if(index == 2)
		return abs(height[1] - height[0]);

	else
	{
		//here index >2
		int min_value = INT_MAX;

		for(int j1 = 1; j1<=j ; j1++)
		{
			if(index-j1 >=0)
			{
				int other_value = frog_jump_memoization_approach(height , index - j1 , j , dp) + abs(height[index]- height[index-j1]);

				min_value = min(min_value , other_value);
			}
		}

		return dp[index] == min_value;
	}


}

int main()
{
	vector<int> s {10,5,20,0,15};

	vector<int> result = frog_jump_tabulation_approach(s , 2);

	for(int index =0 ; index < result.size() ; index++)
	{
		if(index == result.size()-1)
		{
			cout<< "The summed energy which the frog must have is "<< result[index]<<endl;
		}
		else
		{
			cout<<" THE MINIMUM ENERGY REQUIRED FOR "<<index+1 <<" POSITION IS GIVEN BY  " <<result[index]<<endl;
		}
	}

	vector<int> dp ;

	frog_jump_memoization_approach(s,4 , 2 , dp);

	for(int x : dp)
	{
		cout<<x<<endl;
	}
}