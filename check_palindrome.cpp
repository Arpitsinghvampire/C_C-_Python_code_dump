//check_palindrome.cpp

//here we are given the input in  the linked klist  , we want to see whether it is a palindrome or not 
#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next ;
}

//now we take the head of the sequence and then check whether it is a palindrome or not 
//in the previous code we had done the reversal of the linked list , 
//here we will make use of that such that 
//the reverse part must be similar to the front part of the list 
node* reverse_link_list(node* head)
{
	node* temp = head;
	node* tail = NULL;
	while(head->next != NULL)
	{
		temp = head ;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		temp->next->next = temp ;
		temp->next = NULL;

	}
}

bool check_palindrome_sequence(node* head , int count)
{
	//if count is odd then check till the mid part 
	//basically we want ot get the mid part  and then reverse the second half of the linked list to check the palindromic sequence 
	if(count%2 == 1)
	{
		//the number of elements is odd , thus you would have to reverse the next half of the linked list
		int count1 = 0 ;
		node* temp = NULL;
		node* mid_point = NULL;
		while(count1 != count/2)
		{
			temp = temp->next ;
			count1 ++ ;
		}
		mid_point = temp ;

		//now we would have to reverse from this point 
		node* temp1 = NULL;
		node* tail = NULL; //put them in the last 
		while(temp1->next == mid_point)
		{
			temp1 = mid_point->next ;
			//now traverse to the end 
			while(temp1->next->next !=NULL)
			{
				temp1 = temp1->next;

			}
			//now from here we will reach the penultimate node 
			if(tail == NULL)
			{
				//then update the pointer 
				tail = temp1->next ;
			}
			temp1->next->next= temp1;

			temp1->next = NULL;
		}
		//so this has set the tail and the head pointers 
		//we now check whether they are same or not 
		node* temp2 = head ;
		node* temp4 = tail ;
		while(temp2!=temp4)
		{
			if(temp2->data != temp4->data)
			{
				return false;
			}
			temp2 = temp2->next ;
			temp4 = temp4->next ;

		}
		return true;
	}

	if(count%2 == 0 )
	{
		// the number of elements is even , so you have to reverse the link after the ceil of the mid
		//now if the count is even then 
		//then we would have to reverse the links from count/2-1 and so on 
		node* mid_point1 = NULL;
		node* tail = NULL;
		int count1 = 0 ;
		node* temp5 = head ;
		while(count1 != count/2 -1)
		{
			temp5 = temp5->next ;
			count1 ++ ;
		}
		//the resulting node would be the smaller node 
		mid_point1 = temp5 ;

		//now we apply the same loop to reverse the linked list 
		while(temp5 ->next != mid_point1)
		{
			temp5 = mid_point1->next ;
			while(temp5->next->next != NULL)
			{
				temp5 = temp5->next ;
			}
			//from here we again get the penultimate node 
			if(tail == NULL)
			{
				tail = temp5->next ;
			}
			//now we try to reverse the link 
			temp5->next->next = temp5 ;
			temp5->next = NULL;
		}
		//now after reversing the links we check for the palindrome 
		temp5 = head ;
		node* temp6 = tail ;


		while(temp6->next != temp5)
		{
			if(temp6->data != temp5->data)
			{
				return false;
			}
			temp6 = temp6->next ;
			temp5 = temp5->next ;

		}

		//this does not cehck the two middle parts 
		if(temp6->data != temp6->next->data)
		{
			return false;
		}
		return true ;
	}

}

int main()
{
	//we would create the linked list of arbitarary size 
	cout<<"ENTER -1 TO  STOP ENTERING THE NUMBER FROM 0 TO 9 ,ENSURE ONLY SINGLE DIGIT "<<endl;
	node* head = NULL;
	node * temp = NULL;
	while(true)
	{
		int number ;
		cin>>number ;
		int count = 0 ;
		if(number >=10)
		{
			cout<<"invalid number "<<endl;
		}
		else if( number >=0 and number <10)
		{
			//we need to create the new  node and then link them 
			count++;
			node* T = new node ;
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
				temp = T;
				temp->next = NULL;
			}

		}
		else
			break;
	}


}