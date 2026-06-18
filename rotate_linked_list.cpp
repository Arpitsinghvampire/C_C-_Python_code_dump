//rotate_linked_list.cpp

//here we would have to rotate a linked list  a given number of times

#include<iostream>
using namespace std;

struct node //here we assume singly linked list 
{
	int data;
	node* next = NULL;
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
void rotate_linked_list(node* head , int times)
{
	int times1 = times;
	while(times1!= 0)
	{
		node* temp = head;

		while(temp->next->next)
		{
			temp = temp->next;
		}
		//this will stop at the second last node 
		node* last_pointer = temp->next;
		temp->next = NULL;
		last_pointer->next = head;
		head = last_pointer;
		times1--;

		cout<<"THE LINKED LIST AFTER BEING ROTATED "<<times-times1<<"TIMES IS "<<endl;
		print_linked_list(head);

	}
	
}
int main()
{
	node* head = NULL;
	node* temp = NULL;

	cout<<"ENTER ANY NUMBER , PRESS -1 TO STOP TAKING THE INPUT "<<endl;
	while(true)
	{
		int number ;
		cin>>number ;

		if(number == -1)
		{
			break;
		}
		else
		{
			node* T = new node;

			T->data = number ;
			if(!head)
			{
				head = T ;
				temp = T;
				temp->next = NULL;
			}
			else
			{
				temp->next = T;
				temp = T;
				temp->next = NULL;
			}
		}
	}

	cout<<"ENTER THE NUMBER OF TIMES YOU WANT TO ROTATE THE LINKED LIST "<<endl;
	int number ;
	cin>>number ;

	rotate_linked_list(head , number);


}