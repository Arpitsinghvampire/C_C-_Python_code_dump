#include<vector>
#include<iostream>

using namespace std;

int search_insert_position(int x , vector<int> s)
{
    // first we use the brute force method  , the array given is sorted 
    for(int index = 0 ;index <s.size() ; index++)
    {   
        if(s[index]>=x)
        return index;
    }
    // the programme stops the moment you get a. number greater than the number x 
    return s.size(); // return this part when the number is the largest 

}

// now lets use a more optimized part of the programme 
int search_insert_position_optimized(vector<int> s , int number) // we used  the binary search , here to get the mid index 
{
    int low = 0 ;
    int high = s.size();

    //we will keep doing the binary search operation until and unless we get the reuiqred position 
    while(low <= high)
    {
        if(s[(low+high)/2] > number)
        {
            // we then move towards the first half ;
            //therefore we would  shift the higher side towards the middle element 
            high = (low+high)/2 - 1;
        }

        else if(s[(low+high)/2] <number)
        {
            low = (low + high)/2 + 1; //move towards the right hand side 
        }

        else
        {
            return (low+high)/2;
        }
    }
    return (low+high)/2;
}

int main()
{
    vector<int> s {12,13,14,17,25 , 29 , 40};
    int inserted_position = search_insert_position(14 , s);

    cout<<" THE INSERTED POSITION IS GIVEN AS "<< inserted_position<<endl;

    //using the optimized approach we get the index at which we insert our number 
    cout<<" THE INSERTED POSITION FOR THE OPTIMIZED ALGORITHM IS GIVEN AS " << search_insert_position_optimized(s , 14);
}