//conversions_infix_prefix_postfix.cpp

#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool is_operand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

bool is_operator(char ch)
{
    return ch=='+' || ch=='-' ||
           ch=='*' || ch=='/' ||
           ch=='^';
}

int precedence(char ch)
{
    if(ch == '^')
        return 3;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '+' || ch == '-')
        return 1;

    return 0;
}

string convert_infix_to_postfix(string s)
{
    stack<char> st;
    string result = "";

    for(int i = 0; i < s.size(); i++)
    {
        char curr = s[i];

        if(is_operand(curr))
        {
            result += curr;
        }

        else if(curr == '(')
        {
            st.push(curr);
        }

        else if(curr == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }

            if(!st.empty())
                st.pop();      // remove '('
        }

        else if(is_operator(curr))
        {
            while(!st.empty() &&
                  st.top() != '(' &&
                  (
                    precedence(st.top()) > precedence(curr)
                    ||
                    (
                      precedence(st.top()) == precedence(curr)
                      &&
                      curr != '^'
                    )
                  )
                 )
            {
                result += st.top();
                st.pop();
            }

            st.push(curr);
        }
    }

    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

string reverse_string(string s)
{
    int left = 0;
    int right = s.size() - 1;

    while(left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    return s;
}

string convert_infix_to_prefix(string s)
{
    string reversed = reverse_string(s);

    for(int i = 0; i < reversed.size(); i++)
    {
        if(reversed[i] == '(')
            reversed[i] = ')';
        else if(reversed[i] == ')')
            reversed[i] = '(';
    }

    string postfix = convert_infix_to_postfix(reversed);

    string prefix = reverse_string(postfix);

    return prefix;
}

int main()
{
    cout << "ENTER THE INFIX EXPRESSION : ";
    string input_string;
    cin >> input_string;

    string postfix = convert_infix_to_postfix(input_string);

    cout << "POSTFIX : " << postfix << endl;

    string prefix = convert_infix_to_prefix(input_string);

    cout << "PREFIX  : " << prefix << endl;

    return 0;
}