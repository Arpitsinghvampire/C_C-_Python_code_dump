//morris_traversal.cpp

//this code block uses the threaded tree approach , in this case we create a thread from te past node to the root , which 
//can then help us to access the right hand side of the tree 

#include<iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

void morris_inorder(node* root)
{
    node* current = root;

    while(current != NULL)
    {
        // Case 1: No left subtree
        if(current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }

        // Case 2: Left subtree exists
        else
        {
            // Find the inorder predecessor
            node* predecessor = current->left;

            while(predecessor->right != NULL &&
                  predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            // First visit to current node
            if(predecessor->right == NULL)
            {
                // Create a temporary thread
                predecessor->right = current;

                // Move to left subtree
                current = current->left;
            }

            // Returning from the left subtree
            else
            {
                // Remove the temporary thread
                predecessor->right = NULL;

                // Visit current node
                cout << current->data << " ";

                // Move to right subtree
                current = current->right;
            }
        }
    }
}

/*

void morris_traversal(node* root)
{
	node* temp = root->left;
	//now we we go to the rightmost node of the left sub tree
	while(temp->right!= NULL && temp->right!= NULL) //to gather the already threaded part 
	{
		temp = temp->right;
	}
	//after this we will reach the end of the left sub tree 
	//after getting this lets add the right to the node 
	temp->right = root;
}
*/
