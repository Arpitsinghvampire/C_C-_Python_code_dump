//stock_span_problem.cpp

//here in this questio we would want to know the max number of consecutive days for the which thte current day price is greater than or
//equal to previous days price 

//stock_span_problem.cpp

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void max_consecutive_days(const vector<int>& s)
{
    stack<int> s2;
    int max_length = 0;
    int lowest_stack_element;

    for(int index = s.size() - 1; index >= 0; index--)
    {
        if(s2.empty())
        {
            s2.push(s[index]);
            lowest_stack_element = s[index]; //here in this question wwe wont be compariing with the top element 
            //instead wew will be comparing with the last elemetn to see ehterthe the recent number ot be added is glesser than that number 

        }
        else
        {
            if(lowest_stack_element >= s[index])
            {
                s2.push(s[index]); //if hte current element is lesser than the last element then we push the lement onto the stack 
            }
            else
            {
                // Reset the counter for the current stack
                int current_stack_length = 0; //as soon as a bigger element than the last element arrives we have to pop the stack 

                while(!s2.empty())
                {
                    s2.pop();
                    current_stack_length++;
                }

                max_length = max(max_length, current_stack_length);

                // Start a new stack
                lowest_stack_element = s[index];
                s2.push(s[index]);
            }
        }
    }

    // Count the last remaining stack
    max_length = max(max_length, (int)s2.size());

    cout << "THE MAX CONSECUTIVE DAYS FOR WHICH THE CURRENT DAY STOCK PRICE IS GREATER THAN OR EQUAL TO PREVIOUS DAYS IS "
         << max_length << endl;
}

int main()
{
    vector<int> s{7,2,1,3,3,1,8};

    max_consecutive_days(s);

    return 0;
}