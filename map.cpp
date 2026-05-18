#include<iostream>
#include<map>
#include<string>
#include<deque>
#include<list>
using namespace std;
bool isvowel(char s)
{
  s = tolower(s);
  if(s=='a' || s == 'e' ||s=='i' || s == 'o' || s=='u')
  return true;
  return false;
}



int main()
{
    map<string , int> m;
    m.insert(make_pair("Hola" , 0 ));
    //now we create a copy of the above variable 
    //the types of both the strings must be the same 
    map<string , int> m1;//here we take m and assign it to m1 

 // in a string lets find the number of vowels and non vowels in a string 
    m1.insert(make_pair("vowel" , 0));
    m1.insert(make_pair("consonant" , 0));
    string inputstring;
    cout<<"Enter the string where you want to want to know the number of vowels and consonants"<<endl;
    cin>>inputstring; //reads from the input stream and then writes in to the inputstring 


   for(int i =0 ; i<inputstring.size() ; ++i )
   {
    if(isvowel(inputstring[i]))
    m1["vowel"] = m1["vowel"]+1;
    else
    m1["consonant"] = m1["consonant"]+1;
   }

   cout<<"THE NUMBER OF VOWELS IN THE INPUT STRING IS "<<m1["vowel"]<<" AND THE NUMBER OF CONSONANTS IS "<<m1["consonant"]<<endl;
   cout<<inputstring.size();
}