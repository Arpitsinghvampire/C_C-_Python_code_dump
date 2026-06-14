//dutch_flag_staff_algo.cpp

//since we have to segregate between the 0 1 and 2 , in the first list we take all the 0's , in the second list  we atttach all the ones 
//and in the thord list we attach all the 2's 
//in the last we just connect the ending of the previous list to the next list 
//and hence the array will be sorted 
#include<iostream>

using namespace std;
struct node 
{
	int data ;
	node* next ;
};

int main()
{
	node* head = NULL;
	node* temp = NULL;
	cout<<"ENTER EITHER THE NUMBER 0 , 1 OR 2 , ENTER -1 TO BREAK THE LOOP "<<endl;

	while(true)
	{
		int number ;
		cin>>number ;

		if(number!= -1)
		{
			node* T = new node ;
			T->data = number ;
			if(head == NULL)
			{
				//this is the first node
				head = T ;
				temp = T ;

                temp->next = NULL;
			}
			else
			{
				temp->next = T ;
				temp = T;
			}
		}
		else
			break;
	}
	//so we have the list available with us , lets now create three dummy pointers to store the three nodes 
	
	//now lets traverse the linked list 
	node* head0 = new node ;
	head0 ->data = -1 ;
	//we need to point the next to null for the termination of the loop 
	head0 ->next = NULL;
	node* temp0 = head0; //used for traversing the other list 
	node* head1 = new node;
	head1->data = -1 ;
	head1->next = NULL;
	node* temp1 = head1;//used for traversing the other list 
	node* head2 = new node ;
	head2->data = -1 ;
	head2->next = NULL;
	node* temp2 = head2;//used for traversing the other list 

	temp = head ;
	while(temp)
	{
		node* nextNode = temp->next ; //because we are creating the next one to be null , so we would need to remember them that's why 
		if(temp->data == 0)
		{
			temp0->next = temp;
			temp0 = temp ;
			temp0->next = NULL;
			
		}
		else if(temp->data == 1)
		{
			temp1->next = temp ;
			temp1 = temp ;
			temp1->next = NULL;
			
		}
		else
		{
			temp2 ->next = temp ;
			temp2 = temp ;
			temp2->next = NULL;
			
		}

		temp = nextNode ;

	}

	//now after getting the different lists , we now want to segregate them 
	node* temp5 = head0->next;
	temp0->next = head1->next ;
	temp1->next = head2->next;

	//we create a linking for the same  to connect all the other three lists 

	cout<<"kndjwbdfiuf"<<endl;

	//now lets print the linked list 
	while(temp5)
	{
		cout<<temp5->data <<endl;
		temp5 = temp5->next ;
	}



}
