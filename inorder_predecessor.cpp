//inorder_predecessor.cpp

//in this code ,we have to find the inorder predecessor for a particular node 
#include<iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

void inorder_predecessor(node* root , int data)
{
	//here we have to find the inorder predecessor , meaning an element just smaller than the key
	
	int max_node = INT_MIN;
	int max_node1 = max_node;
	while(root)
	{
		int current_data = root->data;
		if(current_data >data)
		{
		
		//but we need to find an element smaller than that number
		root= root->left;
		}

		else if(current_data < data)
		{
			max_node = max(max_node , current_data);
			//but we need to find an element greater than that number 
			
			root= root->right;
		}
		else
		{
			//we need to find an element smaller than that number 
			
			root = root->left;
		}
	}
	
	if(max_node1 == max_node)
	{
		cout<<"NO ELEMENT SMALLER THAT THAT AVAILABLE"<<endl;
	}
	else
	{
		cout<<"THE INORDER PREDECESSOR IS GIVEN AS "<< max_node<<endl;
	}

}
