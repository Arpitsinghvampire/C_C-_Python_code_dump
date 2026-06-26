//remove_k_digits.cpp

//in this code block we will have to remove k larger digits 
//remove_k_digits.cpp

// In this code block we have to remove k digits to form the smallest number.

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void remove_k_digits(string s, int k)
{
    stack<int> s1;
    string result;

    // Traverse all digits
    for (int index = 0; index < s.size(); index++)
    {
        int digit = s[index] - '0';

        // Remove all larger previous digits while k > 0
        while (!s1.empty() && s1.top() > digit && k > 0)
        {
            s1.pop();
            k--;
        }

        s1.push(digit);
    }

    // If k is still left, remove digits from the end
    while (k > 0 && !s1.empty())
    {
        s1.pop();
        k--;
    }

    // If all digits are removed
    if (s1.empty())
    {
        cout << "0" << endl;
        return;
    }

    // Store stack contents (reverse order)
    while (!s1.empty())
    {
        result += char(s1.top() + '0');
        s1.pop();
    }

    // Reverse to get the actual number
    reverse(result.begin(), result.end());

    // Remove leading zeros
    int i = 0;
    while (i < result.size() && result[i] == '0')
    {
        i++;
    }

    if (i == result.size())
    {
        cout << "0" << endl;
        return;
    }

    // Print answer
    for (; i < result.size(); i++)
    {
        cout << result[i];
    }

    cout << endl;
}

int main()
{
    string result = "123456";

    remove_k_digits(result, 3);

    return 0;
}