//balanced_tree.cpp

//we want to check whether the tree is balanced or not , a tree is balanced , if the difference between their heights is less than 
//or equal to 1 

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct node
{
	int data ;
    node* left ;
    node* right ;
};

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
int find_max_height(node* root)
{
	if(root == NULL)
	{
		return 0 ;
	}
	int left_height = find_max_height(root->left);
	int right_height = find_max_height(root->right);

	return 1+ max(left_height, right_height);
}

//so in the balanced tree we need to see whether the node is  balanced , so we would need to check for every node 
bool check(node* root)
{
	if(root == NULL)
	{
		return true;
	}
	//we then need to check whether it is balanced for that node 
	int left_height = find_max_height(root->left);

	int right_height = find_max_height(root->right);

	if(abs(left_height - right_height)> 1)
	{
		return false;
	}

	//we then need to check for the further left and the right nodes 
	bool check_left_node = check(root->left);

	bool check_right_node = check(root->right);

	if(!check_left_node || ! check_right_node)
		return false;

	return true;
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

	bool check_balance_tree = check(root);

	(check_balance_tree == true) ?  cout<<"YES THIS IS BALANCED " : cout<<"NO THIS IS NOT BALANCED ";
}