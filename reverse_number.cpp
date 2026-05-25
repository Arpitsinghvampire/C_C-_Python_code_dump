//reverse_number.cpp
#include<iostream>
#include<iomanip>

using namespace std;


int return_reverse_number(int n)
{
	int reverse =0  ;

	while(n>0)
	{
		int current = n%10;

		reverse = 10*reverse + current;

		n = n/10;
	}

	return reverse ;
}
int main()
{
	 int number ;

	 cout<<"ENTER THE NUMBER YOU WANT TO REVERSE "<<endl;

	 cin>>number ;

	 cout<<"THE REVERSED NUMBER IS GIVEN BY "<<return_reverse_number(number)<<endl;


}