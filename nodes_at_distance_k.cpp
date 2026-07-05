//nodes_at_distance_k.cpp

//here in this code we want to find the nodes at a distance k from a particular node 
#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};


void nodes_at_distance_k(node* root , int number ,int distance_k)
{
	//as we traverse the node , we try to  store the parent node also so that we can traverse backwards 
	map<node* , node*> parent_dict ; //the first node is the current node and the second part is the parent node 
	node* temp = root;
	//we traverse each node , and then record the parents 
	queue<node*> s1;
	s1.push(root);

	node* reference_node = NULL;

	while(!s1.empty())
	{
		node* front1 = s1.front();
		if(front1->data == number)
		{
			reference_node = front1;
		}
		s1.pop();

		if(front1->left)
		{
			s1.push(front1->left);

			if(front1->left->data == number)
			{
			  reference_node = front1->left;
			}
			parent_dict[front1->left] = front1;
		}
		if(front1->right)
		{
			s1.push(front1->right);

			if(front1->right->data == number)
			{
				reference_node = front1->right;
			}
			parent_dict[front1->right] = front1;
		}
	}

	//after this step we will have the reference_node and the  parent node , which we can traverse back 
	//we have to find the node at a distance k 
	//first we travel backwards and the other forwards
	vector<node*> visited_array;

	queue<node*> s1 ;

	s1.push(reference_node);
	int distance = 0;

	//we first find the elements at a distance of one 
	while(distance!= distance_k)
	{
		//push the children and the parent 
		node* front1 = s1.front();

		s1.pop();
		visited_array.push_back(front1);

		if(front1->left)
		{
			if(find(visited_array.begin() , visited_array.end() , front1->left) == visited.end())
			s1.push(front1->left);
		}
		

		if(front1->right)
		{
			if(find(visited_array.begin() , visited_array.end() , front1->right) == visited.end())
			s1.push(front1->right);
		}
		

		//we then push the parent 
		if(parent_dict[front1] && find(visited_array.begin() , visited_array.end() , parent_dict[front1]) == visited.end())
		s1.push(parent_dict[front1]);

		distance ++ ;
	}

	cout<<"ELEMENTS AT THE K DISTANCE FROM THE REFERENCE NODE IS "<<endl;
	//after this we return the resultant elements 
	while(!s1.empty())
	{
		cout<<s1.front()<<endl;
		s1.pop();
	}

}

int main()
{

}
