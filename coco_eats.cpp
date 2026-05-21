#include<iostream>
#include<vector>
using namespace std;

int minimum_bananas_to_eat(vector<int> s, int hour)
{
    int high = 0;

    for(int x : s)
    {
        high = max(high, x);
    }

    int low = 1; // IMPORTANT (not 0)

    while(low <= high)
    {
        int mid = (low + high) / 2;

        long long count_hours = 0;

        for(int i = 0; i < s.size(); i++)
        {
            count_hours += (s[i] + mid - 1) / mid; // correct ceil logic
        }

        if(count_hours <= hour)
        {
            high = mid - 1; // try smaller speed
        }
        else
        {
            low = mid + 1; // need faster eating
        }
    }

    return low;
}

int main()
{
	vector<int> s {12 , 13 ,14 ,15 ,20 , 19};

	int min_num = minimum_bananas_to_eat(s , 9);

	cout<<min_num;
}