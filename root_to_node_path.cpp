//root_to_node_path.cpp

//here we  have to find the path from the node to the root , for this question we will use the traversal method particularly the 
//preorder traversal and then make changes to it 
#include<iostream>
#include<queue>
#include<stack>

using namespace std;
struct node
{
	int data ;
	node* left;
	node* right;
};

bool node_to_root(node* root , vector<int> &path_vector ,int target)
{
	if(!root)
	{
		return false;
	}
	path_vector.push_back(root->data);

	if(root->data == target)
	{
		return true;
	}

	if(node_to_root(root->left , path_vector , target) || node_to_root(root->right , path_vector , target))
	{
		return true;
	}
	path_vector.pop_back();
	return false;

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

            //initialize the coordinates
            T->x_coordinate = 0;
            T->y_coordinate = 0;

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

            //initialize coordinates
            T->x_coordinate = 0;
            T->y_coordinate = 0;

            root = T;
        }

        else
        {
            insert_element(root, number);
        }
    }

   vector<int> path_vector;
   cout<<"ENTER THE TARGET YOU WANT TO SET "<<endl;
   int target ;
   cin>> target;
   node_to_root(root , path_vector , target);

    return 0;
}