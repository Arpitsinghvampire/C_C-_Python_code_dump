#include<iostream>
#include<vector>

using namespace std;

int no_of_rotations(vector<int> s)
{
	// so this question is basically an extension of  previous question 
	// basic optimized approach to find the min of the vector array  and then get the rotations by finding its index+1 

	int min_value = INT_MAX;
	int min_index = 0;
	int low = 0 ;
	int high = s.size();

	while(low<=high)
	{
		// check for sortedness , either the left hand side is sorted or the right hand side is sorted 
		if(s[low]<s[(low+high)/2]) // check the sortedness of the left hand side 
		{
		
			min_value = min(min_value , s[low]);
			if(min_value == s[low])
			min_index = low ;
	

			// now update the low to check the min for the right hand side array 
			low= (low+high)/2  + 1;
		}

		else  // in this case the right hand side is the sorted one , the left hand side is not the sorted one 
		{
			min_value = min(min_value , s[(low+high)/2]);
			if(min_value == s[(low+high)/2])
			min_index = (low+high)/2 ;

			// we then move the high towards the left side to get the min of the first half
			high = (low+high)/2 - 1;
		}
	}

	return min_index  ;

}

int main()
{
	vector<int> s {12 , 13 , 14 , 15 , 16 , 0 , 1 ,2 ,3,4 ,5, 6, 7};
	int nor = no_of_rotations(s);

	cout<<nor;
}