#include<iostream>
#include<string>

using namespace std ;

void swap(int i , int j)
{
    int tmp = j ;
    j = i ;
    i = tmp;

    cout<<"the new value  of i in the function is "<<i;
    cout<<"The new value of j in the function  is "<<j;
}

int main()
{
    int i , j ;
    cout<<"ENTER THE VALUES  YOU WANT FOR I AND J ";
    cin>>i>>j;

    cout<<"VALUES BEFORE THE SWAP IS "<<i<<" and "<<j;
    //we then swap the values 

    swap(i , j);

    cout<<"THE NEW VALUE OF I OUTSIDE THE FUNCTION IS "<<i;
      cout<<"THE NEW VALUE OF J OUTSIDE THE FUNCTION IS "<<j;
}