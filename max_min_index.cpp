//max_min_index.cpp

//here we wwant to get the difference between the max and the min for each 
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> previous_smaller(vector<int>& arr)
{
    int n = arr.size();

    vector<int> pse(n);

    stack<int> st;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }

    return pse;
}

vector<int> next_greater(vector<int>& arr)
{
    int n = arr.size();

    vector<int> nge(n);

    stack<int> st;

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        nge[i] = st.empty() ? n : st.top();

        st.push(i);
    }

    return nge;
}

long long calculate_sum(vector<int>& arr)
{
    vector<int> pse = previous_smaller(arr);
    vector<int> nge = next_greater(arr);

    long long sum = 0;

    for(int i=0;i<arr.size();i++)
    {
        long long left = i - pse[i];
        long long right = nge[i] - i;

        sum += (long long)arr[i] * left * right;
    }

    return sum;
}

int main()
{
    vector<int> arr = {3,1,2,4};

    cout << calculate_sum(arr) << endl;
}