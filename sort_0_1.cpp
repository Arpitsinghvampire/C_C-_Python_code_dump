//sort_0_1.cpp

//here in this problem we would be given an array containing some number of 0's or 1's  and 2's we would need to put them in the correct
//position 

#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int data ;
	node* next ;
};

void print_linked_list(node* head)
{
	node* temp = head ;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->next ;
	}
}

int main()
{
	cout<<"ENTER 0 , 1  OR 2  , PRESS -1 TO QUIT THE LOOP :: "<<endl;
	node* temp = NULL;
	node* head = NULL;
	while(true)
	{
		int number ;
		cin>>number ;

		if(number != -1)
		{
			//create a new node 
			node* T = new node;
			T->data = number ;
			if(head == NULL)
			{
				head = T;
				temp = T ;
				temp ->next = NULL;
			}
			else
			{
				temp ->next = T ;
				temp = T ;
			}
		}
		else
			break ;

	}
	//now lets count the number of integers in each part
	int count_0 = 0 ;
	int count_1 = 0 ;
	int count_2 = 0 ;
	node* temp1 = head ;
	while(temp1)
	{
		if(temp1->data == 0)
		{
			count_0++;
		}
		else if(temp1->data == 1)
		{
			count_1 ++ ;
		}
		else
		{
			count_2 ++ ;
		}
		temp1 = temp1->next;
	}

	cout<<"THE ARRAY BEFORE THE SORTING THE ELEMENTS IS "<<endl;
	print_linked_list(head);

	//now after getting the count , lets now create a  sorted array 
	temp1 = head ;
	while(temp1)
	{
		if(count_0 != 0)
		{
			temp1->data = 0 ;
			count_0 -- ;
		}
		else if( count_1 != 0)
		{
			temp1->data = 1 ;
			count_1 --;
		}
		else
		{
			temp1->data = 2;
			count_2--;
		}
		temp1 = temp1->next ;

	}
	//now lets print the linked list 
	cout<<"THE LINKED LIST AFTER SORTING THE ELEMENTS IS GIVEN AS "<<endl;
	print_linked_list(head);




}