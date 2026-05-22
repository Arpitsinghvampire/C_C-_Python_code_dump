#include<iostream>
#include<vector> 

using namespace std;

int different_climbing_stairs(int n)
{
	// we have n stairs , we need to find the number of ways in which we can  climb the stairs 
	// we can either take 1 step or 2 steps 
	// we use the memoization approach ( top to bottom approach)
	if(n<=2)
		return n;
	else
	{
		// we need to return  the sum of ways of n-1 and n-2  
		// you can take either 1 step or 2 step towards the last leg of the journey 
		return different_climbing_stairs(n-1)+ different_climbing_stairs(n-2);
		// take either 1 step or 2 step in the last leg 
	}
}

int main()
{
   int n ;
   cout<< "ENTER THE NUMBER OF STAIRS YOU WANT " << endl;
   cin>> n ;

   int number_of_ways = different_climbing_stairs(n);

   cout<<number_of_ways<<endl;
}