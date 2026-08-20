//here we will be given an array , we will have to find the repeating number and the missing number 
#include<iostream>
#include<vector>

using namespace std;

vector<int> missing_duplicate_number(vector<int> &given_array)
{
	vector<int> given_array1(given_array);
	vector<int> result ; //first one contains the  duplicate element , and the second one contains the repeating elements 
	for(int index = 0 ; index < given_array1.size() ; index++)
	{
		int num = abs(given_array1[index]);
		int previous_index = num-1;
 		
 		if(given_array1[previous_index] < 0)
 		{
 			result.push_back(num);
 		}
 		else
 			given_array[index] = -given_array1[index];
	}
	//now lets find the duplicate element 
	for(int index = 0 ; index < given_array1.size() ; index++)
	{
		if(given_array1[index] <0)
			continue;
		else
			result.push_back(index+1);
	}
}