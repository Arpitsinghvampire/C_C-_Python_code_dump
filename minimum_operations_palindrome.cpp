//minimum_operations_palindrome.cpp

//in this question we are given string , and then we have to find the minimum number of insertion to convert  it into a palindrome 
#include<iostream>
#include<vector>

using namespace std;

//basically we try to find the max length of the palindrome possible from the word given and then  basically subtract it from the length of the word 
//the difference is the number of insertions needed 
bool is_palindrome(string s) //simple check for palindrome 
{
	for(int index = 0 ; index < s.size() ; index++)
	{
		if(s[index] != s[s.size()-1-index])
			return false;
	}
	return true;
}

void min_operations(string s , int index , string current_sequence , vector<string> &current_vector_palindrome) //contains all the palindromic sequence 
{
	//so either you choose or you dont to be in that palindromic sequence  then in the last it should be a palindrome 
	//this is basically similar to finding the subsequence and among them find the max length 
	if(index == s.size())
	{
		//check for palindrome 
		if(is_palindrome(current_sequence))
			current_vector_palindrome.push_back(current_sequence);
		return ;

	}
	else
	{
		//you have two choices either add that to the palindromic sequence or you dont 
		min_operations( s , index+1 , current_sequence+s[index] , current_vector_palindrome);
		//or you dont 
		min_operations( s , index+1 , current_sequence, current_vector_palindrome);
	}
}
void  find_max_length_palindrome(vector<string> s , string s1)
{
	int max_length = INT_MIN;
	for(int index = 0 ; index < s.size() ; index++)
	{
		cout<<s[index]<<endl;
		max_length = max(max_length , (int) s[index].size());
	}
	cout<<"THE MINIMUM NUMBER OF INSERTIONS FOR MAKING IT A PLAINDROME IS "<<s1.size()-max_length;
	return ;
}

int main()
{
	string s1 = "assdfssa";

	vector<string> result ;

	min_operations(s1, 0 , "" , result);

	find_max_length_palindrome(result ,s1);
}
