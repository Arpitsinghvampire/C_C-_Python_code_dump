//selection_sort.cpp
#include<iostream>
#include<vector>
using namespace std;


vector<int> selection_sort(vector<int> &s)
{
	//find the minimum element for each index after that index and then swap the elements 
	for(int index = 0 ; index < s.size() ; index++)
	{
		//search for the min element after that index 
		int min_element = s[index];
		int j = index;
		for(int index1 = index+1 ; index1 <s.size() ; index1++)
		{
			min_element = min(min_element , s[index1]);
			if(min_element == s[index1])
				j = index1;
		}
		//after getting the min element , we then swap the numbers 
		//now swap the element with the minimum 
		int temp = s[j];
		s[j] = s[index];
		s[index] = temp;

	}

	return s;
}


int main()
{
	vector<int> s {23 ,34 ,1 ,10 , 9 , 0 , 100};

	vector<int> s1 = selection_sort(s);

	for(int x : s1)
	{
		cout<<x<<endl;
	}
}