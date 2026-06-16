//finding_length_loop.cpp

//here we have to find the length of the loop , in the previous code we used to find whether the loop exists or not , the slow pointer 
//and the fast pointer met will always be at the loop 
#include<iostream>

using namespace std;
struct node
{
	int data ;
	node* next;
};

void find_loop_length(int flag , node* fast_pointer)
{
	if(flag == 0)
	{
		cout<<"the loop length is "<<0<<endl;
	}
	else
	{
		node* temp = fast_pointer->next;
		int count = 1 ;
		while(temp != fast_pointer)
		{
			count++;
			//then update the temp ;
			temp = temp->next;
		}
		cout<<"the loop length found is "<<count<<endl;
	}
}

void loop_or_not(node* head)
{
	//we again take two pointers here one is the slow pointer and the other is the fast pointer 
	node* slow_pointer = head;
	node* fast_pointer = head;
	int loop_length = 0 ;
	int flag = 0 ;
	//lets refine the function we used earlier 
	while(true)
	{
		if(fast_pointer == NULL)
		{
			cout<<"LOOP NOT FOUND  , LOOP LENGTH "<<loop_length<<endl;
			break;
		}
		else
		{
			//if the fast pointer is not null , then checkk there equality
			if(fast_pointer == slow_pointer &&  fast_pointer != head) //because of the initial condition
			{
				cout<<"LOOP FOUND" <<endl;
				flag = 1;
				break;
			}
			else
			{
				//we move the pointers forward ;
				if( fast_pointer && fast_pointer->next)
				{
					fast_pointer = fast_pointer->next->next;
					slow_pointer = slow_pointer->next;
				}
			}
		}
	}
	//now we need to find the length of the loop;
	find_loop_length(flag , fast_pointer);
		
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