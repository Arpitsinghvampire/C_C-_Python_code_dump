//inorder_successor.cpp

//here we would be given a bst , we have to find the inorder successor of the particular key /node , 
//that is we have to find a number just greater than the key 
#include<iostream>
using namespace std;

void inorder_successor(node* root , int key )
{
	int min_node = INT_MAX;
	int min_node1 = min_node;

	while(root)
	{
		int current_value = root->data;
		if(current_value <=key)
		{
			if(root->right)
			{
				root =root->right;
			}
			
		}
		if(current_value > key)
		{
			//there is a prospective value that it can be an answer 
			min_node = min(min_node , current_value);

			//we then need to move to the left , because right would contain elements greater than that
			if(root->left) 
			root = root->left;

		}
	}
	if(min_node1 == min_node)
	{
		cout<<"NO INORDER SUCCESSOR FOUND "<<endl;
	}
	else
	{
		cout<<"THE INORDER SUCCESSOR FOR THE NODE IS "<<min_node;
	}

	

}