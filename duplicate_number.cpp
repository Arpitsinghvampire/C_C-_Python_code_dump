#include<iostream>
#include<vector> 
#include<map>
using namespace std;

void duplicate_number(vector<int> s)
{
    // here we maintain a map 
    map<int , int> frequency_map ;
    for(int index = 0 ; index < s.size() ; index++)
    {
        frequency_map[s[index]] += 1;
    }
    for(auto &[key , value] : frequency_map)
    {
        if(frequency_map[key] == 2)
        cout<< key <<endl ;
    }
}

int main()
{
    vector<int> s1 { 232 , 23, 1, 0 , 12 , 10 , 10 , 19 , 19 ,};
    duplicate_number(s1);
}