//longest_palindromic_subseq.cpp

//here we still do the same thing find all the subsequence and then find the largest palindromic subsequence

#include<iostream>
#include<vector>
#include<set>

using namespace std;

//find the subsequences first 
void find_subsequences(string s , int index , vector<string> &subsequence , string current_string)
{
	if(index == s.size())
	{
		subsequence.push_back(current_string);
		return;
	}
	else
	{
			//you either pick up that inde value or not 
		find_subsequences(s , index+1 , subsequence , current_string + s[index]); // you picked the value at that index 
		find_subsequences(s , index + 1 , subsequence  , current_string); //you dont pick up the value at that index 
	}
	return ;
}

bool is_palindrome(string subseq)
{
	for(int index = 0 ; index <= subseq.size()/2; index++)
	{
		if(subseq[index] != subseq[subseq.size()-1-index])
			return false;

	}
	return true;
}

//now after finding the different subsequences for the above string , we now want to find the maximu, length palindroic sequence 
void largest_palindromic_sequence(vector<string> subsequence)
{
	int max_length = INT_MIN;
	string result = "";

	for(int index = 0 ;index < subsequence.size() ; index++)
	{
		if(is_palindrome(subsequence[index]))
		{
			max_length = max(max_length , (int) subsequence[index].length());
			if(max_length  == subsequence[index].size())
				result =subsequence[index];
		}
	}

	cout<<"THE MAX LENGTH OF THE LARGEST PAPLINDROMIC SUBSEQUENCE IS GIVEN AS "<<max_length<<endl;
	cout<<"THE MAX LENGTH PALINDROMIC SEQUENCE IS "<< result <<endl;
}

int main()
{
	string s  = "abbaabbacd";
	vector<string> subsequence;
	find_subsequences(s , 0 ,subsequence , "");

	largest_palindromic_sequence(subsequence);

}