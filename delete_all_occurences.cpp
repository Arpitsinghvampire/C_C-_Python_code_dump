//delete_all_occurences.cpp

//here we are given a doubly linked  list  and we have to delete all such instances 
#include<iostream>
using namespace std;

struct node
{
	int data ;
	node* next;
	node* prev;
};

void print_linked_list(node* head)
{
	node* temp = head;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}
int main()
{
	//first we intialize the doubly linked list 
	node* head = NULL;
	node* temp = NULL;
	node* tail = NULL;

	cout<<"ENTER ANY NUMBER  PRESS -1 TO STOP TAKING THE INPUT "<<endl;

	while(true)
	{
		int number ;
		cin>>number ;

		if(number == -1)
			break;
		else
		{
			node* T = new node;
			T->data = number ;

			if(head == NULL)
			{
				temp = T;
				head = T;

				temp->next = NULL;
				temp->prev = NULL;
			}
			else
			{
				temp->next = T;
				T->prev = temp ;
				temp = T;
				temp->next = NULL;
			}
		}
		tail = temp ;
	}

	//now lets delete instances having some values 
	cout<<"ENTER THE NUMBER YOU WANT TO DELETE  :: ";
	int number2 ;
	cin>>number2;

	node* temp1 = head;
	while(temp1)
	{
		//now first check for the edge case 
		if(temp1->data == number2 && temp1 == head)
		{
			//transfer the head to next 
			node* temp2 = temp1->next;
			//if there is only one node 
			//then we dont update to below form 
			if(temp2)
			{
				
			temp2 ->prev = NULL;
			temp1->next = NULL;
			temp1 = temp2;
			head = temp2;
			}
		}
		else if(temp1->data == number2 && temp1 == tail)
		{
			node* temp4 = temp1->prev ;
			temp4->next = NULL;
			temp1->prev = NULL;
			tail = temp4;
		}
		else if(temp1->data == number2 )
		{
			node* temp5 = temp1->prev;
			temp5->next = temp1->next ;
			temp1->next->prev = temp5;
			temp1 = temp5->next;
		}
		else
		{
			temp1 = temp1->next;
		}

	}
	if(!head)
	{
		cout<<"THE LIST IS EMPTY "<<endl;
	}

	if(head)
	{
		print_linked_list(head);
	}
	
}
