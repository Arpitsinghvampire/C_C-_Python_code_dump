//print_divisors.cpp

#include<iostream>
#include<vector>

using namespace std;

vector<int> divisors(int n)
{
	//brute force approach is that all the divisors would lie int the range of 1 to number itself , so we loop  till we reach the number
	vector<int> result ;
	for(int index = 1 ; index <n+1 ; index++)
	{
		if(n%index == 0)
			result.push_back(index);
	}
	return result ;
}

// here we will look up with another  optimized version of the divisors , instead of going till n , we go till n^0.5 , because after that the 
//divisor will rise and the other factor will reduce 

vector<int> optimized_divisors(double n)
{
	vector<int> result ;

	for(double index = 1 ; index <=n**0.5 ; index++)
	{
		if(n%index == 0)
			result.push_back(index);

	}
	return result ;
}

int main()
{
	vector<int> results;

	int number ;
	cout<<"ENTER THE NUMBER FOR WHICH YOU WANT TO FIND THE DIVISORS "<<endl;

	cin>>number ;

	cout<<"THE DIVISORS  OF THE NUMBER ARE ";

	results = divisors(number);

	for(int index = 0 ; index <results.size() ;index++)
	{
		cout<<results[index];
		if(index != results.size()-1)
			cout<<",";
	}

	number = double(number);

	cout<<"THE DIVISORS FROM THE OPTIMIZED VERSION IS GIVEN BY "<<endl;

	results = optimized_divisors(number);

	cout<<endl;

		for(int index = 0 ; index <results.size() ;index++)
	{
		cout<<results[index];
		if(index != results.size()-1)
			cout<<",";
	}

}