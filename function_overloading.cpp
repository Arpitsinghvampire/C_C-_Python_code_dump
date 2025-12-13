#include<iostream>
using namespace std ;
// function prototypes 
int square_area(int );
double square_area( double);

// here lets also talk about the global and the local variables scoping 
int number =7 ;
//this is the global variable , suppose we have the same variable in our  main function , how to differentiate between the two 

int main()
{
    int side = 3;
    double side1 = 4.5;
    double  number = 4.5;
    cout<<"THE AREA OF THE SQUARE IS ::  "<<square_area(side)<<endl;
    cout<<"THE AREA OF THE SQUARE USING THE  OVERLOADED PART IS ::  "<<square_area(side1)<<endl;

   //this part demonstrates the global and the local variables 
   cout<<"THE LOCAL VARIABLE VALUE IS ::  "<<number<<endl; //this by default prints the local variable value 
   cout<<"THE GLOBAL VARIABLE VALUE IS ::  "<<::number<<endl; //this prints the global value 
}

int square_area(int side)
{
    return side*side;
}

double square_area(double side)
{
    return  side*side ;
}

int square_area(int side)
{
    return side*side*side;
}
