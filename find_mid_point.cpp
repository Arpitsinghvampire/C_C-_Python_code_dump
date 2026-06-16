//find_mid_point.cpp

//here we would need to find the mid point of the linked list , without multiple traversals through the linked list 
#include<iostream>
using namespace std;

struct node
{
	int data ;
	node* next ;
};

//here we will use the slow pointer and the fast pointer to get the  mid point 
//fast pointer moves twice the slow pointer  , when the fast pointer reaches the end the position to which the slow pointer is 
//pointing to will be the mid point 

void mid_point_find(node* head)
{
	node* fast_pointer = head ;
	node* slow_pointer = head ;
	while(fast_pointer && fast_pointer->next) //if i dont ensure this condition then this will lead to segmentation fault because 
		//this condition will only hold if fast_point->next->next is present , that means at max that node can be the second last element
		//after that since there is no memory space available hence you cant access , if you try accessing then segmentation fault
	{
		fast_pointer = fast_pointer->next->next ;
		slow_pointer = slow_pointer->next;
	}
	cout<<"THE MIDDLE ELEMENT OF THE LINKED LIST IS  "<< slow_pointer->data<<endl;
}

int main()
{
	cout<<"ENTER ANY NUMBER , BUT PRESS -1 TO BREAK THE LOOP"<<endl;
	node* head = NULL;
	node* temp = NULL;
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
			node* T = new node ;
			T->data = number;
			if(head == NULL)
			{
				head = T ;
				temp = T;
				temp->next = NULL;
			}
			else
			{
				temp->next = T;
				temp = T;
				temp->next = NULL; //from here we have created the link we required 
			}
		}
	}

	mid_point_find(head);
}