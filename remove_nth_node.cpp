//remove_nth_node.cpp

// here we have to remove the nth element from the end given in a  singly linked list
#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next ;
};

int main()
{
 // here we will first use the naive approach in which we first check the length of the linked list and then delete the element 
	//create the list first 
	cout<<"ENTER -1 TO STOP CREATING THE NODE "<<endl;
	node* head = NULL;
	node* temp = NULL;
	int count = 0 ;
	while(true)
	{
		int number ;
		cin>>number ;
		if(number != -1)
		{
			count++ ;
			node* T = new node;
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
				temp = T ;
			}
		}
		else
			break;
	}
	//now we want to get the nth last element of the  list 
	cout<<"ENTER THE INDEX YOU WANT TO DELETE "<<endl;
	int number1 ;
	cin>>number1 ;

	if(number1 >count)
	{
		cout<<"you cannot delete that indexed number  this is not possible "<<endl;
	}
	else
	{
		int current_index = 0;
		node* temp1 = head ;
		while(temp1)
		{
			if(count - current_index - 1 != number1+1) //go to the previous node for creating a new link and deleting the present node 
			{
				temp1 = temp1->next ;
				current_index ++ ;
			}
			else
			{
              temp1->next = temp1->next->next ;
              temp1 = temp1->next ->next ;
              current_index ++ ;
			}

		}
	}

	cout<<"the nwe updated array is given as :: "<<endl;
	temp = head ;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->next ;
	}
}