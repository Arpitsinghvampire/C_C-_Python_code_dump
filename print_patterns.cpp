#include<iostream>
#include<vector>

using namespace std;

void print_pattern(int n)
{
	for(int row = 0 ; row < n ; row++)
	{
		if(row != 0)
			cout<<endl;
		for(int column = 0 ; column < n ; column++)
		{
			cout<<"*";
		}
	}
}
int main()
{
	print_pattern(5);
}