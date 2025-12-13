#include<iostream>

using namespace std;

//in the inline function  ,the programme basically cuts and fixes the  function  into the required 
// positions  , the function calls are not discontinous , that meansthe flow is not disturbed .
//this can increase the size of the programme , but will be executed faster 

inline double volume( double side)
{
    return side*side*side;
}
// lets also demonstrate the default function 
//here the parameters by default take a value 
inline double area(double side = 1)
{
    return side*side;
}

int sum_pass_by_value(int);
int sum_pass_by_reference(int&);

int main()
{
   cout<<"ENTER THE SIDE LENGTH ";
   double side;
   cin>>side;

   cout<<"THE VOLUME OF THE CUBE IS "<<volume(side)<<endl;

   cout<<"THE AREA OF THE FOLLOWING SQUARE IS  "<<area(side)<<endl;

   //here we will also practive the pass by value and pass by reference 
   cout<<"ENTER THE NUMBER YOU WANT  TO PASS BY VALUE  ::  ";

   int number3 ;
   cin>>number3;
   
   int& count = number3;
   cout<<"THE OUTPUT RECIEVED FROM THE PASS BY REFERENCE  IS  ::  " << sum_pass_by_reference(count)<<endl;
   //since we passed the value by reference this means that the value at that location has changed and thus 
   //the next operation will be done on the updated value 
   cout<<"THE OUTPUT RECIEVED FROM THE PASS BY VALUE IS  ::  " << sum_pass_by_value(number3)<<endl;
}
int sum_pass_by_reference(int& count)
{
    count = count*2;
    return count;
}
int sum_pass_by_value(int count)
{
    count = count*2;
    return count;
}