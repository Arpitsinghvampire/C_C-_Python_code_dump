#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

vector<int> union_function(vector<int> s , vector<int> s1)
{
    vector<int> result_vector;
    set<int> set_s;
    map<int ,int>  frequency_mapping ;
    for(int x : s)
    set_s.insert(x);
    for(int x: s1)
    set_s.insert(x);

    // now we have the different elements in the vector  , now also take the frequency 
    for(int index1 = 0  ; index1 < s.size() ; index1++)
    {
        frequency_mapping[s[index1]] +=1;
    }
    
    for(int index1 = 0  ; index1 < s1.size() ; index1++)
    {
        frequency_mapping[s1[index1]] +=1;
    }
    // now we simply write the numbers the times they appear
    for(int index =0 ; index<s.size() ; index++)
    {
        int temp = s[index];
        int count = 0 ;
        //now we have to push that many times 
        while(count!= frequency_mapping[temp])
        {
            result_vector.push_back(temp);
            count++;
        }
    }

    return result_vector;
}

int main()
{
    vector<int> s {1,2,3,3,4,5};
    vector<int> s1 {2,3,4,1};

    vector<int> union_vector = union_function(s , s1);

    for(int x : union_vector)
    cout<<x<<endl;
}