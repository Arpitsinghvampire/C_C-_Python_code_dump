//find_leader_loop.cpp

//here we need to find the first element of the loop 
//first we will focus on whether the loop exists or not 

//the basic thing is that  find whether the loop exists or not 
//if the loop exists  , after that we give the slow_pointer to the  head  , and from the same position where the slow and fast pointer met initially
//from there continue moving both by one step and the position at which they meet will be the leader 
#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next ;
};

void find_leader_group(node* head)
{
	node* slow_pointer = head;
	node* fast_pointer = head;
	int flag = 0 ;

	while(true)
	{
		if(fast_pointer == NULL)
		{
			cout<<"THE LOOP DOES NOT EXIST "<<endl;
			break;
			
		}
		else
		{
			if(fast_pointer == slow_pointer && fast_pointer != head)
			{
				//the loop exists ;
				flag = 1;
				break;
			}
			else
			{
				if(fast_pointer->next && fast_pointer)
				{
					fast_pointer = fast_pointer->next->next;
					slow_pointer = slow_pointer->next;
				}
			}
		}
	}

	//now if the flag =1  then the loop exists , also flag = 0  means no loop is present 
	if(flag != 0)
	{
		slow_pointer = head ; // again give the slow_pointer to the head ,
		//now move the slow_pointer and the fast_pointer one by one , and where they meet is the  leader of the loop 
		while(slow_pointer != fast_pointer)
		{
			slow_pointer = slow_pointer->next;
			fast_pointer = fast_pointer ->next ;
		}

		cout<<"the leader of the loop is "<<slow_pointer->data<<endl;
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
	find_leader_group(head); //this part is without the loop 
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
	find_leader_group(head); //this part is with the loop 
}