//remove_duplicate_sorted_linked_list.cpp

//in this programme we are given the sorted doubly linked list , we need to remove the duplicates from the sorted doubly linked list 

#include<iostream>
using namespace std;

struct node
{
	int data ;
	node* next  = NULL;
	node* prev = NULL ;

};

bool in_order(node* head , int number)
{
	node* temp = head;
	while(temp->next)
	{
		temp = temp->next;
	}
	if(number< temp->data)
	{
		return false;
	}
	return true;
}

void print_linked_list(node* head)
{
	node* temp = head;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}

void remove_duplicates(node* head)
{
	//first we need to check if the current element is same as the previous element 
	//if it is same as the previous element , then check for the next element 
	//if not then we need to update the link 
	//since the linked list is sorted all the elements which are equal would be at the neighbourhood
	node* temp = head;
	node* temp1 = head;

	//here temp1 will traverse forward and temp will alsways point to the first position where the non duplicate points 
	while(temp1)
	{
		if(temp->data == temp1->data)
		{
			//move temp1 forward
			temp1 = temp1->next;

		}
		else
		{
			temp->next = temp1 ; // do the relinking here 
			temp1->prev = temp;
			temp = temp1 ; //then reassign to the first non duplicate pointer 

		}

	}
	temp->next = NULL;
	//we then print the updated linked list ;
	cout<<"the non duplicated  sequence is "<<endl;
	print_linked_list(head);
}

int main()
{
	node* head = NULL;
	node* temp = NULL;

	cout<<"ENTER THE ELEMENTS OF THE LINKED LIST IN THE SORTED ORDER , PRESS -1 TO STOP TAKING THE INPUT "<<endl;

	while(true)
	{
		int number ;
		cin>>number ;

		if(number!= -1)
		{
			node* T = new node;

			if(!head) //would be the first number , which is always sorted 
			{
				T->data = number;
				T->next = NULL;
				T->prev = NULL;
				temp = T;
				head = T;
			}
			else
			{
				if(in_order(head , number))
				{
					node* T = new node;
					T->data = number;
					temp->next = T;
					T->prev = temp ;
					temp = T;
					temp->next = NULL;
				}
			}
		}
		else
			break;
	}
	print_linked_list(head);

	remove_duplicates(head);
}