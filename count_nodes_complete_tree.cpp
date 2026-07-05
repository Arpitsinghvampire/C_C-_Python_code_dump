//count_nodes_complete_tree.cpp

//a complete tree is a tree where the nodes are filled from top to bottom and then left to right 
//so we need to design an alforithm that finds the number of nodes in less than O(n) complexity 
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
struct node
{
	int data ;
	node* left ;
	node* right;
};

void count_nodes(node* root)
{
	//here we wil follow the baseline approach to count the number of nodes by somply traversing the nodes 
	//here we will follow the level order traversal 
	queue<node*> s1;
	s1.push(root);
	int count = 0 ;
	while(!s1.empty())
	{
		node* front1 = s1.front();

		s1.pop();
		count ++ ; //we increment the counter after they are popped 

		if(front1->left)
		{	
			s1.push(front1->left);
		}
		if(front1->right)
		{
			s1.push(front1->right);
		}

	}

	cout<<"the number of nodes are "<<count ;
}

//now lets write another optimized approach for the following 
//since it is a complete binary tree the elements are filled from left to right and top to bottom , thus if we are able to find 
//the height of the tree , we can then tell the number of nodes in the tree 
int find_height_left(node* root)
{
	int height = 0 ;
	while(root)
	{
		root = root->left;
		height ++ ;
	}
	return height;
}

int find_height_right(node* root)
{
	int height = 0 ;
	while(root)
	{
		root  = root->right;
		height ++ ;
	}
	return height;
}
int find_nodes(node* root)
{
	if(root == NULL)
	{
		return 0 ;
	}
	int left_height  = find_height_left(root);
	int right_height = find_height_right(root);

	if(left_height == right_height)
	{
		return (1<<lh) - 1;
	}
	return 1+ find_nodes(root->left) + find_nodes(root->right);

}

int main()
{

}