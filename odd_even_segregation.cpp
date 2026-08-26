#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
	int data ;
	ListNode* next;
};

ListNode* get_positions_elements(ListNode* head)
{
	if(head== NULL)
		return NULL;
	if(head->next == NULL)
	{
		return head;
	}

	if(head->next->next == NULL)
	{
		return head;
	}
	ListNode* first_odd_element = head;
	ListNode* first_even_element = head->next;

	ListNode* temp = first_odd_element;
	ListNode* temp1 = first_even_element ;

	while(temp1->next && temp1->next->next)
	{
		temp->next = temp1->next;
		temp = temp->next;
		//now we need to link the even part 
		temp1->next = temp->next;
		temp1 = temp1->next;

	}
	if(temp1->next == NULL)
	{
		//no other elements are left 
		head = first_odd_element ;
		temp->next= first_even_element;
	}
	else if(temp1->next != NULL && temp1->next->next == NULL)
	{
		temp->next = temp1->next;
		temp = temp->next;
		temp->next = first_even_element;
		head = first_odd_element;
	}

	return head;
}