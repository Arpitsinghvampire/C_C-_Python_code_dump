//minimum_insertions_palindrome_dp.cpp

//in this code  block we have to find the number of insertions needed to create a palindrome 
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void min_insert_palindrome(vector<vector<int> &dp , string s1)
{
	//so basically if we find the longest aplindromic sequence of the string , and then subtract the 
	//non palindromic sequence , we will get our min operations needed to convert to the substring 
	//in order to find the palindromic sequence , basically they have to be equal from both front and the 
	//rear side ,  , so in the rows , i will keep them as it is ,but in the column side , i will put the reverse of the string 
	//in it 
	for(int column = 0 ; column <= s1.size() ; column++)
	{
		dp[0][column] = 0 ;
	}

	for(int row = 0 ; row<= s1.size() ; row++)
	{
		dp[row][0] = 0 ;
	}
	//now we fix the other values 
	for(int row =1 ; row<= s1.size() ; row++)
	{
		for(int column = 1 ; column <= s1.size(); column++)
		{
			if(s1[row-1] == s1[s1.size()-column])
			{
				dp[row][column] = 1+ dp[row-1][column-1];
			}

			else
			{
				//either ignore the last charcter of the first string or ignore the 
				//last character of the second string 
				dp[row][column] = max(dp[row-1][column] , dp[row][column-1]);
			}
		}
	}

	//now we need to print the longest common subsequence between the string and its reversed string 
	int rows = s1.size()-1;
	int columns = s1.size()-1;
	string answer = ""
	while(rows>0 && columns >0)
	{
		if(s1[s1.size()-1-rows] == s1[columns])
		{	
			answer += s1[rows];
			rows--;
			columns--;
		}	

		else
		{
			if(dp[rows-1][columns] > dp[rows][columns-1])
				rows--;
			else
				columns--;
		}
	}

	reverse(answer.begin()  ,answer.end());

	cout<<answer<<endl;

	cout<<"THE MIN NUMBER OF OPERATIONS TO FIND THE ANSWER IS "<<s1.size()- answer.size()<<endl;
}