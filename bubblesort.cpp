#include<stdio.h>
#include<stdlib.h>

#define SIZE 10 

/* HERE WE WRITE THE FUNCTION PROTOTYPE */
int* bubbleSort(int *array1 , int size);
int* quicksort(int* array1 , int size);
int main()
{
 //take the input of the array 
 int size ;
 printf("ENTER THE SIZE OF THE ARRAY YOU WANT");
 scanf("%d" , &size);
  
  int *array =(int*)malloc(sizeof(int)*size);

 for(int i=0; i<size;i++)
 {
    printf("Enter the number ");
    scanf("%d" , array+i); //this stores the address also 

 }

  for(int i=0; i<size;i++)
 {
    printf("%d\n" , array[i]); //this stores the address also 

 }


 //now lets do the bubble sort algorithm and then return the  sorted array 
 printf("THE SORTED ARRAY IS ");
 int* sorted_array= bubbleSort(array , size);
 for(int j=0;j<size;j++)
{
    printf("%d\n" , sorted_array[j]);
}
}
int* bubbleSort(int* array1 , int size)
 {
  for(int j=0;j<=size-1;j++)
 {
    for(int i=0; i<size-1;i++)
    {
    //swap the elements when the element is greater than the successor 
    if(array1[i]>array1[i+1])
    {
     int temp = array1[i+1];
     array1[i+1] = array1[i];
     array1[i] = temp;
    }
    }
 }
  return array1;
}

//now lets do the same for the quick sort 

int* quicksort(int* array1 , int size)
{
  
}
