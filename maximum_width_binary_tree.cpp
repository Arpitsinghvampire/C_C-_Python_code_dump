//maximum_width_binary_tree.cpp

//the maximum width of the binary tree is given as the maximum  umber of nodes in a particular level 
//there can be imaginery nodes in  between we assume that they too take a space 
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};

//lets start with the level order traversal 
int level_order_traversal(node* root)
{
	queue<pair<node* , int>> s2;
	s2.push({root , 0});
	int ans = 0 ;
	while(!s2.empty())
	{
		int size = s2.size();
		int min_index = s2.front().second();
		int first,last;

		for(int index = 0 ; index < size ; index++)
		{
			node* front_1 = s2.front().first();
			int current_id = s2.front.second() - min_index;

			s2.pop();

			if(i == 0)
			{
				first = current_id;
			}
			if(i == size-1)
			{
				last = current_id;
			}
			if(node->left)
			{
				s2.push({root->left , 2*current_id+1});
			}
			if(node->right)
			{
				s2.push({root->right , 2*current_id + 2});
			}



		}
		ans = max(ans , last-first+1);

	}
	return ans ;

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

    int max_width = level_order_traversal(root);
    cout<<max_width<<endl;

    return 0;
}