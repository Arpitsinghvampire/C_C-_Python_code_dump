#include<iostream>
#include "maximum.h"
using namespace std;

template <typename T> //the c++ programme will accordingly put the correct data format at the correct position 
T add(T a , T b)
{
    return a+b; //here no need to define the data type , the c++ programme works in this template 
}

int main()
{
    double  number1 ;
    double  number2 ;
    cout<<"ENTER THE FIRST NUMBER :: "<<endl;
    cin>>number1;
    cout<<"ENTER THE SECOND NUMBER :: "<<endl;
    cin>>number2;
    cout<<"THE FINAL RESULT IS  :: "<< add(number1 , number2);

    double number3;
    cout<<"ENTER THE THIRD NUMBER ::  "<<endl;
    cin>>number3;

    maximum(number1 , number2  , number3);
}