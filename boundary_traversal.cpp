//boundary_traversal.cpp

//here we have to get the boundary traversal for the tree , that is we need to get the boundary elements of the tree 
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node
{
	int data ;
	node* left ;
	node* right;
};

//so basically we try taking the left boundary , the leaf and then the right boundary fro this case 
//so basically there are 3 elements into it , one is the left boundary element , then the leaf nodes and then the right boundary element 
bool is_leaf_node(node* temp)
{
	if(temp == NULL)
	{
		return false;
	}
	else if(temp->left == NULL &&  temp->right == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

//now we need to get the left boundary nodes 
void left_boundary_nodes(node* root)
{
	queue<node*> result ;
	node* temp = root;

	queue<node*> s1 ;
	//we then push the root into the queue data structure 

	result.push(temp);

	//now we need to keep traversing the  left side of the left sub tree
	while(!result.empty())
	{ //we dont add the leaf node here 

		node* front1 = result.front();

		if(is_leaf_node(front1))
		{
			break;
		}

		else
		{
			if(front1->left) //if the left node exists for that front node 
			{
				result.push(front1->left);
			}

			else if(front1->right) //if the left node does not exist , you have to push the right node because that will be the  boundary element in the other case 
			{
				result.push(front1->right);
			}
			//after pushing the child , you have to pop the element from the queue and then push into s1
			s1.push(front1);
			result.pop();
		}
		
	}

	//now we print the left sub tree excluding the leaf nodes 
	cout<<"LEFT SUB TREE BOUNDARY NODES "<<endl;
	while(!s1.empty())
	{
		cout<<s1.front()->data<<endl;
		s1.pop();
	}
}

//now lets get the leaf nodes

void leaf_nodes(node* root)
{
	if(root == NULL)
	{
		return ;
	}

	if(is_leaf_node(root)) //base case 
	{
		cout<<root->data<<endl;
		return ;
	}
	//now we need to traverse the leaf_nodes 
	leaf_nodes(root->left);
	leaf_nodes(root->right);
}

void right_boundary_nodes(node* root)
{
	//here we print the right side nodes in the reverse order , for this purpose we will use the stack 
	stack<node*> s1 ;
	node* temp = root;

	stack<node*> resultant ;

	//here we wont push the root , instead we push the root->right , as we have already pushed the root 
	if(temp->right)
	{
		s1.push(temp->right);

		//now we keep on pushing the right of the top element 

		while(!s1.empty())
		{	
			node* top1 = s1.top();
			s1.pop();
			resultant.push(top1);

			//push the right hand side , if it exists
			if(top1->right)
			{
				s1.push(top1->right);
			}
			else if(top1->left)
			{
				s1.push(top1->left);
			}
			else
			{
				//reaches the leaf node
				break;
			}

		}

		//now after getting the stack we pop it and print the elements 
		cout<<"THE RIGHT HAND BOUNDARY IS "<<endl;

		while(!resultant.empty())
		{
			cout<<resultant.top()->data<<endl;
			resultant.pop();
		}

	}
	else
	{
		return ; //if no element in the right , the programme stops 
	}
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

	left_boundary_nodes(root);

	cout<<"THE LEAF NODES ARE "<<endl;
	leaf_nodes(root);

	right_boundary_nodes(root);
}