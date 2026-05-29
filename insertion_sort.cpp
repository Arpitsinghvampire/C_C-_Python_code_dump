//insertion_sort.cpp
#include<iostream>
#include<vector>
using namespace std;


vector<int> insertion_sorted_array(vector<int> &s)
{
	for(int index = 1 ; index < s.size(); index++)
	{
		for(int index1 = index ; index1 >0 ; index1 --)
		{
			if(s[index1] < s[index1-1])
			{
				//we then need to swap the elements
				int temp = s[index1];
				s[index1] = s[index1-1];
				s[index1-1] = temp;

			}
		}
	}
	return s;
}
int main()
{
    vector<int> s {23 ,34,12,10,11,5,4,3};

    vector<int> s1 = insertion_sorted_array(s);

    for(int x : s1)
    {
    	cout<<x<<endl;
    }
}