//delete_middle_node.cpp

//here we would be given the head of the linked list and then we would have to  delete the middle node
//here we will use the fast pointer and the slow pointer method only 

#include<iostream>
using namespace std;


struct node
{
	int data;
	node* next;
};

void print_linked_list(node* head) ;
node* find_prev_middle(node* head)
{
	//this function will take the head as the input and then find the middle -1 element 
	node* fast_pointer = head;
	node* slow_pointer = head;

	node* anti_slow_pointer = head;

	while(fast_pointer && fast_pointer->next)
	{
		fast_pointer = fast_pointer->next->next;
		slow_pointer = slow_pointer->next;

		if(slow_pointer != head->next)
		{
			anti_slow_pointer = anti_slow_pointer->next;
		}
	}
	cout<<"THE MIDDLE ELEMENT IS "<<slow_pointer->data<<endl;
	//after this the middle elment will be given by the slow pointer 
	// we then just link the anti_slow_pointer to the element next of the slow pointer
	anti_slow_pointer->next = slow_pointer->next;
	//then deleter the slow pointer
	delete slow_pointer;



	print_linked_list(head);
	return head;
}

void print_linked_list(node* head)
{
	node* temp = head;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->next ;
	}
}

int main()
{
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
	find_prev_middle(head);
}