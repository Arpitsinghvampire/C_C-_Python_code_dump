#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<deque>

using namespace std;

int main()
{
 // we can copy the containers only when the data types must match exactly .
 //the container types and the data types must match 

 vector<string> svec(5 , "eh?");
 list<int> ilist ;

 vector<int> ivec;
 vector<int> ivec2(ivec);

 list<int> ilist2(ilist);
  
 //now we copy the list using the iterators 
 vector<string> stringlist(svec.begin() , svec.end());
 // copies the list from beginning and end of the iterator 
 //we can also find the mid point of the iterator like 
 vector<string>::iterator iter_mid = svec.begin() + svec.size()/2;
 vector<string> stringlist1(svec.begin() , iter_mid);

}