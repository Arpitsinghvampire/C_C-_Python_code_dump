//merge_sorted_linked_list.cpp

//here we have to merge the two sorted linked list 
#include<iostream>
using namespace std;

struct node
{
	int data ;
	node* next = NULL;
};

void print_linked_list(node* head)
{
	node* temp= head;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}

bool bigger_of_two(node* head1 , node* head2)
{
	node* temp = head1 ;
	int count1 = 0 ;
	int count2 = 0 ;
	while(temp)
	{
		temp = temp->next;
		count1++;
	}
	temp = head2;
	while(temp)
	{
		temp = temp->next;
		count2++;
	}
	if(count1 >= count2)
		return true;
	else
		return false;

}

//here we will send the bigger of the two linked list into the head1 

void merge_sorted_linked_list(node* head1 , node* head2)
{
	node* temp1 = head1 ;
	node* temp2 = head2;
	node* dummyNode = new node;

	node* dummy1 = dummyNode;
	node* head3 = dummy1;

	dummyNode->data = -1 ;

	while(temp1 && temp2)
	{
		if(temp1->data <= temp2->data)
		{
			dummy1->next= temp1 ;
			dummy1 = temp1 ;
			//now we also need to increase the temp1
			temp1 = temp1->next;
		}
		else
		{
			dummy1 ->next = temp2;
			dummy1 = temp2;
			temp2 = temp2->next ;
		}
	}
	//now we also have to handle the case where one linked list traversal finishes early
	if(!temp1)
	{
		while(temp2)
		{
			dummy1 ->next = temp2;
			dummy1 = temp2;
			temp2 = temp2->next;
		}
	}
	else
	{
		//the second temp finishes early 
		while(temp1)
		{
			dummy1->next = temp1;
			dummy1 = temp1;
			temp1 = temp1->next;
		}
	}
	//now lets print the loop 
	print_linked_list(head3->next);
}

int main()
{
	node* head1 = NULL;
	node* temp1 = NULL;

	node* head2 = NULL;
	node* temp2 = NULL;
	cout<<"ENTER ANY NUMBER , PRESS -1 TO STOP TAKING THE INPUT  THIS IS THE LINKED LIST 1 "<<endl;
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
			if(!head1)
			{
				head1 = T ;
				temp1 = T;
				temp1->next = NULL;
			}
			else
			{
				temp1->next = T;
				temp1 = T;
				temp1->next = NULL;
			}
		}
	}

	cout<<"ENTER ANY NUMBER , PRESS -1 TO STOP TAKING THE INPUT  THIS IS THE LINKED LIST 2 "<<endl;
	while(true)
	{
		int number1 ;
		cin>>number1 ;

		if(number1 == -1)
		{
			break;
		}
		else
		{
			node* T = new node;

			T->data = number1 ;
			if(!head2)
			{
				head2 = T ;
				temp2 = T;
				temp2->next = NULL;
			}
			else
			{
				temp2->next = T;
				temp2 = T;
				temp2->next = NULL;
			}
		}
	}

	print_linked_list(head1);
	cout<<endl;
	print_linked_list(head2);

	if(bigger_of_two(head1 , head2))
	{
		merge_sorted_linked_list(head1 , head2);
	}
	else
		merge_sorted_linked_list(head2 , head1);

}