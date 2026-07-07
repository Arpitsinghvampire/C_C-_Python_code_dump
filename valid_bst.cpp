//valid_bst.cpp

// we have to tell whether the binary tree given to us is a valid bst or not 
#include<iostream>
using namespace std;
struct node
{
	int data ;
	node* left;
	node* right ;
}
bool valid_bst(node* root , int min_value , int max_value) //for each node we would have the range if withinb range then return true else false 
{
	if(!root)
	{
		return true;			//base case 
	}

	if(root->data >= max_value || root->data <=min_value)
		return false;

	//traverse and then combine the above two steps 
	return valid_bst(root->left ,min_value , root->data) && valid_bst(root->right , root->data , max_value);
}

