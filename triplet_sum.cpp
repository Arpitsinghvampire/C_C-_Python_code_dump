//we need to find a triplet sum that adds to 0 
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> triplet_sum(vector<int> & vector1)
{
	sort(vector1.begin() , vector1.end()); //sort  the array first 
	vector<vector<int>> result_vector;
	int slow_pointer = 0 ;
	int fast_pointer = vector1.size()-1;

	for(int index =  0 ; index < vector1.size() ; index++)
	{
		slow_pointer = index+1;
		fast_pointer = vector1.size()-1;

		while(slow_pointer <= fast_pointer)
		{
			if(vector1[index] + vector[slow_pointer] + vector[fast_pointer] == 0)
			result_vector.push_back({index , slow_pointer , fast_pointer});

			else if(vector1[index]+ vector[slow_pointer] + vector[fast_pointer] >0)
				{
					//we need to reduce the sum 
					fast_pointer--;
				}
			else
				{
					//we need to increase the sum 
					slow_pointer ++ ;

				}
		}
	}
	return result_vector;
}