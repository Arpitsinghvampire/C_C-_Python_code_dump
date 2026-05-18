#include<iostream>
#include<vector>
#include<map>

using namespace std;

int missing_number(vector<int> s)
{
    map<int,int> cooccurrence_map;

    for(int i = 1; i <= s.size() + 1; i++)
    {
        cooccurrence_map[i] = 0;
    }

    for(int i = 0; i < s.size(); i++)
    {
        cooccurrence_map[s[i]]++;
    }

    for(auto [key,value] : cooccurrence_map)
    {
        if(value == 0)
        {
            return key;
        }
    }

    return -1;
}

int main()
{
    vector<int> s {1,2,3,4,6,5,7,8};

    int missing_numb = missing_number(s);

    cout << missing_numb;
}