//random_pointers.cpp


//in this question we  are given the linked list we have to make the deep copy of that linked list  , each node has two pointers 
//the next pointer and the random pointer 

#include<iostream>
#include<map>
using namespace std;

struct node
{
	int data ;
	node* next = NULL;
	node* random = NULL;
}; //only some nodes will have the random nodes 

void print_random_pointers(node* head)
{
		node* temp = head;
		cout<<"random links "<<endl;
		while(temp)
		{
			if(temp->random)
				cout<<temp->data<<" ->  "<<temp->random->data<<endl;
			//now increase the temp 
			temp = temp->next;
		}
}

void print_linked_list(node* head)
{
	node* temp = head;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}

int main()
{
	node* head = NULL;
	node* temp = NULL;
	node* tail = NULL;
	cout<<"ENTER ANY NUMBER YOU LIKE , PRESS -1 TO STOP TAKING THE INPUT "<<endl;

	while(true)
		{
			int number ;
			cin>>number ;

			if(number == -1)
			{
				break;
			}
			else
			{
				node* T = new node;
				T->data = number ;
				if(!head)
				{
					temp = T;
					head = T;
					temp->next = NULL;
				}
				else
				{
					temp->next = T;
					temp = T;
					temp->next = NULL;
				}
			}
		}

		tail = temp ;
		//after this we get the linked list  , we now create some random pointers which 
		temp = head;

		temp->random = temp->next->next;


		temp->next->random = tail ;

		//for the time being we are using the above as the random pointers 

		//our goal now is to create adeep copy of the  above linked list 
		temp = head;
		//for each temp , we create node  and in the map we map their addresses 
		map<node* , node*>  pointers_dictionary;
		while(temp)
		{
			node* T = new node;
			T->data = temp->data;
			
			//now store them into the dictionary 
			pointers_dictionary[temp] = T;
			temp = temp->next;
		}
		//from this we populate the temps in the dictionary 
		//now we create the links of the next pointer 
		temp = head;
		while(temp->next)
		{
			node* temp1 = temp->next; //find the next pointer 
			pointers_dictionary[temp] ->next = pointers_dictionary[temp1]; //create link at that address 
			temp = temp->next;
		}

		//now we create the random pointers we had ;
		temp = head;
		while(temp)
		{
			node* temp2 = temp->random;
			if(temp2)
			{
				pointers_dictionary[temp] ->random = pointers_dictionary[temp2];
			}
			temp = temp->next;
		}

		node* head1 = pointers_dictionary[head];

		//now lets print the linked list , we origially had , and the one we reconstructed 
		cout<<"THE ORIGINAL LINKED LIST WE  HAD IS "<<endl;
		print_linked_list(head);

		cout<<"THE RANDOM LINKS WE HAD IN THE LINKED LIST IS "<<endl;
		print_random_pointers(head);

		cout<<"THE RECONSTRUCTED LINKED LIST WE GOT IS "<<endl;
		print_linked_list(head1);

			cout<<"THE RECONSTRUCTED RANDOM LINKS WE GOT IN  THE RESULT IS  "<<endl;
		print_random_pointers(head1);


}
