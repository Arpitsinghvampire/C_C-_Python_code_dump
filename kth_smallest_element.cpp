//kth_smallest_element.cpp

//in this code , we have to find the kth smallest element of the binary search tree
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};
void inorder_traversal(node* root , int &count , int k )
{	
	if(root == NULL) //base case 
		return ;
	if(count >k)
		return ;
	
	inorder_traversal(root->left , count , k);				 //traverse
	//this is the case where you print the node 
	count++;
	if(count == k)
	{
		cout<<"Kth smallest element is "<<root->data<<endl;
		return;
	}
	
	inorder_traversal(root->right , count , k);

					//no need to combine here since we are only presenting the result 
}


int main()
{

}