//same_tree_or_not.cpp

//we will be given two trees , ww have to find whether they are same or not 
#include<iostream>
#include<queue>

using namespace std;

struct node
{
	int data ;
	node* left;
	node* right ;
};

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

void is_same(node* root1 , node* root2)
{
	//we find the level order ttaversal for the two and check if same 
	queue<node*> s1 ;
	queue<node*>  s2;

	queue<node*> final_visited1;
	queue<node*> final_visited2;

	node* temp1 = root1;
	node* temp2 = root2;

	//push the roots to the queue 

	s1.push(temp1);
	s2.push(temp2);
	
	while(!s1.empty())
	{
		node* front1 = s1.front();
		s1.pop();

		final_visited1.push(front1);

		//now insert the children into the queue
		if(front1->left)
		{
			s1.push(front1->left);
		}
		if(front1->right)
		{
			s1.push(front1->right);
		}
	}

	while(!s2.empty())
	{
		node* front2 = s2.front();
		s2.pop();

		final_visited2.push(front1);

		//now insert the children into the queue
		if(front2->left)
		{
			s2.push(front2->left);
		}
		if(front2->right)
		{
			s2.push(front2->right);
		}
	}

	//now we pop the visited_nodes , if the tops are equal then only the tree is the same 
	while(!s1.empty() || !s2.empty())
	{
		if(s1.front() != s2.front())
		{
			cout<<"THE TREES ARE NOT THE SAME "<<endl;
			break;
		}
		else
		{
			s1.pop();
			s2.pop();
		}
		cout<<"THE TREES ARE IDENTICAL "<<endl;
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
		cout<<"ENTER THE NUMBER YOU WANT TO ENTER , PRESS -1 TO STOP TAKING THE INPUT  "<<endl;
	node* root1 = NULL;

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
			if(root1 == NULL)
			{
				//create the first node from here in the box
				node* T = new node ;
				T->data = number ;
				T->left = NULL;
				T->right = NULL;
				root1 = T;
			}
			else
			{
				insert_element(root1 , number);
			}
		}
	}

	is_same(root1 , root2);

}