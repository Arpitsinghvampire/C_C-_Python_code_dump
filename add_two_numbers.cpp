//add_two_numbers.cpp

//here we would be given the digits of the number and then we would need to add the numbers after creating the final number 

#include<iostream>
#include<vector>
using namespace std;


struct node
{
	int data ;
	struct node*  next ;
	struct node*  prev ;
};

int main()
{
	cout<<"ENTER THE NUMBER OF DIGITS IN THE FIRST NUMBER  :: "<<endl;
	int number ;
	cin>>number ;

	//now we keep on creating the node until we reach the required number of digits 
	node* head = NULL;
	node* temp = NULL;
	for(int index = 0 ; index < number ; index++)
	{
		node* T = new node ;
		cout<<"ENTER THE ONE NUMBERED DIGIT YOU WANT TO PUT INTO :: "<<endl;
		cin>>T->data ;
		if(index == 0)
		{
			head = T;
			T->next = NULL;
			T->prev = NULL;
			temp = T;
		}
		else
		{
			temp->next = T;
			T->prev = temp ;
			temp = T;
		}
	}

	//now lets find the sum of the linked list digits we got so far 
	int digit = 0 ;
	int index = 1 ;
	node* temp1 = head ;
	while(temp1)
	{
		digit += temp1->data * index;
		index *= 10 ;
		temp1= temp1->next ;
	}
	cout<<"THE  FIRST DIGIT IS "<<digit<<endl;

	//now lets do the same for the second linked list ;
	cout<<"ENTER THE NUMBER OF DIGITS IN THE SECOND NUMBER "<<endl;
	int number2 ;
	cin>>number2 ;

	//now lets take the number 
	node* head2 = NULL;
	node* temp2 = NULL;

	for(int index2 = 0 ; index2 < number2 ; index2++)
	{
		node* T2 = new node ;
		cout<<"ENTER THE DIGIT YOU WANT TO PLACE "<<endl;
		cin>>T2->data;

		if(index2 == 0)
		{
			head2 = T2;
			T2->prev = NULL;
			T2->next = NULL;
			temp2 = T2;
		}
		else
		{
			temp2->next = T2;
			T2->prev = temp2;
			temp2 = T2;
		}
	}

	//now lets get the number 
	node* temp5 = head2;
	int index4 = 1 ;
	int digit2 = 0 ;
	while(temp5)
	{
		digit2 += temp5->data * index4;
		index4 *= 10 ;
		temp5 = temp5->next ;
	}

	cout<<"THE SECOND NUMBER IS "<<digit2<<endl;

	//now after getting the number  lets add them 
	cout<<"THE FINAL SUM AFTER ADDING BOTH THE DIGITS IS "<<digit2+digit;
}