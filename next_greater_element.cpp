//next_greater_element.cpp

//in this code ,we have to find the next greater element for each index 
#include<iostream>

using namespace std;

//we will now use the stack approach for solving the above problem 
void reverse_element(vector<int> s)
{
	vector<int> result ;
	stack<int> s1;
	for(int index = s.size()-1 ; index>=0 ; index--)
	{
		if(index == s.size()-1)
		{
			result.push_back(-1);
			s1.push(s[index]);
		}
		else
		{
			if(s[index] < s1.top())
			{
				
				result.push_back(s1.top());
				s1.push(s[index]);
			}
			else
			{
				while(!s1.empty() && s1.top()<=s[index])
				{
					cout<<"popped values "<<s1.top()<<endl;
					s1.pop();
				}
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

	cout<<"THE NEW OUTPUT IS "<<endl;
	//we then print the result in the reverse order 
	for(int index  = result.size()-1 ; index >=0 ; index--)
	{
		cout<<result[index]<<endl;
	}
}

int main()
{
	vector<int> given_vector {6,0,8,1,3};
	vector<int> result ;

	for(int index = 0 ; index <given_vector.size() ;index++)
	{
		int flag = 0 ;
		for(int index1 = index+1 ; index1<given_vector.size() ;index1++)
		{
			if(given_vector[index]<given_vector[index1])
			{
				result.push_back(given_vector[index1]);
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			result.push_back(-1);

	}

	for(int x: result)
	{
		cout<<x<<endl;
	}

	//now lets use the stack approach and then observe what we got 
	reverse_element(given_vector);
}