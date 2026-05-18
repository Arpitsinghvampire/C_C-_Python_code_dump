#include<iostream>
#include<list>
#include<deque>
#include<stack>
#include<vector>

using namespace std;

int main()
{
    pair<string , string> anon ; //this initializes an empty pair 
    typedef pair<string , string> author ; // now you will use pair<string , string> as author 
    author  proust("JOSEPH ", " PROUST");
    author prose("arpit" , "prose");
    cout<<proust.first<<endl;
    cout<<proust.second<<endl;

    string firstbook ;
    if(proust.first == "JOSEPH " && proust.second == " PROUST")
    {
        firstbook = "kamasutra";
    }
    else
    {
        firstbook = "bhagavad geeta";
    }

   cout<<firstbook;
}
