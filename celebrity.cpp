//celebrity.cpp
//in this question we have to find the  celebrity given the array of array 
//a celebrity is a person , whom everybody knows but he does not know anyone 

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void find_celebrity(vector<vector<int>> s) //this is the basic approach which one can follow 
{
	//here we will use two arrrays ;
	//one is know me array and the other is i know array 
	vector<int> i_know_array (s.size() , 0);
	vector<int> know_me_array (s.size() , 0);

	for(int index = 0 ; index < s.size() ; index++)
	{
		for(int index1 = 0 ; index1 < s[index].size() ; index1++)
		{
			if(s[index][index1] != 0)
				{
					i_know_array[index] ++;
					know_me_array[index1] ++ ;
				}	
		}
	}

	//in the end you just have to return the array who everybody knows except himself , but he does not know anyone 
	for(int index = 0 ; index < s.size() ; index++)
	{
		if(i_know_array[index] == 0)
		{
			cout<<"Person "<<index<<" is the celebrity"<<endl;
		}
	}
}
//the above approach is a polytime complexity , we now want to reduce the time complexity of such model 
void better_celebrity_finding(vector<vector<int>> s)
{
	//the oen thing to note here is that if a person knows any other person then that person is not a celebrity 
	//so we will make use of this approach , for this purpose we will use two pointers one is the up pointer and the other 
	//is the down pointer . The down pointer points to thte last and the up pointer points to the first position 
	int up = 0 ;
	int down = s.size()-1; //the last index

	while(up!= down)
	{
		if(s[up][down] != 0)
			//that means the up cannot be a celebrity
		{
			//thus we increase the up by 1 unit 
			up++;
		}
		else if(s[down][up] != 0)
		{
			//that means down knows up , and hence down cannot be a celebrity
			down--;
		}
	}
	cout<<"The person "<<up<<" is the celebrity"<<endl;
}

int main()
{
	vector<vector<int>> s {{0,1,1,0} , {0,0,0,0} , {0,1,0,0} ,{1,1,0,0}};

	find_celebrity(s);

	better_celebrity_finding(s);


}