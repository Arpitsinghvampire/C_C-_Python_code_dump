//shortest_supersequence.cpp

//here we want to find the shortest supersequence containing both the strings 

//so here we should add the common parts only once and then add the non common parts 
//so basically this programme converges to the fact that lenght of shortest super sequence is 
//length of string1 + length of string 2 - length of lcs 

//so we now focus on creating the lcs for the two strings 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void find_subsequences(int index , string s , vector<string> &subsequences , string current_sequence)
{
	if(index == s.size())
	{
		subsequences.push_back(current_sequence);
		return ;
	}
	else
	{
		//either choose or you dont 
		find_subsequences(index+1 , s , subsequences , current_sequence+s[index]);
		find_subsequences(index+1 , s , subsequences , current_sequence);
	}
}

//this will return the subsequence , now you want the longest one 
//after finding the  different subsequences possible we now want to find the largest among them 
void find_max(vector<string> subsequence , vector<string> subsequence1 , string  s1 , string s2)
{
	int max_length = 0;
	for(int index = 0 ; index < subsequence.size() ; index++)
	{
		for(int index1 = 0 ; index1< subsequence1.size() ; index1++)
		{
			if(subsequence[index] == subsequence1[index1])
			{
				if(max_length < subsequence[index].size())
				{
					max_length  = subsequence[index].size();
				}
			}
		}
	}
	cout<<"THE LENGTH FOR THE SHORTEST SUPER SEQUENCE IS GIVEN AS " <<s1.size()+s2.size() - max_length;
}

int main()
{
	string s1 = "helloigood";
	string s2 = "hellohegood";

	vector<string> result ;
	vector<string> result1 ;

	find_subsequences(0 , s1 , result , "");
	find_subsequences(0 , s2 , result1 , "");

	find_max(result , result1 ,s1 , s2);
}