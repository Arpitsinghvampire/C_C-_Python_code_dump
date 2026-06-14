//reverse_single_linked_list.cpp

//in this code block we will be reversing the linked list given to us 

#include<iostream>
#include<stack>

using namespace std;

struct node
{
	int data ;
	node* next ;

};

node* reverse_linked_list(node* head)
{
 	//in this approach we push the elements onto the stack 
 	node* temp1 = head ;
 	stack<int> s ;
 	while(temp1)
 	{	
 		s.push(temp1->data);
 		temp1 = temp1->next ;

 	}
 	//now after getting the order in the reverse order , now lets get the reversed order 
 	temp1 = head ;
 	while(temp1)
 	{
 		temp1->data = s.top();
 		temp1 = temp1->next ;
 		s.pop();
 	}

 	return head ;
}

//but in the above approach the space complexity also increased to O(n) , we would want to reduce that 
node* reverse_linked_list_better_approach(node* head)
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
	node* temp = head ;
	while(temp)
	{
		cout<<temp->data <<endl;
		temp = temp->next ;
	}
}

int main()
{
	//here we will take the predefined values as the fixed value 
	int count = 0 ;
	node* head = NULL;
	node* temp = NULL;

	while(count <10)
	{
		node* T = new node;
		int number ;
		cin>>number ;
		T->data = number;
		if(head == NULL)
		{
			head = T ;
			temp = T ;
			temp ->next = NULL;
		}
		else
		{
			temp->next = T ;
			temp = T ;
			temp->next = NULL;
		}
		count++;
	}
	//now we have the linked list , now lets get the reverse of the linked list 

	node* head1 = reverse_linked_list(head);

	cout<<"the reversed array is given as "<<endl;

	while(head1)
	{
		cout<<head1->data<<endl ;
		head1 = head1->next ;
	}

	head1 = reverse_linked_list_better_approach(head);
	print_linked_list(head1);
}