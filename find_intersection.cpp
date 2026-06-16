//find_intersection.cpp

//in this code block we will need to find the common intersection point between the two linked list 
//in this question we will take two pointers for each of the linked list , and then move the pointer to same position as the smallest ones 
//so that we can find the intersection between them 

#include<iostream>

using namespace std;

struct node
{
	int data ;
	node* next ;
};

int count_length(node* head)
{
	//this function counts the length of the linked list 
	node* temp = head ;
	int count = 0 ;
	while(temp)
	{
		count++;
		temp = temp->next ;
	}
	return count ;
}

//now we create another function to get the  first intersection part 
void first_intersection_part(node* head1 , node* head2)
{
	int count = count_length(head1);
	int count1 = count_length(head2);

	node* temp1 = head1;
	node* temp2 = head2;


	//now we have to get the counts for both the linked lists 
	if(count > count1)
	{
		//the first list is bigger list 
		//then you have to move the temp1 to match the list 
		int difference = count - count1;
		while(difference!=0)
		{
			temp1 = temp1->next ;
			difference -- ;
		}
	}
	else if(count <count1)
	{
		int difference = count1 - count ;
		while(difference!= 0)
		{
			temp2 = temp2->next ;
			difference -- ;
		}
	}
	//if they are of the same length then nothing to look this 
	//now after this part both the pointers will be at the same length horizontally 
	//now we move both the pointers and see where they are matching 
	while(temp1)
	{
		if(temp1->data != temp2->data)
		{
			//move both one step forward 
			temp1 = temp1->next ;
			temp2 = temp2->next ;
		}
		else
		{
			//now if they are equal you have to break the loop and then return the number 
			break ;
		}
	}
	cout<<"THE FIRST COMMON INTERSECTION POINT FOR BOTH THE LINKED LIST IS GIVEN AS "<<temp1->data;
}
int main()
{
	//now here we will fill both the linked list 
	cout<<"enter -1 to stop taking the input  for the first linked list "<<endl;

	node* head = NULL;
	node* temp = NULL;
	while(true)
	{
		int number ;
		cin>>number ;
		if(number == -1)
		{
			break ;
		}
		else
		{
			node* T = new  node ;
			T->data = number ;

			if(head == NULL)
			{
				head = T ;
				temp = T ;
				temp->next = NULL;
			}
			else
			{
				temp->next = T;
				temp = T ;
				temp->next = NULL;
			}
		}
	}

	cout<<"NOW YOU ARE FILLING FOR THE SECOND LINKED LIST , ENTER -1 TO STOP TAKING THE INPUT "<<endl;

	node* head1 = NULL;
	node* temp1 = NULL;
	while(true)
	{
		int number ;
		cin>>number ;
		if(number == -1)
		{
			break ;
		}
		else
		{
			node* T = new  node ;
			T->data = number ;

			if(head1 == NULL)
			{
				head1 = T ;
				temp1 = T ;
				temp1->next = NULL;
			}
			else
			{
				temp1->next = T;
				temp1 = T ;
				temp1->next = NULL;
			}
		}
	}

	//now we have both the linked list we now take the intersection part from them 
	first_intersection_part(head , head1);

}