//trapping_rainwater.cpp

//in thsi question we would need to find the amount of water it  can hold 
//the amount of water it can hold is to find the difference fo left max and the right max - current array element 
//you cannot store water if it is the only building 
/*
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void find_water_holding(vector<int> s)
{
	//we have to find the max of (left side ,right side) - the current element , and then add them to get the rainwater trapped 
	vector<int> prefix_max ;
	vector<int> suffix_max_reverse ;

	stack<int> s1;
	stack<int> s2;

	//lets find the left max first that is the prefix max 
	for(int index = 0 ; index < s.size() ; index++)
	{
		if(index == 0)
		{
			s1.push(s[index]);
			prefix_max.push_back(s[index]);
		}
		else
		{
			//we need to find the max from the left hand side 
			//if the top of the stack is less than the vector index  , then you need to keep popping the stack until you get an element 
			//greater than the  vector[index]
			if(s1.top() <s[index])
			{
				//you need to pop until you get an element greater than that number 
				while(!s1.empty() && s1.top() <= s[index])
				{
					s1.pop();
				}
				//now if the stack is empty that means that the no element greater than that element 
				if(s1.empty())
				{
					//you need to push that index , because that will be the largest element till data 
					s1.push(s[index]);
					prefix_max.push_back(s[index]);
				}
				else
				{
					//if the stack is not empty ,then there is another lement greater than the current element 
					//and we wont push that value there 
					prefix_max.push_back(s[index]);
				}
			}
			else
			{
				//if the top element is greater than or equal to that element , then you need to push into the prefix_max
				prefix_max.push_back(s1.top());
			}
		}
	}
	//after the above process you will get the prefix max , now we need to get the suffix max 
	//start from the right hand side 
	for(int index = s.size()-1 ; index >= 0 ; index--)
	{
		if(index == s.size()-1)
		{
			//we need to push the element into the stack 
			s2.push(s[index]);
			suffix_max_reverse.push_back(s[index]);
		}
		else
		{
			// you have to get the max element from the right hand side
			if(s2.top() < s[index])
			{
				//if the top element is less than the current index , then we continue popping the elements  until  you get the element 
				//greater than that element 
				while(!s2.empty() && s2.top() < s[index])
				{
					s2.pop(); //continue popping until you get the required element 
				}
				if(s2.empty())
				{
					//if the stack becomes emepty than that element will be the largest element , hence put into the stack 
					s2.push(s[index]);
					suffix_max_reverse.push_back(s[index]);
				}
			}
			else
			{
				suffix_max_reverse.push_back(s[index]);
				//we do not then put the element into the stack

			}
		}
	}
	//we then reverse the suffix_max_reverse element 
	vector<int> suffix_max ;
	for(int index = s.size()-1 ; index >= 0 ; index--)
	{
		suffix_max.push_back(s[index]);
	}


	//now after getting the suffix_max and the prefix_max , we now sum the max(left,right) - arr[index]
	int sum = 0 ;
	for(int index1 = 0 ; index1 <s.size() ; index1++)
	{
		if(s[index1] <= suffix_max[index1] && s[index1] <= prefix_max[index1])
		{
			sum += min(suffix_max[index1] , prefix_max[index1]) - s[index1];
		}
	}

	cout<<"THE  RAINWATER TRAPPED HERE IS "<<sum<<endl;

}

int main()
{
	vector<int> s {0,1,0,2,1,0,1,3,2,1,2,1};

	find_water_holding(s);

}
*/
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void find_water_holding(vector<int> s)
{
    vector<int> prefix_max;
    vector<int> suffix_max_reverse;
    vector<int> suffix_max;

    stack<int> s1;
    stack<int> s2;

    // Prefix maximum
    for(int i=0;i<s.size();i++)
    {
        if(s1.empty())
        {
            s1.push(s[i]);
            prefix_max.push_back(s[i]);
        }
        else
        {
            int current_max = max(s1.top(), s[i]);

            s1.push(current_max);

            prefix_max.push_back(current_max);
        }
    }

    // Suffix maximum
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s2.empty())
        {
            s2.push(s[i]);
            suffix_max_reverse.push_back(s[i]);
        }
        else
        {
            int current_max = max(s2.top(), s[i]);

            s2.push(current_max);

            suffix_max_reverse.push_back(current_max);
        }
    }

    // Reverse suffix array
    for(int i=suffix_max_reverse.size()-1;i>=0;i--)
    {
        suffix_max.push_back(suffix_max_reverse[i]);
    }

    int sum = 0;

    for(int i=0;i<s.size();i++)
    {
        sum += min(prefix_max[i], suffix_max[i]) - s[i];
    }

    cout << "THE RAINWATER TRAPPED HERE IS "
         << sum << endl;
}

int main()
{
    vector<int> s{0,1,0,2,1,0,1,3,2,1,2,1};

    find_water_holding(s);
}