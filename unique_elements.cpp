#include<vector>
#include<iostream>

using namespace std;


int unique_elements(vector<int> &s)
{
    int i = 0;
   if(s.empty()) return 0 ;
   else
   {
    
    for(int j =1 ; j<s.size() ; j++)
    {
        if(s[i] != s[j])
        {
            ++i ;
            s[i] = s[j];
        }
    }
   }
   return i+1;
}

int main()
{
    //the input is a sorted array 
        vector<int> unique {0,0 ,0, 0 ,1 ,1, 1,2 ,2 ,2,2  ,3,3,3,4,4,4,4,100};

        int number_1 = unique_elements(unique);
        cout<<number_1;
}