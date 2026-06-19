//merge_k_sorted_linked.cpp

//in this question we are given the k sorted linked list , we need to  merge the k sorted linked list , here , we will work with k= 3
#include<iostream>
#include<vector>

using namespace std;

struct node
{
	int data;
	node* next;
};

void print_linked_list(node* head)
{
	node* temp = head;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}

}
void sorted_k_linked_list(vector<node*> heads)
{
	vector<node*> temp_vectors;
	for(int index = 0 ; index < heads.size() ; index++)
	{
		node* temp = heads[index];
		temp_vectors.push_back(temp);
	}
	//now we create dummy node 
	node* dummyNode = new node;
	dummyNode->data = -1;
	dummyNode->next = NULL;
	node* dummy = dummyNode;
	node* head1 = dummyNode;

	int flag = 0 ;
	while(true)
	{
		//check for the values of all the temp stored in each index 
		int min_index = 0 ;
		int min_value = INT_MAX;
		node* current_pointer = NULL;
		for(int index = 0 ; index < temp_vectors.size() ; index++)
		{
			//we need to find the minimum value for the particular iteration 
			if(temp_vectors[index])
			{
				if(min_value >= temp_vectors[index]->data)
				{
					min_value = temp_vectors[index]->data;
					min_index = index;
				}
			}
		}
		//from here we have the min index and the min value , now we have to join the indices 
		//first update that particular index temp to next , so that we are able to traverse 
		node* pointer1 = temp_vectors[min_index] ;
		temp_vectors[min_index] = temp_vectors[min_index]->next;
		//now update the link 
		dummy->next = pointer1 ;
		dummy = pointer1 ;
		pointer1->next = NULL;


		//we need to stop the loops when all the values are null 
		int count_null_values = 0 ;
		for(int index = 0 ; index<temp_vectors.size() ; index++)
		{
			if(!temp_vectors[index]) //count the number of null values 
			{
				count_null_values ++;
			}
		}
		if(count_null_values == temp_vectors.size())
		{
			break;
		}
	}
	//we then need to print the linked list 
	print_linked_list(head1->next);

}

int main()
{
	int number_of_sorted_linked_list ;
	cout<<"ENTER THE NUMBER OF SORTED LINKED LIST YOU WANT  ::  ";
	cin>>number_of_sorted_linked_list;

	int number1 = number_of_sorted_linked_list;

	vector<node*> captures_head; //this stores the head for all the linked list 
	while(number1)
	{
		cout<<"You are entering the  "<<number_of_sorted_linked_list-number1+1 <<" linked list "<<endl;
		cout<<"ENTER THE SORTED LINKED LIST  , PRESS -1 TO STOP TAKING THE INPUT "<<endl;

		node* head = NULL;
		node* temp = NULL;
		while(true)
		{
			int number ;
			cin>>number;

			if(number != -1)
			{
				node* T = new node;
				T->data = number ;
				if(!head)
				{
					head = T;
					temp = T;
					temp->next = NULL;
					captures_head.push_back(head);
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
		number1--;
	}

	//from here we would get the  vector containing the heads for all the linked list 
	sorted_k_linked_list(captures_head);
}