//two_sum_linked_list.cpp

//in this problem we would be given a sorted doubly linked list , we would need to find whether the sum of pairs is equal to a target or not 

#include<iostream>
using namespace std;

struct node
{
	int data ;
	node* next = NULL ;
	node* prev  = NULL;
};

//here we will first code the naive version that is for each element we check for the sum 

void print_pair_sum(node* head , int target )
{
	node* temp = head;
	node* temp1 = temp->next;

	while(temp)
	{
		while(temp1)
		{
			if(temp->data + temp1->data == target)
			{
				cout<<temp->data<<","<<temp1->data<<endl;
				//if the target is found then dont search for the same pair in the forward direction it would only increase 
				break;
			}
			else if(temp->data + temp1->data > target)
			{
				//move to the next iteration 
				break;
			}
			else
			{
				temp1 = temp1->next;
			}
		}
		temp = temp->next;
		if(temp)
		temp1 = temp->next; //update both the temp and the temp1 
		if(!temp)
			temp1 =temp;

	}
}

//now lets see the optimised approach for the above algorithm 
void optimized_approach(node* head ,int  target)
{
	node* left = head;
	node* temp = head;
	while(temp->next)
	{
		temp = temp->next;
	}
	node* right = temp ;

	//the new optimised approach is that when the sum of the left + right > target , 
	//we need to reduce the sum , therefore we only move the right pointer towards the left 
	//if the sum is smaller , we need to increase it , thus we move the left pointer towards the right 
	while(right->next != left) //moment they surpass each other 

	{
		if(left->data+ right->data >target)
		{
			//we need to reduce the sum thus move the right pointer towards the left 
			right = right->prev;
		}
		else if(left->data + right->data <target)
		{
			//we need to increase the sum , this we move the left pointer  towards the right 
			left = left->next;

		}
		else
		{
			//case when they are the same , we need to move both the pointers , one will increase the sum , the other will try to 
			//decrease the sum , thus counter acting each others effect 
			cout<<left->data<<","<<right->data<<endl;
			left = left->next;
			right = right->prev ;
		}
	}


}

bool check_order(node* head , int number)
{
	node* temp = head;
	while(temp->next)
	{
		temp = temp->next;
	} //bsaically the last number should be smaller than the number to be inserted 
	if(number<temp->data)
	{
		cout<<"you cannot insert the number into the linked list "<<endl;
		return false;
	}
	return true;
}

int main()
{
	node* temp = NULL;
	node* head = NULL;

	cout<<"ENTER THE ELEMENTS IN THE SORTED ORDER PRESS -1 TO STOP TAKING THE INPUT "<<endl;

	while(true)
	{
		int number ;
		cin>>number ;



		if(number != -1)
		{

			node* T = new node;
			
			if(!head)
			{
				T->data = number ;
				head = T;
				temp = T;
				temp->next = NULL;
				temp->prev = NULL;
			}
			else
			{
				if(check_order(head , number))
				{
					T->data = number;
					temp->next = T;
					T->prev = temp ;
					temp = T;
					temp->next = NULL;
				}
				
			}
		}
		else
		{
			break;
		}
	}

	cout<<"Enter the target you want to set "<<endl;
	int target ;
	cin>>target ;
	print_pair_sum(head , target);

	cout<<"the following is the output of the optimized approach"<<endl;
	optimized_approach(head , target);
}