//vector_to_linked_list.cpp

//here we willl convert a vector into a linked list 
//here we will be given a vector array we would need to comvert into  linked list 
#include<iostream>
#include<vector>

using namespace std;


struct node
{
	int data;
	struct node* next ;
	struct node* prev ;
};

node* create_node(vector<int> s)
{
	node* head = NULL;
	//now lets create a space for a new node 
	node* temp  = NULL;

	for(int index = 0 ; index < s.size() ; index++)
	{
	   node* T = new node ;
		if(index ==0)
		{
			//then you would need to update the head pointer 
			head = T;
			T->data = s[index];
			T->next = NULL;
			T->prev = NULL;
			temp = T;
		}
		else
		{
			temp ->next = T;
			T->prev = temp ;
			T->data = s[index];
			temp = T;
			temp ->next = NULL;
		}
	}
	return head ; //returns the head or the pointer to the first position 
}

int main()
{
	vector<int> s {23,34,1,1,2,5,6};

	node* head  = create_node(s);
	node* temp = head ;


	while(temp)
		{
			cout<<temp->data<<endl;
			temp = temp->next ;
		}


}