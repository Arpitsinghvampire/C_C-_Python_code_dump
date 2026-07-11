//maximum_sum_non_adjacent.cpp

//here we would be given a vector , we would have to find the maximum sum of non adjacent elements 
#include<iostream>
#include<vector>

using namespace std;


int max_sum(vector<int> &s1 ,int index ,  int number1 )
{
	if(index >= number1)    //base case 
		return 0;

	
	//either take or do not take 
	//when you take the element 
	int taken = s1[index]+ max_sum(s1 , index +2 ,number1); //traversal  gives us the correct answer
	int not_taken = max_sum(s1 , index+1 , number1);

	return max(taken , not_taken); //then combine the answers 
}

void dp_approach(vector<int> &s1 , vector<int> &dp , int index , int number ) //for each index we will find the max sum for that index
{
	if(index > number)
		return ;
	if(index == 0)
		dp[index] = s1[index];
	if(index == 1)
		dp[index] = max(s1[index] , s1[index-1]);
	else
		dp[index] = max(dp[index-1] , dp[index-2] + s1[index]); //if the previous element is taken then you cant 
	//take the new data ,
	//but if you dont take the previous element you can take the current + the previous of the previous 
	dp_approach(s1 , dp , index+1 , number);
	return ;

}
int main()
{
	vector<int> s1;
	
	cout<<"ENTER THE NUMBER OF ELEMENTS YOU WANT ::  "<<endl;
	int number ;
	cin>>number ;
	vector<int> dp(number+1 , 0);
	for(int index = 0 ; index < number ; index++)
	{
		cout<<"ENTER THE NUMBER YOU WANT TO PUSH  :: " <<endl;
		int number1;
		cin>>number1;

		s1.push_back(number1);
	}

	int result = max_sum(s1 , 0 ,  number);
	cout<<"THE MAX SUM IS "<<result;

	dp_approach(s1 ,dp , 0 , number);
	cout<<"THE MAX FOR THE PARTICULAR INDEX GAINED IS "<<dp[number-1];
}