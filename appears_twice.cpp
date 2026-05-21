#include<vector>
#include<iostream>
#include<map>
using namespace std;


int appears_twice(vector<int> s) // lets use a basic algorithm that finds  the count of each element 
{
	map<int , int> frequency_map;

	for(int index = 0 ;index< s.size(); index++)
	{
		frequency_map[s[index]] += 1;
	}

	for(auto [key , value] : frequency_map)
	{
		if(frequency_map[key] == 1)
		{
			return key ;
		}
	}
	return -1 ; // else all the values occur greater than 1 times 
}

// we can also solve the above problem using xor 
int appears_twice_xor(vector<int> s) // this algorithm also has the complexity of O(n)
{
	int result = 0 ;
	for(int index = 0 ; index < s.size() ; index++)
	{
		result ^= s[index];
	}

	return result ;
}

// now lets another approach for the above problem statement 
// it is given that the array is sorted and all numbers except one appears twice 
//suppose we take the example 
//[1 ,2,2,3 ,3 ,4 ,4 ,5 ,5]  mid point is 3 , if the mid is not equal to mid+1 , that means singular element in first half , else in second half 
// we will use this concept here

int appears_twice_optimized(vector<int> s)
{
	int low = 0 ;
	int high = s.size();

	while(low<=high)
	{
		// the target or the singular element can be the middle element if it is not equal to either of the neighbours 
		if(s[(low+high)/2] != s[(low+high)/2 - 1] && s[(low+high)/2] != s[(low+high)/2+1])
		{
			// the middle element is the one that appears twice ;
			return s[(low+high)/2];
		}
		// we then check the pairing conditions 
		else if(s[(low+high)/2] == s[(low+high)/2]+1)
		{
			// the answer then lies in the second half of the vector 
			// therefore update the low point 
			low = (low+high)/2+1;
		}
		else
		{
			// update towards the first half 
			high= (low+high)/2 -1 ;
		}
	}

	// if nothing is returned then we return -1 
	return -1 ;
}

int main()
{
	vector<int> s { 1,2,2,3,3,4,4,5,5};

	int appears_tw = appears_twice(s);

	cout<< appears_tw <<endl;

	// now lets get the output using the xor approach 
	int appears_tw_xor = appears_twice_xor(s);

	cout<<appears_tw_xor<<endl;

	// now lets try using the optimized version of the algorithm 
	int appears_tw_opti = appears_twice_optimized(s);

	cout<< appears_tw_opti <<endl;


}