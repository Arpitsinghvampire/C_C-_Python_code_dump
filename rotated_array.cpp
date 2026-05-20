#include<vector>
#include<iostream>

using namespace std;

// the brief about the question 
// in thsi question we have a rotated array , and we would have to search for a target 
// the array was earlier in  ascending order which was then rotated 


int  search_rotated_array(vector<int> s , int target)
{
	// search linearly , search the while vector 
	for(int index = 0 ;index < s.size() ; index++)
	{
		if(s[index] == target)
		{
			return index;
		}
	}
	// else if the number was not found , then return -1 
	return -1 ;
}

int search_rotated_array_optimized(vector<int> s , int target)
{
	int low = 0 ;
	int  high = s.size();

	while(low<=high)
	{
		//in this question either the left side is sorted or the right side is sorted 
		if(s[(low+high)/2] == target)
			return (low+high)/2;

		// if the left side is sorted 
		else if(s[0] < s[(low+high)/2]) // this means that the left side is sorted so we can  apply the binary seach in that half 
		{
			// we then need to check  for those limits 
			if(target >= s[low] && target <= s[(low+high)/2])
			{
				high = (low+high)/2 -1 ; // move the pointers towards this point 
			}
			else
			{
				low = (low+high)/2 + 1; // else move to the other half 
			}
		}

		else // the right hand side is the sorted one  , so we need to apply binary search on the right hand side 
		{
			if(target>=s[low] && target <=s[(low+high)/2])
			{
				low = (low+high)/2 + 1;
			}
			else
			{
				high = (low+ high)/2 -1 ;
			}
		}
	}

	// if the element is not returned it means that  the element is nto present there 
	return -1 ;
}

int main()
{
	vector<int> s { 12 , 13 , 14 , 15 , 0 , 1  , 2  , 3 , 4};

	int searched = search_rotated_array(s , 5);

	cout<<searched<<endl;

	int searched1 = search_rotated_array_optimized(s , 14);

	cout<< searched1 <<endl;
}