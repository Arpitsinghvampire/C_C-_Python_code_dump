#include<iostream>
using namespace std;

void do_swap(int &v1 , int &v2)
{
 int temp = v2;
 v2 = v1;
 v1 = temp;
}

void swap(int &v1  , int &v2)
{
    if(v1 == v2)
        return;

    do_swap(v1 , v2);
}

int main()
{
    cout<<"enter the first number ";
    int number1 , number2 ;
    cin>>number1;

    cout<<"Enter the second number";
    cin>>number2;

    cout<<'The values of the numbers before the swapping is '<<number1<<" and "<<number2;

    //now we swapt the values ;
    swap(number1 , number2);

     cout<<"The values of the numbers after the swapping is "<<number1<<" and "<<number2;

}