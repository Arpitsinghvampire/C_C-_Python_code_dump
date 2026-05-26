//print_n_times.cpp

//here we will print the name n times using the recursion
#include<iostream> //this imports all the required library 

using namespace std;

void print_function(int n)
{
	//lets create the base case first 
	if(n==0)
		return;

	cout<<n;
	print_function(n-1);
}

void print_string_n_times(int n)
{
	if(n==0)
		return ;
	cout<<"THIS IS THE "<<n<<"th string "<<endl;
	print_string_n_times(n-1);
}

int main()
{
	print_function(5);

	print_string_n_times(5);
}