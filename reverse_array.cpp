//reverse_array.cpp

#include<iostream>
#include<vector>
#include<array>

using namespace std;

//here we will reverse the array by using the concept of recursion 
//specially the parameterized  recursion 
void reverse_array(int i , int j , int arr[]) //everytime these two positions will be swapped 
{
	if(i >= j)
		return ;
	else
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;

		//after making this change we need to call the function again 
		reverse_array(i+1 , j-1 , arr); //here i refers to the startinf pointer and the j refers to the end pointer 
	}
}

int main()
{

	int arr[] = {1 ,2,3,4,5,6,7,8};
   array<int ,9> arr1 {1,2,3,4,5,6,7,8,9};

   reverse_array(0 , (sizeof(arr)/sizeof(arr[0]))-1, arr);


   cout<<"THE REVERSED ARRAY IS GIVEN BY "<<endl;

   for(int x : arr)
   {
   	cout<<x<<endl;
   }
}