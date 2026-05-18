#include<vector>
#include<iostream>

using namespace std;
//lets take the  brute force approach  
vector<vector<int>> sum_exists(vector<int> s , int target)
{   
    vector<vector<int>> required_sum ;
    for(int index = 0 ; index < s.size() ; index++)
    {
        int subtracted_target = target - s[index];
        vector<int> intermediate;
        for(int index1 = 1 ; index1 <s.size() ; index1++)
        {
            
            if(subtracted_target == s[index1])
            {
            intermediate.push_back(index);
            intermediate.push_back(index1);
            required_sum.push_back(intermediate);
            }
        }

        
    }
    return required_sum;
}

int main()
{
    vector<int> s1 { 23 , 34 ,1 ,45, 1, 0 , 12 , 23 , 100};
    int target  = 101 ;

    vector<vector<int>> target1 = sum_exists(s1,target);

    for(vector<int> x : target1)
    {
        cout<<"THE PAIRS ARE "<<endl;
        for(int c : x)
        {
        cout<<c;
        cout<<endl;
        }
    }

}