//division_threshold.cpp
#include<iostream>
#include<vector>

using namespace std;

int division_threshold_optimized(vector<int> s , int threshold)
{
	//we need to find the sum of divisors which which it is less than or equal to threshold
	// we do similarly which we did in the previous question 
	int max_element = 0;
	for(int index = 0 ; index < s.size() ; index++)
	{
		max_element = max(max_element , s[index]);
	}
	//we get the max element 
	//now lets get the divisor 
	int low =1 ;
	int high = max_element ;

	while(low<=high)
	{
		int mid =(low+high)/2 ;
		int  sum_divisors = 0 ;
		for(int index = 0 ; index <s.size() ; index++)
		{
			sum_divisors += (s[index]+mid -1 )/mid; // correct ceil value 
		}
			cout<<"mid is given as " << mid <<"and sum of divisors is given as "<<sum_divisors<<endl;
		if(sum_divisors == threshold)
		{
			return mid;
		}
		else if(sum_divisors > threshold)
		{
			// we would need to move towards the right hand side  so to reduce the sum_divisors 
			low = mid  + 1;
		}
		else
		{
			high = mid -1 ;
		}

	}
	return low ;
}

int main()
{
		vector<int> s {12 ,14 , 12 ,10 , 1 , 5 ,6 ,7 ,10};

		int max_div = division_threshold_optimized(s , 24);

		cout<<max_div<<endl;
}
