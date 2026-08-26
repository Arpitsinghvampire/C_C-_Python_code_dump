#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode
{
	int data;
	ListNode* next;
}

ListNode* reverse_linked_list(ListNode* head)
{
	stack<ListNode*> st;

	ListNode* tail = head;
	while(tail->next)
	{
		tail = tail->next;
	}

	//now we try to push all the elements into the stack 
	ListNode* temp = head;

	while(temp!= tail)
	{
		st.push(temp);
		temp = temp->next;
	}
	ListNode* temp1 = tail ;
	while(!st.empty())
	{
		ListNode* front_node = st.top();
		st.pop();
		//now we connec them 
		temp1->next = front_node;
		temp1 = front_node;
	}

	head = tail ;
	return head ;
}
ListNode* reverse_linked_list(ListNode* head , int n)
{
	if(head == NULL)
	{
		return nullptr;
	}
	
	//now we need to delete that node 
	int count1 = n;

	ListNode* reversed_head = reverse_linked_list(head);
	ListNode* temp = reversed_head;
	ListNode* temp2 = temp ;
	//what is the element to be deleted is the first element 
	if(n == 1)
	{
		
		temp2 = temp2->next ;
		temp->next = NULL;
		reversed_head = temp2;
	}
	int count = n-2;
	while(count != 0)
	{
		temp = temp->next;
		count--;
	}

	if(temp->next && temp->next->next) //the element to be deleted is not the last element 
	{
		temp1 = temp->next;
		temp->next = temp->next->next;
		temp1->next = NULL;
		temp = temp->next;
	}
	else //the element to be deleted is the last element 
	{
		temp->next = NULL;
	}
	//now we need to agin reverse the linked list 
	ListNode* true_head = reverse_linked_list(reversed_head);

	return true_head;

}