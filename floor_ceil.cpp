#include<iostream>
#include<vector>

using namespace std;
vector<int> get_floor_ceil(vector<int> s , int x)
{
    // lets focus on getting the floor value , floor is the smallest number greater than that number x 
    vector<int> result ;
    int low = 0 ;
    int high = s.size()-1;
    int ans = 0;
    while(low<= high)
    {
        
       if( s[(low+high)/2] >=x)
        {
            ans = s[(low+high)/2];
            high = (low+high)/2 - 1;
        }

        else
        {
            low = (low+high)/2 + 1;
        }
    }
    result.push_back(ans);

    // now we want to  similarly find the ceil value 

    int ans1 = -1 ;
    low = 0 ; high = s.size();
    while(low<=high)
    {
        if(s[(low+high)/2] <= x)
        {
            ans1 = s[(low+high)/2]; // potential answer 
            high = (low+high)/2 -1 ;
        }
        else
        {
            low = (low+high)/2 +1 ;
        }


    }

    result.push_back(ans1);

    return result ;

}

int main()
{   
    vector<int> s {12 ,14 ,16 , 29 , 31};
    vector<int> result = get_floor_ceil(s , 31);

    for(int x : result)
    {
        cout<<x<<endl;
    }

}