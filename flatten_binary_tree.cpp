//flatten_binary_tree.cpp

//in this code ,we have to flatten the binary tree to a linked list , without using any new linked list space 
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct node
{

 	int data;
 	node* left;
 	node* right ;
};

void flatten_binary_tree(node* root)
{
	//the left node points to null in the resultant traversal 
	if(root == NULL)
	{
		return ;															//base case scenario 
	}

	if(root->left == NULL && root->right == NULL)
	{
		return ;
	}
		
	flatten(root->left) ; //this flattens the left sub tree;              //traverse 
	flatten(root->right) ; //this flattens the right sub tree;


	node* temp = root->right;
	root->right = root->left;

	root->left = NULL;

	//we find the last node
	node* temp1 = root;

	while(temp1->right)															//combine
	{
		temp1 = temp1->right;
	}
	//now after getting the last node , you add the nodes to the last 
	temp1->right = temp ;										

}

void other_approach(node* root) //this approach uses the stack 
{
	stack<node*> s1;
	node* prev = NULL;

	s1.push(root);

	while(!s1.empty())
	{
		//push the right side first 
		node* top_element = s1.top();
		s1.pop();
		//now we push the left and the right children into the stack 
		if(top_element->right)
		{
			s1.push(top_element->right);
		}
		if(top_element->left)
		{
			s1.push(top_element->left);
		}
		if(!prev)
		{
			prev = top_element;
		}
		else
		{
			prev->right = top_element;
			prev = top_element;
			prev->left = NULL;
		}

	}
}
int main()
{

}