//asteroid_collision.cpp

//here we will be given some elements in the arrays , pertaining to the weight of the asteroid , we need to find whether the asteroid goes to 
//left or the right
#include<iostream>
#include<vector>
#include<stack>
#include<cmath>

using namespace std;

void asteroid_prediction(vector<int> s)
{
    stack<int> s1;

    for(int index = 0; index < s.size(); index++)
    {
        if(index == 0)
        {
            s1.push(s[index]);
        }
        else
        {
            if(s1.empty())
            {
                s1.push(s[index]);
            }
            else if(s[index] * s1.top() > 0)
            {
                s1.push(s[index]);
            }
            else
            {
                if(s1.top() > 0 && s[index] < 0)
                {
                    if(s1.top() > abs(s[index]))
                    {
                        continue;
                    }
                    else
                    {
                        while(!s1.empty() &&
                              s1.top() * s[index] < 0 &&
                              s1.top() < abs(s[index]))
                        {
                            s1.pop();
                        }

                        if(s1.empty())
                        {
                            s1.push(s[index]);
                        }
                        else
                        {
                            if(s1.top() * s[index] > 0)
                            {
                                s1.push(s[index]);
                            }
                            else if(s1.top() == abs(s[index]))
                            {
                            	s1.pop();
                            }
                            else
                            {
                            	continue;
                            }
                        }
                    }
                }
                else
                {
                    if(!s1.empty() && abs(s1.top()) > s[index])
                    {
                        continue;
                    }
                    else
                    {
                        while(!s1.empty() &&
                              s1.top() * s[index] < 0 &&
                              abs(s1.top()) < s[index])
                        {
                            s1.pop();
                        }

                        if(s1.empty())
                        {
                            s1.push(s[index]);
                        }
                        else
                        {
                            if(s1.top() * s[index] > 0)
                            {
                                s1.push(s[index]);
                            }
                            else if(abs(s1.top()) == s[index])
                            {
                            	s1.pop();
                            }
                        }
                    }
                }
            }
        }

        cout << "THE STACK ELEMENTS AFTER THE "
             << index + 1
             << " th pass are\n";

        // Print without destroying original stack
        stack<int> temp = s1;
        stack<int> reverse_stack;

        while(!temp.empty())
        {
            reverse_stack.push(temp.top());
            temp.pop();
        }

        while(!reverse_stack.empty())
        {
            cout << reverse_stack.top() << endl;
            reverse_stack.pop();
        }

        cout << "------------------" << endl;
    }

    cout << "\nFINAL STACK\n";

    stack<int> temp = s1;
    stack<int> reverse_stack;

    while(!temp.empty())
    {
        reverse_stack.push(temp.top());
        temp.pop();
    }

    while(!reverse_stack.empty())
    {
        cout << reverse_stack.top() << endl;
        reverse_stack.pop();
    }
}

int main()
{
    vector<int> s {4,7,1,1,2,-3,-7,17,15,-16};

    asteroid_prediction(s);

    return 0;
}