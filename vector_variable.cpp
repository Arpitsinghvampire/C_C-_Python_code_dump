#include<iostream>
#include<vector>

using namespace std ;

int main()
{
    //now here we will store the variable number of variables into a vector 
    vector<string> variable_vectors ;
    string value;

    while(cin>>value)
    {
        if(value == ".")
        {
            break;
        }
        else
        {
            variable_vectors.push_back(value);
        }
    }
    //now we wil create another loop to get the values of the vectors stored 
    
    // here we will use an iterator 
    vector<string>:: iterator iter = variable_vectors.begin();
    
    while(iter!= variable_vectors.end())
    {
       cout<<*(iter)<<endl;
       ++iter;
    } //this prints the value stored in the iterator 

}
