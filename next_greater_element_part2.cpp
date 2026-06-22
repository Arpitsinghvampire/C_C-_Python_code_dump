//next_greater_element_part2.cpp

//in this question we would be looking for the greater element in the circular  part , that is if we do not find the  largest element 
//until the end , we would keep looking in the circular fashion that is start from the starting of the queue and then find it 
#include<iostream>
#include<stack>
#include<vector>

using namespace std;


//lets first get the elements for which we wont have to traverse back  , that is elements having non -1 


//we will now use the stack approach for solving the above problem 
void reverse_element(vector<int> s)
{
	vector<int> result ;
	vector<int> reverse_result ;
	stack<int> s1;
	for(int index = s.size()-1 ; index>=0 ; index--)
	{
		if(index == s.size()-1)
		{
			//find the  first max element greater than that number 
			for(int index1 = 0 ; index1 <s.size() ; index1++)
			{
				if(s[index1] > s[index])
				{
					//push the element onto the stack and then push the  last element you had 
					s1.push(s[index1]);
					break; //break from the loop
				}
			}
			if(s1.empty())
			{
				result.push_back(-1);
			}
			else
			{
				//then push the topmost element 
				result.push_back(s1.top());
			}
			//now push the index 
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
	//now we have the reverse result , now lets only focus on the elements having the -1 as the next greater element 
	//so the elements still having -1 means that either it is rightmost element or the largest element is towards its left 
	//we now traverse from the front 
	
}

int main()
{
	vector<int> given_vector {6,0,8,1,9};
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

