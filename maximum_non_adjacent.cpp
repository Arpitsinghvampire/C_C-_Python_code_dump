//maximum_non_adjacent.cpp
#include<iostream>
#include<vector>

using namespace std;

int  max_non_adjacent_sum(vector<int> s , int index) //this is the memoization approach (top to bottom approach)
{
	//there are only two cases either you choose the index or you dont 
	//now give the base case 
	int picked = 0;
	int non_picked = 0 ;
	if(index == 0)
		return s[0] ;
	else if(index<0)
		return 0 ;

	else
	{
		picked = s[index] + max_non_adjacent_sum(s,index-2);
		non_picked = 0 + max_non_adjacent_sum(s , index-1 );
	}

	return max(picked , non_picked);
	
}


int main()
{
	vector<int> s { 23,34,45,1,0 , 0 , 9};

	int final_output = max_non_adjacent_sum(s , s.size()-1);

	cout<<final_output<<endl;
}