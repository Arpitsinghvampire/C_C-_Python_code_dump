//add_two_numbers_v2.cpp

//here we will follow another approach for the add two linked list . here we will add the  list one at a time 
//we wont find the new number created 
#include<iostream>
#include<vector>

using namespace std;

struct node 
{
	int data ;
	node* next ; //here we will use only a single direction  pointer 
};


void print_linked_list(node* head)
{
	node* temp = head;
	while(temp)
	{
		cout<<temp->data;
		temp = temp->next ;
	}
	cout<<endl;
}

node*  sum_element_wise(node* head , node* head2)
{
	//here we will take two heads and then add the elementwise 
	node* temp = head ;
	node* temp1 = head2 ;
	//here we will create another list containing the elements of the sum of the above two elements 
	node* head3 = NULL;
	node* temp3 = NULL;
	int carry = 0 ;

	while(temp || temp1)
	{
		node* T = new node ;
		// this part was for the data 
		if(temp->data+ temp1->data + carry <10)
		{
			T->data = temp->data + temp1->data + carry ;
			carry = 0 ;
			if(head3 == NULL)
			{
				head3 = T;
				temp3 = T;
				temp3->next = NULL;
			}
			else
			{
				temp3->next = T;
				temp3 = T;
			}


		}
		else
			{
				T->data = (temp->data + temp1->data + carry)%10 ;
				carry =  (temp->data + temp1->data + carry)/10;

				if(head3 == NULL)
					{
				head3 = T;
				temp3 = T;
				temp3->next = NULL;
					}
			else
					{
				temp3->next = T;
				temp3 = T;
					}
			}
			temp = temp ->next ;
	   temp1 = temp1->next ;


	}
	// the major problem will be when the computation is complete but the carry is not 0 , then create another place 
	if(carry!= 0)
	{
		node* T1 = new node;
		T1->data = carry;
		temp3 ->next = T1;
		temp3 = T1;
	}
	return head3 ;
}
int main()
{
	cout<<"ENTER -1 TO STOP ENTERING THE  FIRST NUMBER "<<endl;
	node* head = NULL;
	node * temp = NULL;

	while(true)
	{	
		int number ;
		cin>>number ;
		if(number != -1)
		{
			node* T = new node;
			T->data = number ;
			if(head == NULL) //this means this is the first node 
				{
					head = T;
					temp = T;
					temp ->next = NULL;
				}
			else
			{
				temp->next = T;
				temp = T;
			}
		}
		else
			break;

	}
	//from here we would get the first linked list 
	//now lets get the second linked list 
	cout<<"YOU ARE NOW ENTERING THE SECOND NUMBER  PRESS -1 TO STOP TAKING THE NUMBER "<<endl;

	node* head2 = NULL;
	node* temp2 = NULL;

	while(true)
	{
		int number1 ;
		cin>>number1 ;
		if(number1 != -1)
		{
			node* T = new node ;
			T->data = number1 ;

			if(head2 == NULL)
			{
				head2 = T;
				temp2 = T;
				temp2->next = NULL;
			}
			else
			{
				temp2->next = T;
				temp2 = T;
			}
		}
		else
			break;
	}

	//now we  have the two linked list  , lets print the linked list 
	print_linked_list(head);
	print_linked_list(head2);

	node* head3 = sum_element_wise(head ,head2);

	cout<<"THE SUMMED LINKED LIST IN REVERSED ORDER  IS GIVEN AS "<<endl;
	print_linked_list(head3);
}