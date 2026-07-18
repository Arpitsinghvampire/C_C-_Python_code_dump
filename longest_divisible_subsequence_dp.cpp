//longest_divisible_subsequence_dp.cpp

//this is a precursor to the previous longest increasing subsequence  , but we need to find the longest increasing subsequence 
//longest_increasing_subsequence_dp.cpp

//here we want to find the longest increasing subsequence

#include<iostream>
#include<vector>

using namespace std;

void longest_increasing_subseq_length(vector<int> array_1)
{
    int n = array_1.size();

    // dp[index][prev+1]
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Base case:
    // dp[n][*] = 0

    for(int index = n - 1; index >= 0; index--)
    {
        for(int prev = index - 1; prev >= -1; prev--)
        {
            // Don't take current element
            int not_taken = dp[index + 1][prev+1]; //this refers to previous element  not taken , since the index is starting from 0 

            // Take current element
            int taken = 0;

            if(prev == -1 || array_1[index] % array_1[prev] == 0 || array_1[prev] % array_1[index] == 0)
            {
                taken = 1 + dp[index + 1][index + 1]; //when you have taken that element , the previous also changes 
            }

            dp[index][prev + 1] = max(taken, not_taken);
        }
    }

    cout << "Length of LIS = " << dp[0][0] << endl;
}

int main()
{
    vector<int> arr = {10,9,2,5,3,7,101,18};

    longest_increasing_subseq_length(arr);
}