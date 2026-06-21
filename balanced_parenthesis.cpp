//balanced_parenthesis.cpp

//here we would be seeing whether the programme has the balanced parenthesis or not , that is they should have the same order of opening 
//and closing 
#include<iostream>
#include<stack>

using namespace std;

bool check_balanced_parenthesis(string s1)
{
	stack<char> s2;
	for(int index = 0 ; index < s1.size() ; index++)
	{
		//if there is opening brackets we need to add them into the stack 
		if(s1[index] == '(' || s1[index] == '[' || s1[index] == '{')
			s2.push(s1[index]);
		else
		{
			//if we get the enclosing brackets ,the top should be the opening version of that bracket 
			if(s1[index] == ')')
			{
				if(s2.top() == '(')
					s2.pop();
			}
			//else you cannot pop the bracket 
			if(s1[index] == ']')
			{
				if(s2.top() == '[')
					s2.pop();
			}
			if(s1[index] == '}')
			{
				if(s2.top() == '{')
					s2.pop();
			}


		}
	}

	return s2.empty();
}

int main()
{
	cout<<"ENTER THE INPUT OF THE STRING OF BRACKETS , THEY MUST CONTAIN ONLY ( , { , [ , AND THEIR CORRESPONDING CLOSING BRACKET"<<endl;
	string s1 ;
	cin>> s1;

	bool valid_or_not = check_balanced_parenthesis(s1);

	cout<< (valid_or_not ? "CONTAINS BALANCED BRACKETS " : "DOES NOT CONTAIN BALANCED BRACKETS");




}