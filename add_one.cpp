//add_one.cpp

//in this code we would be given a number represented by the linked list. we would need to add 1 to the number 
#include<iostream>
using namespace std;

struct node
{
	int data ;
	node* next ;
};

node* reverse_linked_list_better_approach1(node* head)
{
	//basically the last nodes next should point to the penultimate node and so on 
	node* temp = head ;
	node* temp1 = NULL;
	node* tail = NULL;
	while(head->next != NULL)
	{
		temp = head ;
		//so you have the second last element , from which you can access the last element 
		while(temp->next->next !=NULL)
		{
			temp = temp->next ;
		}
		//so you have the penultimate element 
		if( tail == NULL)
		tail = temp->next; //so we have the last element with us 
	    temp->next->next = temp ;
	    temp->next = NULL;
	}

	head = tail ;
	//now we have the linked list in the opposite order 
	return head;

}

void print_linked_list(node* head)
{
	node* temp = head;
	while(temp)
	{
		cout<<temp->data;
		temp = temp->next;
	}
}

//here we first reverse the linked list connections so that we wont need to traverse the list many times 
void reverse_linked_list_better_approach(node* head)
{
	//basically the last nodes next should point to the penultimate node and so on 
	node* temp = head ;
	node* temp1 = NULL;
	node* tail = NULL;
	while(head->next != NULL)
	{
		temp = head ;
		//so you have the second last element , from which you can access the last element 
		while(temp->next->next !=NULL)
		{
			temp = temp->next ;
		}
		//so you have the penultimate element 
		if( tail == NULL)
		tail = temp->next; //so we have the last element with us 
	    temp->next->next = temp ;
	    temp->next = NULL;
	}

	head = tail ;
	//now we have the linked list in the opposite order 
	//now after getting the reversed linked list , we now add 1 
	int carry = 0 ;
	node* temp5 = tail ;

	while(temp5->next!= NULL)
	{
		if(temp5 == tail)
		{
			if(temp5->data + 1 + carry >= 10 )
			{
				int sum = temp5->data + 1 + carry;
				temp5->data  = (sum)%10;
				carry = (sum)/10;
			}
			else
			{
				int sum1 = temp5->data + 1 + carry;
				temp5->data = sum1 ;
				carry = 0 ;
			}
		}
		else
		{
			if(temp5->data + carry >=10)
			{
				temp5->data = (temp5->data + carry)%10;
				carry = temp5->data /10;
			}
			else
			{
				temp5->data = temp5->data + carry ;
				carry = 0;
			}
		}
		temp5 = temp5->next ;
	}
	//now if the carry is not equal to 0 then we need to add one more node 
	if(carry != 0)
	{
		node* T = new node ;
		temp5->next = T ;
		T->next = NULL;
		T->data = carry ;
		temp5 = T;
	}
	//now we write the head and tail 
    
	//now we need to again reverse the  given list 
	head = temp5 ;
	node* temp6 = head;

	head = reverse_linked_list_better_approach1(tail);

	//now lets print the  values of the linked list 
	print_linked_list(head);
}




int main()
{
	//first take the number ;
	cout<<"ENTER THE NUMBER 0-9 PRESS -1 TO EXIT TAKING THE NUMBER "<<endl;
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
		else if(number >=10)
		{
			cout<<"this number is not allowed "<<endl;
		}
		else if(number>=0  && number <10)
		{
			//here we would need to create a new node 
			node* T = new node ;
			T->data = number ;
			if(head == NULL)
			{
				head = T ;
				temp = T ;
				temp->next = NULL;
			}
			else
			{
				temp->next = T ;
				T->next = NULL;
				temp = T ;
			}
		}
		else
		{
			cout<<"number not allowed "<<endl;
		}
	}

	//now after getting the values lets now perform the operation of adding one to the number 

	reverse_linked_list_better_approach(head);
}