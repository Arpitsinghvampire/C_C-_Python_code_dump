//serialize_deserialize.cpp

//in this code , we have to transform the root to such a string which when dereialized will return us the original tree
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;

	node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

string serialized_tree(node* root)
{
	if(!root)
	{
		return "";
	}
	//given the root we have to transform into the string , here we will choose the level order traversal 
	queue<node*> s1;
	queue<char> s2; //this stores the  # in case of no children 

	string resultant= "";

	s1.push(root);
		while(!s1.empty())
		{
			//the only thing is that in order to differentiate for the children we will add # in the case when there is no child
			node* front1 = s1.front();
			if(front1)
			resultant += to_string(front1->data) + ',';
			else
				resultant += '#';
			s1.pop();

			
			if(front1)
			{
				s1.push(front1->left);
				s1.push(front1->right);
			}


		}
	return resultant;

}

void deserialized_tree(string s1)
{
	//here we would be given a tring of level order traversal , we need to create the original tree 
	queue<node*> q;

	if(s1.empty())
		cout<<"THE TREE IS EMPTY "<<endl;

	string str;
	getline(s1,str,',');

	node* T = new node(stoi(str));

	q.push(T);

	while(!q.empty())
	{
		node* front1 = q.front();
		q.pop();

		// now we need to create the links to the above data 
		getline(s1,str,',');
		if(str == '#')
		{
			front1->left = NULL
		}
		else
		{
			node* T1 = new node(stoi(str));

			front1->left = T1;

			q.push(T1);
		}

		getline(s1,str,',')

		if(str == '#')
		{
			front1->right = NULL;
		}
		else
		{
			node* T1 = new node(stoi(str));

			front1->right = T1;
			q.push(T1);
		}
	}







}