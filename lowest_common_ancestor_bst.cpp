//lowest_common_ancestor_bst.cpp

//in this code , we have to find th elowest common ancestor , in a binary tree
////this can be easily done as we have the values in the sorted order ,and we know the structure of the data 
#include<iostream>
using namespace std;

struct node
{
	int data ;
	node* left;
	node* right;
};

node* lca(node* root , int p , int q)
{
	//p and q are the values for comparing the nodes 
	if(root == NULL)
		return NULL;		//base case 

	int current_value = root->data;

	//there are 4 cases , 
	//all on left , all on right , or they are in different  sides  , one is ancestor of another 
	if(current_value == p || current_value == q)
	{
		return root;
	}

    if(current_value > p && current_value > q)
	{
		//the lie on the left hand side 
		return lca(root->left , p , q);
	}

	if(current_value < p && current_value<q)
	{
		return lca(root->right , p , q);
	}




}	