//flatten_linked_list.cpp

//in this question we are given nodes , which have child pointers each we have to  flatten the pointers 
#include<iostream>
using namespace std;

struct node
{
	int data ;
	node* next = NULL;
	node* down =  NULL;
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

void flatten_function(node* head)
{
	node* temp = head;
	node* temp1 = head;
	//one pointer will go towards the right , and the other pointer will go downwards ,if it exists 
	node* dummyNode = new node ;
	node* dummy = dummyNode;
	dummyNode ->data = - 1;
	node* head1 = dummy;
	
	while(temp) //this pointer goes towards the right side 
	{
		temp = temp->next; //first store the pointer to the next position and then update the pointer 
		while(temp1) //this pointer goes down
		{
			dummy->next =temp1;
			dummy = temp1 ;
			temp1 = temp1->down; 
		}
		//we then move towards the right hand side 
		temp1 = temp;
	}
	dummy->next = NULL;

	//now after flattening the linked list ,we now need to print the linked list 
	print_linked_list(head1->next);

	//now we also need to sort the above linked list we got 

}

int main()
{
	node* head = NULL;
	node* temp = NULL;
	node* temp1 = NULL;


	//lets take a predefined linked list set 
	int count = 10;
	while(count)
	{
		node* T = new node;
		T->data = count ;

		if(!head)
		{
			head = T;
			temp = T;
			temp->next = NULL;
			temp->down = NULL;
		}
		else
		{
			temp->next = T;
			temp = T;
			temp->next = NULL;
			temp->down = NULL;

		}

		count -- ;
	}
	//now we have fixed the  the left to right pointers , we now want to fix the child pointers 
	temp = head;
	int count1 = 5;
	while(count1)
	{
		node* T = new node;
		T->data = count1;
		temp->down = T;
		temp =T;
		count1--;
	}

	temp = head->next;
	count1 = 4;
	while(count1)
	{
		node* T = new node;
		T->data = count1;
		temp->down = T;
		temp =T;
		count1--;
	}

	temp = head->next->next;
	count1 = 3;
	while(count1)
	{
		node* T = new node;
		T->data = count1;
		temp->down = T;
		temp =T;
		count1 --;
	}

	//now we have created our multi level linked list , we now want to flattent the linked list 
	//print_linked_list(head);

	flatten_function(head);
}