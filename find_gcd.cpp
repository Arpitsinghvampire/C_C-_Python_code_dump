//find_gcd.cpp
#include<iostream>
#include<vector>

using namespace std;

int find_gcd(int n , int m )
{
	//here we have to find the highest number that divides the two 
	//lets start by taking a loop until the max of the two numbers 

	int max_number = 0 ;
	for(int index = 1 ; index <=min(m , n) ; index++)
	{
		if(n%index == 0 && m%index == 0)
		{
			max_number = max(max_number , index); // choose the maximum among the maximum number and the index  and update it to the largest 
		}
	}

	return max_number ;
}
//alterative approach you have the factors for each of the two numbers , then find the max among them 

int alternative_approach(int number1 , int number2)
{
	int max_number = 0;

    vector<int> s1 ,s2;

    for(int index = 1 ; index <=  number1 ; index++)
    {
    	if(number1%index == 0)
    		s1.push_back(index);

    }

     for(int index = 1 ; index <=  number2 ; index++)
    {
    	if(number2%index == 0)
    		s2.push_back(index);

    }

    // now we have the factors for  both , now try to find the max 

    //we wont follow thisprocedure because it involves repetedly doiung the same task 
    

}

int main()
{
 	int number1 , number2 ;

 	cout<<"ENTER THE FIRST NUMBER "<<endl;
 	cin>>number1 ;

 	cout<<"ENTER THE SECOND NUMBER "<<endl;
 	cin>>number2;

 	int gcd = find_gcd(number1 , number2);

 	cout<<"THE GREATEST COMMON DIVISOR IS GIVEN AS "<< gcd<<endl;
}