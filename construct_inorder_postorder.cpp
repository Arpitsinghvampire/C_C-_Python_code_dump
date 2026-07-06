//construct_inorder_postorder.cpp

//here we would be given a inorder traversal and a postorder traversal , now we need to create a new tree using the two traversals
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct node
{
	int data;
	node* left;
	node* right;
};

node* create_tree(vector<int> &inorder_traversal, vector<int> & postorder_traversal)
{
	if(inorder_traversal.empty() || postorder_traversal.empty())
	{
		return NULL;
	}
	//here the root would be the last element , because the postorder traversal is done like left , right and then root
	node* root = new node;
	root->data = *(postorder_traversal.end()-1);
	root->left = NULL;
	root->right = NULL;
	int index = find(inorder_traversal.begin() , inorder_traversal.end() , root->data)-inorder_traversal.begin();

	vector<int> left_inorder(inorder_traversal.begin() , inorder_traversal.begin() + index);
	vector<int> right_inorder(inorder_traversal.begin()+index+1 , inorder_traversal.end());

	vector<int> left_postorder(postorder_traversal.begin() , postorder_traversal.begin() + left_inorder.size());
	vector<int> right_postorder(postorder_traversal.begin()+left_inorder.size() , postorder_traversal.end()-1);

	root->left = create_tree(left_inorder , left_postorder);
	root->right = create_tree(right_inorder , right_postorder);

	return root ;

}


int main()
{

}