#include<iostream>
#include<vector>

using namespace std;


vector<vector<int>> pascals_triangle(int n)
{
    vector<vector<int>> result ;
    for(int index =1 ; index <= n; index++)
    {
        vector<int> result1 (index , 1);
        result.push_back(result1);
    }
  // here we have fixed the  structure of the problem we then update the lements of the pascal triangle
    for(int index = 0 ; index <n ; index++)
    {
        if(index > 1)
        {
        for(int i = 1 ; i<result[index].size(); i++)
        {
            result[index][i] = result[index-1][i-1] + result[index-1][i];
        }
        }
    }
     
    return result ;
}

int main()
{
    vector<vector<int>> result1 = pascals_triangle(5);
    for(vector<int> s :  result1)
    {
        for(int x : s)
        {
            cout<<x;
        }
        cout<<endl;
    }
}