//diameter_binary_tree.cpp

//we have to find the maximum diameter of the binary tree , the only constraint is that it might not pass through the root always
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct node
{
	int data ;
	node* left;
	node* right;
};

//one approach is that for every node , we can find the left height of the node, and the right height of the node , and then 
//sum them , do for all the nodes and then find the max of those diameters 

int max_height(node* root) //here if you pass the left pointer and the right pointer , you will get the max of those heights 
{
	if(root == NULL)
		return 0 ;

	int left_height = max_height(root->left);
	int right_height = max_height(root->right);

	return 1+ max(left_height , right_height);
}

//here we willuse a more optimized approach and that is , since we can find the height of the node  from the max_height function 
//we wont use them seperately 
int findMax(node* root , int maxi)
{
	if(root == NULL)
	{
		return 0 ;
	}
	int left_height = findMax(root->left , maxi);
	int right_height = findMax(root->right , maxi);

	//lets also update the maximum height we will encounter 
	maxi = max(maxi , left_height + right_height);

	return 1+ max(left_height, right_height);
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

void level_order_depth(node* root)
{
	int max_dia = 0 ;
	node* temp = root;
	queue<node*> s1 ;

	//push the root node to the queue
	s1.push(temp);

	while(!s1.empty())
	{
		node* front_pointer = s1.front();

		int inter_depth = 0 ; //tracks intermediate depth ; //reset after every iteration ;
		//pop the front pointer , and then push the children pointer 
		s1.pop();

		if(front_pointer->left)
		{
			s1.push(front_pointer->left);
			inter_depth += max_height(front_pointer->left);
		}
		if(front_pointer->right)
		{
			s1.push(front_pointer->right);
			inter_depth += max_height(front_pointer->right);
		}
		//after doing this you need to find the max of max_depth and the inter depth 
		max_dia  = max(max_dia , inter_depth);

	}

	//after doing this print the max_diameter
	cout<<"THE MAX DIAMETER OF THE  ABOVE TREE IS "<<max_dia+1<<endl;
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

	//now we need to find the max diameter , for this purpose , we will pass the leftpointer and the right pointer for each node
	node* temp1 = root;
	int max_diameter = 0 ;

	//we have to find the diameter for each node , lets do the level order traversal , and from that we find the max depth 
	level_order_depth(root);

	int result = findMax(root , 0 );

	cout<<result<<endl;
}
