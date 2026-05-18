#include<iostream>
#include<vector>

using namespace std;

vector<int> relative_ordering (vector<int> s)// first we use the brute force approach 
{
    vector<int> positive_vector;
    vector<int> negative_vector;
    

    //now we would change the order of the positive and negative ordering  without changing the relative ordering 
    for(int index =0 ;index < s.size() ; index++)
    {
        if(s[index]>0)
        positive_vector.push_back(s[index]);

        else
        negative_vector.push_back(s[index]);
    }
    //now after getting the positive and the negative vectors , we now  create a single list appending both the vector elements 
    vector<int> result ;
   
    for(int index  = 0; index< positive_vector.size() ; index++)
    {
        result.push_back(positive_vector[index]);
        result.push_back(negative_vector[index]);
    }
    return result ;
}

// in this we use the optimized part  for the above algorithm 
vector<int> relative_positioning_optimized(vector<int> s)
{
    vector<int> result ;
    vector<int> :: iterator iter1 = s.begin();
    // the above iterator alwys tries to point towards the  positive element 
    vector<int> :: iterator iter2 = s.begin(); // tries to point towards the negative element 

    while(iter1 != s.end() && iter2 != s.end())
    {
    while(*iter1<0)
    ++iter1;

    while(*iter2>0)
    ++iter2;

    result.push_back(*iter1);
    result.push_back(*iter2);

    // now we increment the iterators  for both the positive and the negative part 
    ++iter1;
    ++iter2;
    }
        return result ;
}

int main()
{
    vector<int> result  { 10, -10 , 3, 4, 5, -5 , -4 , -3 , 45 , -12 , 12 ,10 };

    vector<int> result1 = relative_ordering (result);

    for(int x : result1)
    cout<< x<<endl;

    cout<<endl;
    cout<<endl;
    //now we use the optimized part for  the above algorithm 
    vector<int> result2 = relative_positioning_optimized(result);

    for(int x : result2)
    cout<< x <<endl;

}