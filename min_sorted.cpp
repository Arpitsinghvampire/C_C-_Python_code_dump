#include<vector>
#include<iostream>

using namespace std;

// basic approach
int min_sorted(vector<int> s)
{
	int min_value = INT_MAX;
	for(int index = 0 ; index < s.size() ; index++)
	{
		min_value = min(min_value , s[index]);
	}

	return min_value ;
}

// we will use a more optimized approach  for the above algorithm to find the min of the rotated array 

int min_sorted_optimized(vector<int> s)
{
	int low = 0 ;
	int high = s.size() ;
	int min_value = INT_MAX;

	// we use the same approach that either the  first half is sorted or the second half is sorted verytime 
	while(low<= high)
	{
		if(s[low] <= s[(low+high)>>1]) // this means that the first half is sorted one 
		{
			min_value = min(min_value , s[low]) ; // since it is the sorted array , min will always be the first element 
			// then update the low part to get the min of the seond part also 
			low = (low+high)/2 + 1;
		}
		else // the second half is the sorted array 
		{
			min_value = min(min_value , s[(low+high)/2]); // min of this half of the array would be the mid element 
			// we would then need to check for the min of the first half 
			high = (low+high)/2 -1 ;
		}
	}
	return min_value;
}

int main()
{
	vector<int> s{12 , 13 ,14 ,15 ,16 ,0 , 1 ,2 ,3 ,5};

	int min = min_sorted_optimized(s);

	cout<<min<<endl;
}