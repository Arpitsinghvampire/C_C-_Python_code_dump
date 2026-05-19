#include<iostream>
#include<vector>

using namespace std;

//this vector is sorted vector and does not have any duplicates 
bool element_found(vector<int> s , int target)
{
    // we will solve this question using the iterator 
    vector<int> ::iterator iter_begin = s.begin();
    vector<int> :: iterator iter_end = s.end();
    vector<int> :: iterator iter_mid = iter_begin + (iter_end-iter_begin)/2;
    // now we do the binary search ;
    while(iter_begin <= iter_end)
    {
        vector<int> :: iterator iter_mid = iter_begin + (iter_end-iter_begin)/2;
        if(*iter_mid > target)
        iter_end = iter_mid-1;

        else if(*iter_mid < target)
        iter_begin = iter_mid+1;

        else
        return true ;
    }

    return false;
}

int main()
{
    vector<int> s {12,13,14,15 , 29 , 35};
    bool element1 = element_found(s , 36);

   if(element1 == 0)
   cout<< "THE ELEMENT WAS NOT FOUND";
   else
   cout<<"THE ELEMENT WAS FOUND "; 

}