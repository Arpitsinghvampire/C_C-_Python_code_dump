//children_sum_property.cpp

//in this code , we have to create a tree such that the parent node is the sum of the left and the right nodes 
//the only catch is that you cannot decrease the node , you can only increase the node
#include<iostream>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

struct node
{
	int data ;
	node* left;
	node* right;
};

void child_node(node* root)
{
	if(!root)
	{
		return ;
	}																//this is the current node computation 
	int child = 0 ;

	if(root->left)
	{
		child += root->left->data;
	}
	if(root->right)
	{
		child += root->right->data;
	}

	if(root->data > child)
	{
		//we then update the children to the root->data				//perform the computation for each node 
		if(root->left)
			root->left->data = root->data;
		if(root->right)
		root->right->data = root->data;
	}
	else
	{
		root->data = child;
	}

	child_node(root->left);											//traverse the node 
	child_node(root->right);

	//now we need to recompute the value of the node 

	int total = 0 ;
																//update the root node after coming back
	if(root->left)
	{
		total = root->left->data;
	}
	if(root->right)
	{
		total = root->right->data;
	}

	if(total->left || total->right)
	{
		//we need to update the root
		root->data = total;
	}

	

}

void insert_element(node* root , int number)
{
    node* temp = root;

    while(temp)
    {
        if(number > temp->data && temp->right != NULL)
        {
            temp = temp->right;
        }

        else if(number <= temp->data && temp->left != NULL)
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
                //insert in the left hand side
                temp->left = T;
            }

            break;
        }
    }
}

int main()
{
    cout<<"Enter the numbers, press -1 to stop taking input"<<endl;

    node* root = NULL;

    while(true)
    {
        int number;
        cin >> number;

        if(number == -1)
        {
            break;
        }

        if(root == NULL)
        {
            //create the first node

            node* T = new node;

            T->data = number;
            T->left = NULL;
            T->right = NULL;

     
           

            root = T;
        }

        else
        {
            insert_element(root, number);
        }
    }

    	child_node(root);

    	
    

    return 0;
}