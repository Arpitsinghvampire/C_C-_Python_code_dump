#include<iostream>
using namespace std;

int main()
{
//here we want to find the sum of teh variable number of variables given by the user 
//since all the values inputted by the user is stored in the input stream  , we use that concept 

    int sum =0 , value ;

    while(cin>>value)
    {
        sum +=value ;
    }
    cout<<"The final variable of the sum of the variable num of variables is " <<sum;
}