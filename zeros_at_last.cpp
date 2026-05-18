#include<iostream>
#include<vector>
#include<array>
using namespace std;

vector<int> zeros_at_last(vector<int> s) //but this is the O(n^2 approach)
{
    for(int index =0 ; index <s.size() ; index++)
    {
        if(s[index] == 0)
        {
            for(int j = index+1 ; j< s.size() ; j++)
            {
                if(s[j] != 0)
                {//swap the values 
                s[index] = s[j];
                s[j] = 0;
                break;
                }
            }
        }
    }

    return s;
}

// now we need to use the most optimized approach  using the two pointers 
vector<int> zeros_at_last1(vector<int> s)
{
    int j =s.size()-1;
    for(int i =0 ; i< j ; i++)
    {
        if(s[i] == 0 && s[j] != 0)
        {
            s[i] = s[j];
            s[j] = 0;
            j--;
        }
        //if both the points are zero we ould need to go back to the last non zero value 
        else if(s[i] == 0 && s[j] == 0)
        {
            while(s[j] == 0 && i<j)
            {
                    j--;
            }
            s[i] = s[j];
            s[j] = 0;
        }

    }
    return s ;
}


// here we want to put all  0's at the last 
int main()
{
    vector<int> zeros {1  ,2 ,2 ,0 , 4, 2 ,0 ,23 , 0 , 0 , 0 , 0 , 9};
    vector<int> zeros1 {1  ,2 ,2 ,0 , 4, 2 ,0 ,23 , 0 , 0 , 0 , 0 , 9};
    vector<int> functioned_zeros = zeros_at_last(zeros);

    for(int x: functioned_zeros)
    {
        cout<<x<<endl ;
    }

    cout<<"Now this is the new and optimized function having two pointers "<<endl;
    vector<int> functioned_zeros1 = zeros_at_last1(zeros1);

    for(int x: functioned_zeros1)
    {
        cout<<x<<endl ;
    }
}