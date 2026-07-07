//construct_bst_preorder_traversal.cpp

//here we would be given a preorder traversal , we then have to create a binary search tree using that 
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct node
{
	int data ;
	node* left;
	node* right ;
};

node* create_bst(vector<int> preorder_traversal) //preorder is root left right 
{
	//base case is when the preorder traversla array is empty 
	if(preorder_traversal.empty())
		return NULL;

	int current_root_element = preorder_traversal[0];
	//now this acts as the root node
	node* T = new node ;
	T->data = current_root_element ;

	//now you would need to scan all the elements lesser than the root element 
	vector<int> left_preorder ;
	vector<int> right_preorder;

	for(int x: preorder_traversal)
	{
		if(x> current_root_element)
			right_preorder.push_back(x);
		if(x < current_root_element)
			left_preorder.push_back(x);
	}

	//now we traverse 
	T->left = create_bst(left_preorder);
	T->right= create_bst(right_preorder);

	return T;


}
int main()
{

}