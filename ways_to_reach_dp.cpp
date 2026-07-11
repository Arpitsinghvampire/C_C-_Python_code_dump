//ways_to_reach_dp.cpp

//here we would be given the nmber of stairs , we have to find the number of ways by which a person can reach the 
//n stairs 
//you can take either two stairs or one stairs at a time 
#include<iostream>
#include<vector>

using namespace std;

void number_of_ways(vector<int> &s1 , int index , int number)
{
	if(index > number)
		return ;
	else if(index == 0 || index == 1)
		s1[index] = 1;
	else
		s1[index] = s1[index-1] + s1[index-2]; //since thy can take two or one step at a time 

	//now traverse the loop 
	number_of_ways(s1 , index+1 , number);
}


int main()
{
	cout<<"ENTER THE NUMBER OF STAIRS YOU HAVE "<<endl;
	int number ;
	cin>>number ;

	vector<int> s1(number+1 , 0);

	number_of_ways(s1 , 0 , number);
	cout<<"THE NUMBER OF WAYS OF TRAVELLING THE STAIRS IS "<<s1[number];


}