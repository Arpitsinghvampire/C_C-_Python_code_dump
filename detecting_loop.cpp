#include<iostream>
#include<vector>

using namespace std;

struct ListNode
{
	int data ;
	ListNode* next;
};

bool detect_cycle(ListNode* head)
{
	if(head == NULL)
		return false;
	if(head->next == NULL)
		return false;
	//we need to move the slow_pointer by one position and the fast_pointer  by 2 position 
	ListNode* slow_pointer = head;
	ListNode* fast_pointer = head;

	while(slow_pointer->next && fast_pointer->next && fast_pointer->next->next)
	{
		slow_pointer = slow_pointer->next;
		fast_pointer = fast_pointer->next->next;
		if(slow_pointer == fast_pointer)
			return true;
	}
	return false;
}