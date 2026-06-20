//preorder_traversal.cpp

//here we will code the pre order traversal
#include<iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;

};


void preorder(node* root)
{
	//the preorder traversal is root left and then right 
	node* temp = root ;
	if(!temp)
	{
		return ;
	}
	cout<<temp->data<<endl;
	preorder(root->left);
	preorder(root->right);
}

void postorder(node* root)
{
	//in this the traversal is left right root 
	node* temp = root;
	if(!temp)
		return;
	//traverse the left side first 
	postorder(root->left);
	postorder(root->right);
	cout<<temp->data<<endl;
}

void inorder_traversal(node* root)
{
	node* temp = root;
	if(!temp)
	{
		return ;
	}
	postorder(temp->left);
	cout<<temp->data<<endl;
	postorder(temp->right);
}

void insert_in_bst(node* root , int number)
{
	//here we want to insert the elements in the binary search tree

	node* temp = root;
	//compare the elements , and then you will reach at teh position 
	//you will always insert at the leaf position 
	while(temp)
	{
		if(temp->data> number && temp->left != NULL)
		{
			//move to the left side
			temp = temp->left;
		}
		else if(temp->data <= number && temp->right != NULL)
		{
			//move to the right side 
			temp = temp->right;
		}
		else
		{ //this tries to stop at the parent node
			if(temp->data >number && temp->left == NULL)
			{
				node* T = new node;
				T->data = number;
				temp->left = T;
				temp =  T;
				temp->left = NULL;
				temp->right = NULL;
				break;
			}
			else
			{
				//add the node to the right hand side 
				node* T = new node;
				T->data = number ;
				temp->right = T;
				temp = T;
				temp->right = NULL;
				temp->left = NULL;
				break;
			}
		}
	}
	

	//we then print the inroder , preorder and the postorder traversal for the tree obtained 
	cout<<"INORDER TRAVERSAL "<<endl;
	inorder_traversal(root);

	cout<<"PREORDER TRAVERSAL "<<endl;
	preorder(root);

	cout<<"POSTORDER TRAVERSAL "<<endl;
	postorder(root);
}

int main()
{
  	cout<<"enter the root node "<<endl;
  	int number ;
  	cin>>number ;

  	node* root_node = new node;
  	root_node->data = number ;
  	root_node->right = NULL;
  	root_node->left = NULL;


  	cout<<"ENTER ANY NUMBER PRESS -1 TO STOP TAKING THE INPUT "<<endl;

  	while(true)
  	{
  		int number1 ;
  		cin>>number1 ;

  		if(number1 == -1)
  			break;
  		else
  		{
  			insert_in_bst(root_node , number1);
  		}
  	}
}
