//finding_loop.cpp

//this programme tries to find whether there is a loop existing in the programme or not 
#include<iostream>
using namespace std;

struct node
{
	int data ;
	node* next ;
};


void loop_or_not(node* head)
{
	//we again take two pointers here one is the slow pointer and the other is the fast pointer 
	node* slow_pointer = head;
	node* fast_pointer = head;

	//we stop until and unless they both point to the same location or the address 
	//but there may be chance where they wont be same (loop does not exit)
	while(true)
	{
		//here we will handle the case when the loop does not exit 
		if(fast_pointer == NULL)
		{
			cout<<"THE LOOP DOES NOT EXIST "<<endl;
			break;
		}
		else
		{
			//here we move the fast pointer by two positions and the slow pointer by one position 
			if(fast_pointer == slow_pointer && fast_pointer != head)
			{
				cout<<"THE LOOP EXITS "<<endl;
				break;
			}
			else
			{
				if(fast_pointer && fast_pointer->next)
				{
					fast_pointer = fast_pointer->next->next;
					slow_pointer = slow_pointer->next;
				}
			}

		}

	}
}
int main()
{
	//here we will take our own custom linked list which has loop , and the other linked list which does not 
	node* head = NULL;
	node* temp = NULL;

	for(int i = 0 ; i< 10 ; i++)
	{
		node* T = new node ;
		T->data = i;
		if(head == NULL)
		{	
			head = T;
			temp = T ;
			temp->next = NULL;
		}
		else
		{
			temp->next = T;
			temp = T;
			temp->next = NULL;

		}
	}
	//now from here we add the looping element to the above non loop
	loop_or_not(head); //this part is without the loop 
	node* temp1 = temp ;

	for(int i = 0; i<20 ; i++)
	{
		node* T = new node ;
		T->data= i ;
		temp->next = T;
		T->next = NULL;
		temp = T;
	}
	temp->next = temp1; //this is used for creating the loop 

	//now we need to check whether there is a loop or not 
	loop_or_not(head); //this part is with the loop 
}