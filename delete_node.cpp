//delete_node.cpp

//here we will delete the node , which  has a particular value 
#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int data ;
	struct node* next;
	struct node* prev;
};

node* create_node(node* temp , int data )
{
	node* T = new node;

	T->data = data ;
	temp->next = T;
	T->next = NULL;
	T->prev = temp ;
	temp = T;
	return temp ;
}

node* delete_node(node* head , int number)
{
	
	node* temp = head ;
	while(temp)
	{
		if(temp == head && head->data == number)
		{
			
			temp = temp->next ;
			head->next = NULL;
			head = temp ;
			temp->prev = NULL;
		}
		else
		{
			if(temp->data == number)
			{
				node* temp2 = temp;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev ;
				temp2 = temp->next ;
				temp->next = NULL;
				temp->prev = NULL;
				temp = temp2 ;
			}
			temp  = temp->next;
		}
	}
	return head ;
}

int main()
{
	int number ;
	cout<<"ENTER THE NUMBER OF NUMBERS YOU WANT  TO INSERT INTO THE LINKED LIST ";
	cin>>number;
	node* head = NULL;
	node* temp  = NULL;
	for(int i =0 ; i<number ; i++)
	{
		cout<<"ENTER THE NUMBER YOU WANT TO ENTER :: "<<endl;
		int number1 ;
		cin>>number1;
	  if(i==0)
	  {
	  	node* T = new node ;
	  	T->data = number1;
	  	T->next = NULL;
	  	T->prev = NULL;
	  	temp = T;
	  	head = T;
	  }
	  else
	  	temp = create_node(temp , number1);
	}

	cout<<"THE PRESENT LINKED LIST IS GIVEN AS :: "<<endl;

	node* temp2 = head ;
	while(temp2)
	{
		cout<<temp2->data<<endl;
		temp2 = temp2->next ;
	}


	//now lets delete the node we want ;
	cout<<"ENTER  THE NUMBER YOU WANT TO DELETE ::  "<<endl;
	int number2 ;
	cin>>number2;

	node* head1 = delete_node(head , number2);

	node* temp1 = head1 ;

	cout<<"THE UPDATED LINKED LIST IS GIVEN AS "<<endl;

	while(temp1)
	{
		cout<<temp1->data<<endl;
		temp1 = temp1->next ;
	}




}