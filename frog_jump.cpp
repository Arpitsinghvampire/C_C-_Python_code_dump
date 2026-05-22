//frog_jump.cpp
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

 vector<int> frog_jump(int n ,vector<int> height )
{
	vector<int> result ;
	// the frog can take one or two steps at one go 
	// the frog is at the first step  , in each step , we will find the least energy method to get to that stair 
	if(n == 1)
	{
		result.push_back(0);
 // this is the base case 
	}
	else if(n==2)
	{
		result.push_back(0);
		result.push_back(abs(height[1]-height[0]));
		 // this is the base case 
	}

	else
	{
		//we take the general case 
		result.push_back(0); // it is alsready in that staircase
		result.push_back(abs(height[1]-height[0])); // base case for reaching that staircase 

		for(int index = 2 ; index < height.size() ; index++)
		{
			// you can reach to that stair  by taking one step from the previous or  taking 2 steps from the penultimate one 
			result.push_back(min(result[index-2]+ abs(height[index]-height[index-2]) , result[index-1] + abs(height[index]-height[index-1])));
			// energy needed to reach the previous step + energy required for the  next step  , we update it with the minimum 
		}

	}
	return result ;
}


int main()
{
	vector<int> height {2,1,3,5,4};

	vector<int> result =frog_jump(height.size() , height);

	for(int index = 0 ; index < result.size() ; index++)
	{
		cout<<"FOR THE HEIGHT "<<height[index] << " THE MINIMUM ENERGY REQUIRED IS " << result[index]<<endl;
	}
}