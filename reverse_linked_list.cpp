//reverse_linked_list.cpp

//here we would reverse the linked list 
#include<iostream>
#include<vector>

using namespace std;

struct node 
{
	int data ;
	node* next ;
	node* prev ;
};


node* reverse_list(vector<int> s)
{
	node* head = NULL;
	node* temp = NULL;
	for(int index = s.size()-1 ; index >=0 ;index--)
	{
		 node* T = new node ;
		 if(index == s.size() -1 )
		 {
		 	T-> data = s[index];
		 	T->next = NULL;
		 	T->prev = NULL;
		 	temp = T;
		 	head = T;
		 }
		 else
		 {
		 	temp->next = T;
		 	T->data = s[index];
		 	T->prev = temp ;
		 	T->next = NULL;
		 	temp = T;
		 }
	}
	return head ;
}

int main()
{
	///now lets get the reversed array fo teh vector 
	vector<int> s {12,13,14,15,16,17,18,23};

	node* temp = reverse_list(s);

	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}