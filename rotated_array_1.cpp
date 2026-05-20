#include<vector>
#include<iostream>

using namespace std;


// here we will only use the optimized part from the previous programme 
bool rotated_array(vector<int> s , int target)
{
	int low  = 0 ;
	int high = s.size();

	while(low<=high)
	{
		if(s[(low+high)/2] == target)
		{
			return true ;
		}

		else if (s[low] == s[(low+high)/2] && s[(low+high)>>1] == s[high])
		{
			low ++ ;
			high -- ;
			continue ;
		}
		// take th case where the left hand side is the sorted one 
		else if(s[low]<=s[(low+high)/2])
		{
			// this means that the target can be in this area 
			if(s[low] <=target && target <=s[(low+high)/2])
			{
				// then the solution lies here therefor update the high point 
				high = (low+high)/2 -1 ;
			}
			else
			{
				low = (low+high)/2 +1 ; // move to the other part of the array 
			}
		}

		else
		{
			// if the right hand side is the sorted one 
			if(s[(low+high)/2] <= target && target<=s[high])
			{
				// therefore the target lies in the right 
				low = (low+high)/2 +1 ;
			}
			else
			{
				// target lies in the left hand side of the mid 
				high = (low+high)/2 -1 ;
			}
		}
	}

	return false;
}

int main()
{
	vector<int> s { 12  , 12 , 14 ,15 , 16 , 17 , 0 , 1 , 2 ,3 ,4 ,4 ,5, 5};

	bool rotated = rotated_array(s , 15);
	cout<< rotated <<endl ;
}
