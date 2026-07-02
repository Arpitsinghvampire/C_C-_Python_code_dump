//max_depth_sum.cpp

//we have to find the max_depth_sum of the  node , here we will use the optimized approach onpy 
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
	int data ;
	node* left;
	node* right;
};

//so in this question we have to find the max of the left sub tree + the value of the node + the value of the right sub tree 
//so basically the formula becomes  maxL + val+maxR
int maxPathsum(node* root , int &maxi)
{
	if(root == NULL)
	{
		return 0 ;
	}
	int leftsum = maxPathsum(root->left , maxi);
	int rightsum = maxPathsum(root->right , maxi);

	//now update the maxi 
	maxi = max(maxi , root->data + leftsum+ rightsum);


	return root->data + max(leftsum , rightsum);
}
void insert_element(node* root , int number )
{
	node* temp = root;

	while(temp)
	{
		if(number > temp->data && temp->right != NULL)
		{
			temp = temp->right;
		}
		else if( number <= temp->data && temp->left != NULL)
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
				temp->left = T; //insert in the left hand side 

			}
			break;
		}
	}
}


int main()
{
	cout<<"ENTER THE NUMBER YOU WANT TO ENTER , PRESS -1 TO STOP TAKING THE INPUT  "<<endl;
	node* root = NULL;

	while(true)
	{
		int number ;
		cin>> number ;

		if(number == -1)
		{
			break;
		}
		else
		{
			if(root == NULL)
			{
				//create the first node from here in the box
				node* T = new node ;
				T->data = number ;
				T->left = NULL;
				T->right = NULL;
				root = T;
			}
			else
			{
				insert_element(root , number);
			}
		}
	}

	int maxsum = maxPathsum(root , 0 );

	cout<<maxsum<<endl;
}