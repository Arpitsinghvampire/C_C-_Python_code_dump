#include<vector>
#include<iostream>

using namespace std;

int find_square_root(int n) // this is the brute force method 
{
	for(int i = 0 ; i<n ; i++)
	{
		if(pow(i ,2) <=n && pow(i+1 , 2)>n)
		{
			return i ;
		}
	}
	// if we do not find such number , we return -1 ;
	return -1 ;

}

// now lets use an optimized approach for the above programme
int find_sqaure_root_optimized(int n)
{
	// we know that the numbers of the vector int would be in the sorted order so we try finding the mid of the number of the number
	// is greater than the number , we then move towards the left hand side of the array , so that the we approach towards the actual square root 
	// else if the mid element is lesser than that number then we move towards the right hand side 
	int low = 0 ;
	int high = n;

	while(low<=high)
		{
			if((low+high)/2 *(low+high)/2  < n)
			{
				// we need to move towards the right side of the vector 
				low = (low+high)/2 +1 ;
			}
			else  if((low+high)/2*(low+high)/2 ==n)
			{
				return (low+high)/2 ;
			}
			else
			{
				// we need to move towards the left hand side of the vector 
				high = (low+high)/2 -1 ;
			}

		}
		return (low+high)/2  ;
}
int main()
{
	int number = 25;

	int square_root = find_square_root(number);

	cout<<square_root<<endl;

	int square_root1 = find_square_root(number);

	cout<<square_root1<<endl;

}
