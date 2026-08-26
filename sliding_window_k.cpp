#include<iostream>
#include<vector>
#include<stack>

using namespace std;


vector<int>  sliding_window(vector<int> slides_vectors , int k )
{
	vector<int> result ;
	stack<int> s1;
	for(int starting_index= 0 ; starting_index <=slides_vectors.size()-k ; starting_index++)
	{
		int ending_index = starting_index+k ;

		for(int index = starting_index ; index < ending_index ; index++)
		{
			if(s1.empty())
			{
				//you need to push the element 
				s1.push(slides_vectors[index]);
			}
			else
			{
				//if the next element is smaller than the top then we do not push 
				if(slides_vectors[index] > s1.top())
				{
					//we push into the stack 
					s1.pop();
					s1.push(slides_vectors[index]);
				}
				//if the element is smaller then we do not push the element into the stack 
			}
		}
		//after getting the highest element for the segment , we need to see whether the largest element is the element that will be removed or not 
		//first of all push the answer into the vector 
		result.push_back(s1.top());
		//we then need to see whether that element is the element to be removed or not 
		if(s1.top() == slides_vectors[starting_index])
		{
			//we need to pop the element 
			s1.pop();
		}
		//if not then we do not need to do anything 
	}
	return result ;
}
int main()
{
	vector<int> s1{4, 0, -1, 3, 5, 3, 6, 8};

	vector<int> result = sliding_window(s1, 3);

	for(int x: result)
		cout<<x<<endl;
}