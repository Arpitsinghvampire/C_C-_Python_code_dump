//sum_first_n.cpp

#include<iostream>
#include<vector>

using namespace std;

int return_sum(int n)
{
	if (n==0)
		return 0 ; //specify the base case scenario
	else
	return n+return_sum(n-1);
}

//parameterized way 
int return_sum_parameter(int n  , int sum )
{
	// we start from bottom up that is from n 
	if(n==0)
		return sum ;
	else
	{
		return return_sum_parameter(n-1 , sum+n);
	}

}

// now lets calculate the factorial of the above part 
int factorial_paramterized(int n , int factorial )
{
	if(n==1)
		return factorial ;
	else
	{
		return factorial_paramterized(n-1 , factorial*n);
	}
}

int factorial_functional(int n)
{
	if(n==1)
		return 1;
	else
		return n*factorial_functional(n-1);
}


int main()
{
	int  final_sum = return_sum(100);

	cout<<final_sum<<endl;

	int final_sum_par = return_sum_parameter(100 , 0);

	cout<<final_sum_par<<endl;


	//now lets calculate the factorial of the function

	int fact_result_par = factorial_paramterized(4,1);

	cout<<fact_result_par<<endl;

	int fact_result_par1 = factorial_functional(4 );

	cout<<fact_result_par1<<endl;
}