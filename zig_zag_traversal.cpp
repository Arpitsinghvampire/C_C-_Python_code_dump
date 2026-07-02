//zig_zag_traversal.cpp

//in this code , we have to do the zig zag traversal that is first start from left to right and then right to left and then again left to right 
//this code is pretty simple 
#include<iostream>
#include<queue>

using namespace std;

//here we wil play with how we will place the elements in the queue
struct node
{
	int data;
	node* left;
	node* right;
};

void zigzag_traveral(node* root)
{
	int flag = 0 ; //if flag is 0 , we place the left hand side first and then the right hand side 
	queue<node*> s1;
	node* temp = root;

	queue<node*> resultant ;

	//push the root on the queue;
	s1.push(temp);

	while(!s1.empty())
	{
		node* front1 = s1.front();
		resultant.push(front1);
		//pop the s1
		s1.pop();

		//now here the insertion changes on the basis of flag variable 
		//if flag is 0 , push from left to right 
		//if flag is 1 push from right to left
		if(flag == 0)
		{
			if(front1->left)
			{
				s1.push(front1->left);
			}
			if(front1->right)
			{
				s1.push(front1->right);
			}
			flag = 1 ; //we have to change the flag then 
		}
		else if(flag == 1)
		{
			if(front1->right)
			{
				s1.push(front1->right);
			}
			if(front1->left)
			{
				s1.push(front1->left);
			}

			//then change the flag 
			flag = 0 ;
		}
	}

	//now we have to get the resultant queue

	while(!resultant.empty())
	{
		cout<<resultant.front()->data<<endl;
		resultant.pop();
	}

}

void insert_element(node* root , int number )
{
	node* temp = root;

	while(temp)
	{
		if(number > temp->data && temp->right != NULL)
		{
			temp = temp->right;
		}
		else if( number <= temp->data && temp->left != NULL)
		{
			temp = temp->left;
		}
		else
		{
			node* T = new node;
			T->data = number;
			T->left = NULL;
			T->right = NULL;
			if(number > temp->data)
			{
				//insert in the right hand side 
				temp->right = T;
			}
			else
			{
				temp->left = T; //insert in the left hand side 

			}
			break;
		}
	}
}

int main()
{
	cout<<"ENTER THE NUMBER YOU WANT TO ENTER , PRESS -1 TO STOP TAKING THE INPUT  "<<endl;
	node* root = NULL;

	while(true)
	{
		int number ;
		cin>> number ;

		if(number == -1)
		{
			break;
		}
		else
		{
			if(root == NULL)
			{
				//create the first node from here in the box
				node* T = new node ;
				T->data = number ;
				T->left = NULL;
				T->right = NULL;
				root = T;
			}
			else
			{
				insert_element(root , number);
			}
		}
	}

	zigzag_traveral(root);

}