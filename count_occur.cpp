#include<iostream>
#include<vector>

using namespace std;
int count_occur(vector<int> s1 , int target) // lets start with the brute force apporach 
{
	int count = 0 ;
	for(int index = 0 ; index < s1.size() ; index++)
	{
		if(s1[index]== target)
		{
			count++;
		}
	}

	return count ;

}

// now we will continue with a better more optimizedversion of the above code 

int count_occur_optimized(vector<int> s , int target)
{
	//the more optimized approach for the above problem can be to find the first occurence of the target variabel , and the last 
	// occurence of the target , then the number of  occurences is given by last-first+1;

	//lets find the  last occurence of the target 
	int max_index = INT_MIN;
	int min_index = INT_MAX;
	int low = 0 ;
	int high = s.size();

	while(low<=high)
	{
		if(s[(low+high)/2] == target)
		{
			max_index = max(max_index , (low+high)/2);
			min_index = min(min_index , (low+high)/2);
			// then search for the later half to get an index greater than that index 
			low = (low+high)/2 + 1;
		}
		else if(s[(low+high)/2] < target)
		{
			// then we  need to check for the second half of the problem 
			low = (low+high)/2 + 1;
		}
		else

		{
			// check in the first half of the array 
			high = (low+high)/2 -1 ;
		}
	}

	// this part gives us the max_index and the min_index ;
	return max_index - min_index + 1;

}

int main()
{
	vector<int> s {12 , 14 , 15 , 17 , 19 ,19 , 19 , 19};

	int count_occ = count_occur(s , 19);

	cout<< count_occ<<endl;

	int count_occur = count_occur_optimized(s , 19);

	cout<< count_occur << endl;
}
