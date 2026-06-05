//longest_common_subsequence.cpp

//in this code we need to find the longest common subsequnce for the two strings 
//the basic approach is that the find all the bubsequnces for the two strings and then calculate the maximum length  of the subsequnce common to both 

//so our first approach is to create the subsequnce for both strings 
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


void subsequence_generation(string s , int index , string current_string , set<string> &result)
{
	//either you have to choose that index or not , if you  choose that index then you have to push into the vector 
	if(index == s.size())
	{
		result.insert(current_string);
		return ;
	}
	else
	{
		//the index is less than s.size()
		//either take the element in that index or not 
		subsequence_generation( s, index+1 , current_string+s[index] , result); //use the concatenation approach of the string 
		//here you take this current_string only , dont include into that original string 
		subsequence_generation(s , index+1 , current_string , result);

	}
	return ;

}

int get_max_length_subsequence(set<string> s , set<string> s1)
{
	vector<string> result ;
	set_intersection(s.begin() , s.end() , s1.begin() , s1.end() , back_inserter(result));

	cout<<"THE COMMON ELEMENTS IN BOTH ARE "<<endl;

	int max_length = 0;
	for(string x : result)
	{
		if(max_length < x.length())
			max_length = x.length();
		cout<<x<<endl;
	}

	return max_length ;

}


int main()
{
  string s1 ("abbcedefgh");
  string s2 ("bcabbdsfsajfiuabbcedefgh");

  set<string> result;

  set<string> result1 ;

  subsequence_generation(s1 , 0 , "" , result);
  subsequence_generation(s2 , 0 , "" , result1);

  cout<<"THIS IS THE DIFFERENT SUBSEQUENCES POSSIBLE FOR "<<s1<<endl;
  for(string s : result)
  {
  	cout<<s<<endl;
  }

   cout<<"THIS IS THE DIFFERENT SUBSEQUENCES POSSIBLE FOR "<<s2<<endl;
  for(string s : result1)
  {
  	cout<<s<<endl;
  }

  int result2 = get_max_length_subsequence(result , result1);

  cout<<"THE MAX LENGTH OF COMMON SUBSEQUENCE IS GIVEN AS "<<result2<<endl;
  
}