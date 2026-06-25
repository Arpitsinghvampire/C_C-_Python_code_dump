//largest_rectangle.cpp
//in this question we would be given some bar graphs , we have to find the maximal length bar chart which can fit into it 
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// we can continue taking that length until we get a smaller element in its right  and to its left 
// we then multiply the length to whichit applies  to the number (which represents its contribution)
//here for eahc index , we will find the previous smaller index 
vector<int> last_smaller_index(vector<int> s)
{
	stack<int> s1; //this stores the index to the last smaller value
	vector<int> smaller_index_vector ;

	for(int index = 0 ;index <s.size() ; index++)
	{
		if(index == 0)
		{
			smaller_index_vector.push_back(index);
			s1.push(index);
		}
		else
		{
			if(s[s1.top()] >= s[index])
			{
				while(!s1.empty() && s[s1.top()] > s[index])
				{
					s1.pop();
				}
				if(s1.empty())
				{
					s1.push(index);
					smaller_index_vector.push_back(index);
				}
				else
				{
					smaller_index_vector.push_back(s1.top());
					//but we would need to push the element into the stack 
					s1.push(index); //this might be the smaller index for the next index 
				}
			}
			else 
			{
				smaller_index_vector.push_back(s1.top());
				s1.push(index);
			}

		}
	}

	return smaller_index_vector;

}

//now we also need to find the next smaller index value for all the index so that i can find the length  of the rectangle
vector<int> next_smaller_element(vector<int> s)
{
	vector<int> next_smaller_index_vector_reverse;
	stack<int> s1; //we store the index here to get the value 

	for(int index = s.size()-1 ; index >=0 ; index--)
	{
		if(index == s.size()-1)
		{
			//we start from the right hand side 
			next_smaller_index_vector_reverse.push_back(index);
			s1.push(index);
		}
		else
		{
			if(s[index] < s[s1.top()])
			{
				//we need to remove elements from the stack 
				while(!s1.empty() && s[index] < s[s1.top()])
				{
					s1.pop();
				}
				if(s1.empty())
				{
					//we would need to push in the element 
					s1.push(index);
					next_smaller_index_vector_reverse.push_back(index);
				}
				else
				{
					next_smaller_index_vector_reverse.push_back(s1.top());
					//we also need to push the lement into the stack , because it might be the smaller number 
					s1.push(index);
				}
			}
			else
			{
				next_smaller_index_vector_reverse.push_back(s1.top()); //smaller index is the top of the stack 
				//push the index also , it might be the smaller number 
				s1.push(index);

			}
		}
	}
	//so from here we would get the next smaller element 
	//we need to reverse the array 
	vector<int> next_smaller;
	for(int index = s.size()-1 ; index >= 0 ; index--)
	{
		next_smaller.push_back(next_smaller_index_vector_reverse[index]);
	}

	return next_smaller;

}

//so now  we have the next smaller element and the previous smaller element , we now want to get the maximum size that can be 
//fit
void max_length(vector<int> s)
{
	vector<int> last_small_index = last_smaller_index(s);
	vector<int> next_small_index = next_smaller_element(s);

	//after getting the last smaller index ans the next small index , lets now get the max contribution we can get 
	int max_contribution ;
	for(int index = 0 ; index <s.size() ;index++)
	{
		int contri = s[index]* (next_small_index[index] - last_small_index[index]-1) ;
		max_contribution = max(max_contribution , contri);
	}
	cout<<"THIS IS THE PREV SMALL INDEX" <<endl;
	for(int x : last_small_index)
	{
		cout<<x<<endl;
	}

	cout<<"THIS IS THE NEXT SMALL INDEX "<<endl;
	for(int x : next_small_index)
	{
		cout<<x<<endl;
	}

	cout<<"THE MAX CONTRIBUTION IS GIVEN AS "<< max_contribution<<endl;
}

int main()
{
	vector<int> s {2,1,5,6,2,3};

	max_length(s);
}