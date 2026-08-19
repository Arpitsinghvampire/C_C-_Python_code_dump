#include<iostream>
#include<vector>
#include<array>

using namespace std;

bool is_smallest(vector<int> vectors)
{
	//if the array is in the ascending order , then it is the smallest array
	vector<int> vectors1(vectors);

	sort(vectors1.begin() , vectors1.end());
	for(int index = 0 ; index < vectors.size() ; index++)
	{
		if(vectors[index] != vectors1[index])
			return false;
	}
	return true;
}

bool is_largest(vector<int> vectors)
{
	vector<int> vectors1(vectors);
	sort(vectors1.begin() , vectors1.end() , greater<int>());
	for(int index = 0 ; index < vectors.size() ; index++)
	{
		if(vectors[index] != vectors1[index])
			return false;
	}
	return true;
}

vector<int> get_next_permutation(vector<int> &vectors)
{
	//check if the permutation is the smallest or the largest vector possible 
	bool smallest = is_smallest(vectors);
	bool largest  = is_largest(vectors);

	if(smallest)
	{
		//if the vector is the smallest element , then we need to get the next bigger element and then swap the position 
		swap(vectors[0] , vectors[1]);
	}
	else if(largest)
	{
		//we  then need to return the sorted array in the acending order 
		sort(vectors.begin() , vectors.end());
	}
	else
	{
		//if this is the general case then also 
		//we need to get the pivot 
		int pivot = 0 ;
		for(int index = 0 ; index < vectors.size()-1 ; index++)
		{
			if(vectors[index] < vectors[index+1])
				continue;
			else
			{
				pivot = index ;
			}
		}
		//next we get the smallest element from that pivot until the end 
		int min_element = INT_MAX;
		int min_index = pivot+1 ;
		for(int index = pivot+1 ; index< vectors.size() ; index++)
		{
			if(vectors[index] < min_element)
			{
				min_element = vectors[index];
				min_index = index;
			}
		}
		//after this swap the pivot element with the number at the min_index
		swap(vectors[pivot] , vectors[min_index]);
	}
	return vectors;
}