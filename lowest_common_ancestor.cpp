//lowest_common_ancestor.cpp

//we have to find the lowest common ancestor for the nodes
#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

bool root_to_node_path(node* root , vector<int> &path_vector , int target)
{
	if(!root)
	{
		return false;
	}
	path_vector.push_back(root->data);

	if(root->data == target)
	{
		return true ;
	}

	if(root_to_node_path(root->left ,path_vector ,target) || root_to_node_path(root->right ,path_vector ,target))
	{
		return true ;
	}
	//if still we get the true as the return type then we need to pop the vector 
	path_vector.pop_back();

	return false;

}

void lowest_common_ancestor( vector<int> path_vector1 , vector<int> path_vector2 )
{
	//find the one with the lowest size
	int size1 = path_vector1.size();
	int size2 = path_vector2.size();
	vector<int> s;

	if(size1 > size2)
	{
		for(int index = 0 ;index <size2 ; index++)
		{
			if(path_vector1[index] == path_vector2[index])
			{
				s.push_back(path_vector1[index]);
			}
		}
	}
	else
	{
		for(int index = 0 ;index < size1 ; index++)
		{
			if(path_vector1[index] == path_vector2[index])
			{
				s.push_back(path_vector1[index]);
			}
		}
	}

	cout<<s[s.size()-1]<<endl;

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

   vector<int> path_vector;
   cout<<"ENTER THE FIRST NODE "<<endl;
   int target ;
   cin>> target;
   root_to_node_path(root , path_vector , target);

   vector<int> path_vector1 ;
   cout<<"ENTER THE SECOND NODE "<<endl;
   int target1 ;
   cin>>target1;
   root_to_node_path(root , path_vector1 , target1);

   lowest_common_ancestor(path_vector , path_vector1);

    return 0;
}