//nearest_smaller_element.cpp

//in this question we will have to  return the nearest smaller element on the left hand side 
//so we will start from the left hand side , to get the idea of what all elements are to its left
#include<iostream>
#include<stack>
using namespace std;

void nearest_smaller_element(vector<int> s)
{
	vector<int> result ;
	stack<int> s1 ;


	for(int index = 0 ; index < s.size() ; index++)
	{
		if(index == 0)
		{
			result.push_back(-1);
			s1.push(s[index]);
		}
		else
		{
			//we use the same approach as we used to find the next greater element , but here we will pop when we get an element 
			//greater than that number and if the resulting stack is empty then return -1 
			if(s1.top()<s[index])
			{
				//we need to return that number 
				result.push_back(s1.top());
				s1.push(s[index]);
			}
			else
			{
				//this encompasses the case where the top is greater than or equal to the index number 
				//in this case we need to keep popping the number until we find the smaller number 
				while(!s1.empty() && s1.top() >= s[index])
				{
					s1.pop();
				}
				//if the stack is empty that means no smaller element that that 
				if(s1.empty())
				{
					result.push_back(-1);
					s1.push(s[index]);
				}
				else
				{
					result.push_back(s1.top());
					s1.push(s[index]);
				}
			}
		}
	}
	//after this return the result array you got 
	for(int x : result)
	{
		cout<<x<<endl;
	}
}

int main()
{
	vector<int> s2 {4,5,2,10,8};

	nearest_smaller_element(s2);

}