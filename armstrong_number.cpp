//armstrong_number.cpp

//if the sum of the cube of the digits is equal to that number , then that number is called an Armstrong number 
#include<iostream>
#include<vector>

#include<iomanip>

using namespace std;

bool is_armstrong(int n)
{
	int sum = 0 ;

	int n1= n;

	if(n == 0)
	{
		return true;
	}

	while(n1>0)
		{
			sum += (n1%10)*(n1%10)*(n1%10);
			n1 = n1/10;
		}
	
	if(sum == n)
		return true;
	
	return false;
}

int main()
{
 	int number ;
 	cout<<"enter the number you want to check for the armstrong number :: "<<endl;

 	cin>>number;

 	int yes_or_no = is_armstrong(number);

 	cout<<yes_or_no;

 	if(yes_or_no)
		cout<<"THE NUMBER "<<number<< "is armstrong number "<<endl;
	else
		cout<<"THE NUMBER IS NOT AN ARMSTRONG NUMBER "<<endl;
}