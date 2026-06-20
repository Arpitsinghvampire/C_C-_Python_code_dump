//binary_search_tree.cpp

//here  we will code the binary search tree 
#include<iostream>
using namespace std;

struct node
{
	int data;
	node* left = NULL;
	node* right=  NULL;
};

void print_tree(node* root)
{
    if(root == NULL)
        return;

    cout << "Node : " << root->data;

    if(root->left)
        cout << " Left : " << root->left->data;
    else
        cout << " Left : NULL";

    if(root->right)
        cout << " Right : " << root->right->data;
    else
        cout << " Right : NULL";

    cout << endl;

    print_tree(root->left);
    print_tree(root->right);
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
	//after this you will reach the leaf node
	cout<<"THE RESULTANT TREE IS  "<<endl;
	print_tree(root);
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