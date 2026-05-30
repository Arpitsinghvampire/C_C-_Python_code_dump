//house_robber.cpp

#include<iostream>
#include<vector>

using namespace std;

int house_robber(vector<int> s , int index , int low) //we will use the memoization approach which is the top to bottom
{
	int picked = 0 ;
	int non_picked = 0 ;

	if(index == 0 || index == low)
	{
		return s[index];
	}

	else if (index < 0)
		return  0 ;
	else
	{
		//if you pick the last element then you need to update both the low and the index 
		//else if you pick any non last last element , you would only need to update the index 
		if(index == s.size()-1)
		{
			picked =  s[index] + house_robber(s , index-2 , low+1); // you will update the value of low for only 1 instance 
			non_picked = house_robber(s , index-1 , low);
		}

		else
		{
			//the index is not the last index 
			picked = s[index] + house_robber(s , index-2 , low);
			non_picked = s[index] + house_robber(s , index - 1 , low );
		}
	}

	return max(picked , non_picked);

}



int main()
{
	vector<int> s {23 ,34 , 10 , 0 , 1 , 0 , 0 , 9};

	int counter = house_robber(s , s.size()-1 , 0 );

	cout<<counter<<endl;
}