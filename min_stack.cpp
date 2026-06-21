//min_stack.cpp

//here in this question we have to get the minimum of the stack 

#include<iostream>
#include<stack>

using namespace std;

int main()
{
	stack<int> s1;
	stack<int> s2;

	cout<<"ENTER THE NUMBERS YOU WANT TO CHECK AND FIND THE MIN OF  ,PRESS -1 TO STOP TAKING THE INPUT "<<endl;

	while(true)
	{
		int number ;
		cin>> number ;
		if(number == -1)
		{
			break;
		}
		else
		{
			if(s1.empty())
			{
				s1.push(number);
				//intially both the stacks will be empty
				if(s2.empty())
				{
					s2.push(number);
				}
			}
			else
			{
				//we compare the top of the stack with the number if the number is less , we pop the top and then add the element 
				if(number < s1.top())
				{
					//pop the element , and then push the min element 
					s1.pop();
					s1.push(number);
				}
				if(number >s2.top())
				{
					s2.pop()
						s2.push(number);
				}
			}
		}
	}
	//after doing this procedure , we get the top element , and that element would be our min element 
	cout<<"THE MIN ELEMENT FOR THE STACK IS "<<s1.top()<<endl;

	cout<<"THE MAX ELEMENT FOR THE STACK IS  "<<s2.top()<<endl;
}
