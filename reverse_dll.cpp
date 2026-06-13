//reverse_dll.cpp

//in this programme we will reverse the already given dll  with no new space comsumed 
//since we are given the dll that means we are also given the  previous pointer also 
#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int data ;
	struct node* next ;
	struct node* prev;
};

//now after creating the node , we will noew start reversing the linked list 
//here in this function we will use the tail also to get to the end point directly 
void reversed_dll(node* tail )
{
	//since we have the last node given to us  , we will now use that to build the reversed dll 
	while(tail)
	{
		cout<<tail->data<<endl;
		tail = tail->prev;
	}
}

//now we have to change in place
void change_in_place(node*tail , node* head)
{
	node* temp = tail;

	node* temp1 = tail->prev;
	node* temp2 = NULL;

	while(temp1)
	{
		temp->next = temp1;
		temp->prev = NULL;
		temp1->next = NULL;
		temp2 = temp1->prev ;
		temp1->prev = temp ;
		temp = temp1;
		temp1 = temp2;


	}
	head = tail;

	node* temp4 = head;
	while(temp4)
	{
		cout<<temp4->data<<endl;
		temp4 = temp4->next;
	}

}

int main()
{
	int number ;
	cout<<"ENTER THE NUMBER OF INTEGERS YOU WANT TO  HAVE IN YOUR DOUBLY LINKED LIST ";
	cin>>number ;

	node* head = NULL;
	node* tail = NULL;
	node* temp = NULL;
	node* temp1 = NULL;
	for(int  i =0 ; i< number ; i++)
	{
		cout<<"ENTER THE NUMBER YOU WANT TO PUSH INTO THE LINKED LIST ";
		int number1 ;
		cin>>number1 ;
		temp1 = new node ;
		temp1 ->data = number1 ;
		if(i ==0)
		{	
			temp1 ->next = NULL ;
			temp1 ->prev = NULL;
			head = temp1;
			temp = temp1 ;
		}
		else
		{

			temp1->prev = temp ;
			temp ->next = temp1 ;
			temp1->next = NULL;
			temp = temp1 ;

		}
	}

	node* temp5 = head ;
	while(temp5->next != NULL)
	{
		temp5 = temp5->next ;

	}
	tail = temp5 ;


	//now having created the number lets now reverse the doubly linked list 
	reversed_dll(tail);

	change_in_place(tail , head);


}