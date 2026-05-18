#include<iostream>
#include<vector>

using namespace std;

bool number_found(vector<vector<int>> s , int target) //number of rows number of columns 
{
    for(int i = 0 ; i<s.size() ; i++)
    {
        if(target > s[i][0])
        continue ;

        else
        {
            // we can do either the binary search or the linear search to search for the element 
            for(int j =0 ; j<s[i].size() ; j++)
            {
                if(s[i][j] == target)
                return true ;
            }

        }
    }
    return false ;
}

// now lets do the binary search part in the above algorithm 
bool number_found1(vector<vector<int>> s , int target) //number of rows number of columns 
{
    for(int i = 0 ; i<s.size() ; i++)
    {
        if(target > s[i][0])
        continue ;

        else
        {
            // we can do either the binary search or the linear search to search for the element 
            int start_point = 0;
            int end_point = s[i].size()-1;
            while(start_point<=end_point)
            {
                if(target> s[i][(start_point+end_point)/2])
                end_point = static_cast<int>((start_point+end_point)/2)-1;

                if(target == s[i][(start_point+end_point)/2])
                return true;

                else
                {
                    start_point = static_cast<int>((start_point+end_point)/2)+1;
                }

            }

        }
    }
    return false ;
}

int main()
{
    vector<vector<int>> s1 {{2 , 1 , 0} , {10 , 9 , 9} , {100 , 45 , 1}};

    bool number_there = number_found(s1 , 100);

    cout<< "NUMBER THERE "<<number_there<<endl;

    cout<<"USING THE BINARY SEARCH OPTION "<<endl;

    bool number_there1 = number_found1(s1 , 100);

    cout<<"SEARCH USING BINARY SEARCH NUMBER "<< number_there1<<endl;

}