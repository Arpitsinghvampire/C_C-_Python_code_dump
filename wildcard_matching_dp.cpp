//wildcard_matching_dp.cpp

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool wildcard_matching(string s, string p)
{
    int n = s.length();
    int m = p.length();

    // dp[i][j] = whether first i characters of pattern
    // match first j characters of string
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Empty pattern matches empty string
    dp[0][0] = true;

    // Empty string initialization
    for (int i = 1; i <= m; i++)
    {
        if (p[i - 1] == '*')
            dp[i][0] = dp[i - 1][0];
        else
            dp[i][0] = false;
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // Exact character match or '?'
            if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }

            // '*'
            else if (p[i - 1] == '*')
            {
                // '*' matches empty sequence OR one/more characters
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }

            // Characters don't match
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[m][n];
}

int main()
{
    string s, p;

    cout << "Enter the string : ";
    cin >> s;

    cout << "Enter the pattern : ";
    cin >> p;

    if (wildcard_matching(s, p))
        cout << "Pattern matches the string." << endl;
    else
        cout << "Pattern does not match the string." << endl;

    return 0;
}