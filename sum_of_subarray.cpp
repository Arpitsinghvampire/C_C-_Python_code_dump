

//in this question we have to calculate the sum of the subarray minimums  ,the approach for this problem would be that 
//we find that particular index and how many times is it the minimum  for the subarray , that will be its contribution 
//ad one to the contibution to take the element when it is the only element and then multiply by that number to get the total contribution
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Previous Smaller Element indices
vector<int> previous_smaller_element(vector<int>& arr)
{
    int n = arr.size();

    vector<int> pse(n);

    stack<int> st; // stores indices

    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            pse[i] = -1;
        }
        else
        {
            pse[i] = st.top();
        }

        st.push(i);
    }

    return pse;
}

// Next Smaller Element indices
vector<int> next_smaller_element(vector<int>& arr)
{
    int n = arr.size();

    vector<int> nse(n);

    stack<int> st; // stores indices

    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            nse[i] = n;
        }
        else
        {
            nse[i] = st.top();
        }

        st.push(i);
    }

    return nse;
}

long long sum_of_subarray_minimums(vector<int>& arr)
{
    int n = arr.size();

    vector<int> pse = previous_smaller_element(arr);
    vector<int> nse = next_smaller_element(arr);

    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        long long left = i - pse[i];
        long long right = nse[i] - i;

        long long contribution =
            (long long)arr[i] * left * right;

        sum += contribution;
    }

    return sum;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};

    cout << "Sum of Subarray Minimums = "
         << sum_of_subarray_minimums(arr)
         << endl;

    return 0;
}