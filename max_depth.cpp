//max_depth.cpp

//here we want to find the max depth 
// so basically the max depth can be seen as 1+ max(left side length , right side length)
#include<iostream>
#include<queue>

using namespace std;

//there are two approaches , one is the recursie approach and the other is the level order traversal 

struct node
{
	int data ;
	node* left ;
	node* right;
};
//first we will code the recursive approach 
int max_depth(node* root)
{
	if(!root)
	{
		return 0 ;
	}
	int left_height = max_depth(root->left);
	int right_height = max_depth(root->right);

	
	return 1 + max(left_height , right_height);
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

	int max_depth1 = max_depth(root);

	cout<<"THE MAX DEPTH IS GIVEN AS "<<max_depth1<<endl;
}