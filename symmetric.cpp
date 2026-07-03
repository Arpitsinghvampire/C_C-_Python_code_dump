//symmetric.cpp

//we have to find whether the tree is symmetric or not 

//we can do this by the traversal 
//find the levelorder or any other traversal  for the left subtree and the right sub tree and then  check whether they are same or not 
#include<iostream>
#include<queue>

using namespace std;
struct node
{
	int data ;
	node* left ;
	node* right ;
};

void symmetric_or_not(node* root)
{
	queue<node*> s1;

	queue<node*> left_sub_tree;
	queue<node*> right_sub_tree;

	if(root->left && !root->right)
	{
		cout<<"THEY ARE NOT SYMMETRIC";
		return;
	}
	else if(root->right && !root->left)
	{
		cout<<"THEY ARE NOT SYMMETRIC";
		return;
	}
		
		else
		{
			left_sub_tree.push(root->left);
			right_sub_tree.push(root->right);

			while(!left_sub_tree.empty())
			{
				node* front1 = left_sub_tree.front();
				node* front2 = right_sub_tree.front();

				left_sub_tree.pop();
				right_sub_tree.pop();

				if(front1->data != front2->data)
				{
					cout<<"NOT SYMMETRIC "<<endl;
					return ;
				}
				else
				{
					if(front1->left && front2->right)
					{
						left_sub_tree.push(front1->left);
						right_sub_tree.push(front2->right);
					}
					else if(front1->right && front2->left)
					{
						left_sub_tree.push(front1->right);
						right_sub_tree.push(front2->left);
					}
					else if(!front1->right && front2->left || front1->left && !front2->right)
					{
						cout<<"NOT SYMMETRIC"<<endl;
						return;
					}
				}

			}

			//after all this if the right sub tree is not empty then it is not symmetric 
			if(!right_sub_tree.empty())
			{
				cout<<"THE  TREE IS NOT SYMMETRIC "<<endl;
				return ;
			}
			else
			{
				cout<<"THE TREE IS SYMMETRIC "<<endl;
				return ;
			}
	
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

    
    symmetric_or_not(root);
   
}