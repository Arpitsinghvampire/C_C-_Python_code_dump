//construct_inorder_preorder.cpp

//here in this code block we will focusing on creating a binary tree using the inorder and preorder traversal 
//in order to create a unoque tree , we either have to have an inorder + preorder/postorder traversal 
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node
{
	int data ;
	node* left;
	node* right ;
};

//here we will be given a preorder traveral and the inorder traversal 
//preorder traversal is root , left and then right 
//inorder traversal is left root right 
node* create_tree(vector<int> inorder_traversal , vector<int> preorder_traversal  )
{
	if(inorder_traversal.empty() || preorder_traversal.empty())
	{
		return NULL;
	}
	int root_element = preorder_traversal[0];
	node* T = new node ;
	
	T->data = root_element;
	T->left = NULL;
	T->right = NULL;
	

	//seperate into the left inorder and the right inorder and then the left preorder and the right preorder 
	int index = find(inorder_traversal.begin() , inorder_traversal.end() , root_element) - inorder_traversal.begin();

	vector<int> left_inorder(inorder_traversal.begin() , inorder_traversal.begin() + index);
	vector<int> right_inorder(inorder_traversal.begin()+index+1 , inorder_traversal.end());

	vector<int> left_preorder(preorder_traversal.begin()+1 ,preorder_traversal.begin()+1 + left_inorder.size());
	vector<int> right_preorder(preorder_traversal.begin()+1+left_inorder.size() , preorder_traversal.end());

	root->left = create_tree(left_inorder , left_preorder);
	root->right = create_tree(right_inorder , right_preorder);

	return root ;

	

}

int main()
{

}