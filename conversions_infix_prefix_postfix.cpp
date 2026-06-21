//conversions_infix_prefix_postfix.cpp

//here in this programme we will convert the infix , prefix and the postfix programmes 
#include<iostream>
#include<stack>

using namespace std;

bool is_operand(char s)
{
	if(s>='a' && s<='z' || s>='A' && s<='Z' || s>=1 && s<=9)
		return true;
	return false;
}

bool is_operator(char s)
{
	return !is_operand(s);
}


int return_precedence_order(char s)
{
	//precedence order is only for the operators 
	if(is_operator(s))
	{
		if(s == '^')
			return 3;
		else if( s== '/' || s== '*')
			return 2;
		else
			return 1;
	}

	return 0 ;
}

//now we write the function to convert the infix to postfix 
void convert_infix_to_postfix(string s)
{
	string result = "";
	stack<char> s1 ;
	for(int index = 0 ; index < s.size() ; index++)
	{
		if(is_operand(s[index]))
			result += s[index] ; //if it is operand directly push into the resulting string 
		else
		{
			//npw you have to push on the stack 
			if(is_operator(s[index]))
			{
				//if the current operator has priority greater than the top you just have to push 
				///else you would need to pop the top and then push into the resulting string 
				if(s1.empty())
				{
					//push the operator
					s1.push(s[index]); 

				}
				else
				{
					//check the precedence order of the top 
					if(return_precedence_order(s[index])> return_precedence_order(s1.top()))
						s1.push(s[index]);
					else
					{
						if(s[index]!= ')')
						{
							result += s1.top();
							s1.pop();
							s1.push(s[index]);
						}
						else
						{
							//you need to pop until you get the enclosing open bracket
							while(s1.top()!= '(')
							{
								result += s1.top();
								s1.pop();
							}
							s1.pop();
						}
					}
				}
			}

		}
	}

	//after reaching the end you need to pop all the stack values and then push onto the string 
	while(!s1.empty())
	{
		result += s1.top();
		s1.pop();
	}

	cout<<"THE FINAL RESULT IS  "<< result<<endl;

	return ;
}

int main()
{
	cout<<"ENTER THE STRING YOU WANT TO CONVERT TO POSTFIX FROM INFIX ";
	string input_string ;
	cin>>input_string ;

	convert_infix_to_postfix(input_string);
}