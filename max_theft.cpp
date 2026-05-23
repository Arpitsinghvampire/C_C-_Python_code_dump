#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> find_non_neighbourhoods(vector<int> s , int number)
{
    cout<<"THIS IS THE FIND NON NEIGHBOURHOOD PART "<<endl;
    if(number == 0)
    {
        if(s.size() > 2)
        {
            s.erase(s.begin());
            s.erase(s.begin() + 1);
        }

        if(!s.empty())
            s.pop_back();
    }
    else
    {
        if(s.size() > 1)
            s.erase(s.begin() + 1);
    }

    for(int x : s)
    {
        cout<<x ;
    }

    return s;
}

vector<int> not_steal_part(vector<int> s)
{
    if(!s.empty())
        s.erase(s.begin());

    cout<<"THIS IS THE NOT STEAL PART "<<endl;
    for(int x : s)
    {
        cout<<x;
    }

    return s;
}

int max_theft(vector<int> s , int number)
{
    

    if(s.size() == 0)
        return 0;

    if(s.size() == 1)
        return s[0];

    int reward = s[0];

    if(number == 0)
    {
        cout<<"the reward recieved in this part is given by "<<reward <<endl;
        return max(
            reward + max_theft(find_non_neighbourhoods(s , 0), 1),
            max_theft(not_steal_part(s), number)
        );
    }
    else
    {
        cout<<"THE REWARD RECIEVED IN THIS PART IS GIVEN BY "<<reward<<endl;
        return max(
            reward + max_theft(find_non_neighbourhoods(s , number), number),
            max_theft(not_steal_part(s), number)
        );
    }
}

int main()
{
    vector<int> s {2,1,4,9};

    int output_number = max_theft(s , 0);

    cout << output_number;
}