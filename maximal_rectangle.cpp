//maximal_rectangle.cpp

//in this question we would be given a 2d matrix , and we would need to find the maximal rectangle which we can draw 
//so this question is basically an extension of the previous question to  find the  largest rectangle 
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> previous_smaller(vector<int> &h)
{
    int n = h.size();

    vector<int> prev(n);

    stack<int> st;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && h[st.top()] >= h[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            prev[i] = -1;
        }
        else
        {
            prev[i] = st.top();
        }

        st.push(i);
    }

    return prev;
}

vector<int> next_smaller(vector<int> &h)
{
    int n = h.size();

    vector<int> nxt(n);

    stack<int> st;

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && h[st.top()] >= h[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            nxt[i] = n;
        }
        else
        {
            nxt[i] = st.top();
        }

        st.push(i);
    }

    return nxt;
}

int max_histogram_area(vector<int> h)
{
    vector<int> prev = previous_smaller(h);
    vector<int> nxt = next_smaller(h);

    int ans = 0;

    for(int i=0;i<h.size();i++)
    {
        int width = nxt[i] - prev[i] - 1;

        int area = h[i] * width;

        ans = max(ans, area);
    }

    return ans;
}

void maximal_rectangle(vector<vector<int>> matrix)
{
    if(matrix.empty())
        return;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> height(cols,0);

    int answer = 0;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(matrix[i][j] == 1)
            {
                height[j]++;
            }
            else
            {
                height[j] = 0;
            }
        }

        answer = max(answer,
                     max_histogram_area(height));
    }

    cout<<"THE MAXIMAL AREA IS GIVEN AS "
        <<answer<<endl;
}

int main()
{
    vector<vector<int>> s =
    {
        {1,0,1,0,1},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };

    maximal_rectangle(s);
}