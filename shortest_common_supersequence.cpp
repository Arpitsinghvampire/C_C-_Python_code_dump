//shortest_common_supersequence.cpp

#include<iostream>
#include<vector>
#include<map>
#include<climits>

using namespace std;

//basic approach 
//instead of now looking at only one single string we will now look at two strings at once and then decide whether to add them into the subsequence or not 
void max_substring(int index , int index1 , string s1 , string s2 , vector<string> &max_subsequence , string current_sequence)
{
	if(index == s1.size  && index1 == s2.size()) //that means reaches the end 
	{
		max_subsequence.push_back(current_sequence);
	}

	else if(index == s1.size())
	{
		max_substring(index , index1 ,s1 ,s2 , max_subsequence , current_sequence);
	}
	else

	{
		//you have 4 options here , either push both , or push one or push neither 
		max_substring(index+1 , index1+1 , s1 , s2  ,max_subsequence , current_sequence + s1[index] +s2[index1]);
		max_substring(index+1 , index1+1 , s1 , s2  ,max_subsequence , current_sequence + s1[index] );
		max_substring(index+1 , index1+1 , s1 , s2  ,max_subsequence , current_sequence + s2[index1]);
		max_substring(index+1 , index1+1 , s1 , s2  ,max_subsequence , current_sequence );
	}

}

bool contains_all(string s1 , string s2 , string max_subsequence)
{
	map<char , int> dictionary ;
	map<char , int> dictionary1 ;
	map<char , int> dictionary2 ;

	for(int index = 0 ; index < max_subsequence.size() ; index++)
	{
		dictionary[max_subsequence[index]] ++;
	}
	//we similarly do the same for getting characters and their counts in the dictionary of the string

	for(int index1 = 0 ; index1 < s1.size() ; index1++)
	{
		dictionary1[s1[index1]] ++;
	}
	for(int index2 = 0 ; index2 < s2.size() ; index2++)
	{
		dictionary2[s2[index2]] ++;
	}

	//now check for each count of the dictionary 1 , the corresponding element must be lesser then the max_subsequence
	for(int index = 0 ; index < s1.size() ; index++)
	{
		if(dictionary1[s1[index]] > dictionary[s1[index]])
			return false;
	}
	for(int index = 0 ; index < s2.size() ; index++)
	{
		if(dictionary2[s2[index]] > dictionary[s1[index]])
			return false;
	}
	//else we return true;
	return true ;

}

//now we have  all the subsequences , we now want to make sure that both 
void min_supersequence(vector<string> max_subsequence , string s1 , string s2)
{
	cout<<"IA M CURRENTLY IN THE MIN SUPERSEQUENCE PART "<<endl;
	int min_length = INT_MAX;
	string result = "";
	for(int index = 0 ; index < max_subsequence.size() ; index++)
	{
		if(contains_all(s1 ,s2 , max_subsequence[index]))
		{
			if(min_length > max_subsequence[index].size())
			{
				min_length = max_subsequence[index].size();
				result = max_subsequence[index];
			}
		}
	}
	//now we have the min length of the supersequence 
	cout<<"THE MIN LENGTH OF THE SUPERSEQUENCE WHICH CONTAINS BOTH IS :: "<<min_length <<" AND THE SUPERSEQUENCE IS :: "<<result<<endl;
}

int main()
{	
	string s1 ("hola");
	string s2 ("hola1an");

	vector<string> final_result ;
	max_substring(0 , 0 , s1 , s2 , final_result , "");
	min_supersequence(final_result , s1 , s2);


}