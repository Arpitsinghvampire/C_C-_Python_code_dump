//level_order_traversal.cpp

//in this question we would be given a binary tree , we want to find its level order traversal 
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct node
{
	int data ;
	node* left;
	node* right;
};

void insert_element(node* root , int number)
{
	node* temp = root;
	while(temp != NULL)
	{
		if(temp->data > number && temp->left != NULL)
		{
			//insert in the right hand side 
			temp = temp->left;
		}
		else if(temp->data <= number && temp->right != NULL)
		{
			temp = temp->right;
		}
		else //this ensures you add the node in the correct position 
		{
			//here we need to create a new node 
			node* T = new node;
			T->data = number ;
			if(T->data > temp->data)
			{
				//insert in the right hand side
				temp->right = T;
				T->right = NULL;
				T->left = NULL;
				
			}
			else
			{
				temp->left = T;
				T->left = NULL;
				T->right = NULL;
				
			}
			break;
		}
	}
	return ;

}

void level_order_traversal(node* root)
{
	//after getting the tree lets now get the  level order traversal for the same 
	//for each node  push the elements into the queue
	queue<node*> s1 ;
	node* temp = root ;
	s1.push(temp);

	queue<node*> visited_node ;

	while(!s1.empty())
	{
		//find the topmost node , and its children and then append in the queue
		node* top = s1.front();

		visited_node.push(top);
		s1.pop();
		//after popping the element , you have to push its left and the right children into the stack
		if(top->left)
		{
			s1.push(top->left);
		}
		if(top->right)
		{
			s1.push(top->right);
		}
	}
	//now just print the visited_node
	while(!visited_node.empty())
	{
		cout<<visited_node.front()->data<<endl;
		visited_node.pop();
	}



}

int main()
{
	cout<<"	enter the number you want to enter , press -1 to stop taking the input "<<endl;
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

	cout<<"THE LEVELORDER TRAVERSAL IS GIVEN AS "<<endl;

	level_order_traversal(root);

}