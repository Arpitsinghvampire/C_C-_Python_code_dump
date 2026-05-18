#include<iostream>

using namespace std;

int consecutive_ones(vector<int> s)
{
    int max_count = 0;
    int count =0 ;
    for(int i =0 ;i< s.size() ; i++)
    {
        if(s[i] == 1)
        {
        ++count;
        if(max_count< count)
        max_count = count ;
        }
        
        else
        count = 0;
    }

    return max_count;
}

int main()
{
    vector<int> binary_numbers { 1,0 , 1 , 1  ,1 , 1 , 0 , 0, 0, 1 , 1 , 0 , 0  ,1 , 0};
    int max_count = consecutive_ones(binary_numbers);

    cout<<max_count;
}