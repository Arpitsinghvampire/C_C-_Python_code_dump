//minimum_time_taken_to_burn.cpp

//here we would be given a node , from that nodes , we would need to find the minimum time taken to  burn the tree 
#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

struct node
{
	int data ;
	node* left;
	node* right;
};



void minimum_time_taken(node* root , int number ,int distance_k)
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
	while(!s1.empty())
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

		if(!front1->left)
		{
			break;
		}
		

		if(front1->right)
		{
			if(find(visited_array.begin() , visited_array.end() , front1->right) == visited.end())
			s1.push(front1->right);
		}
		
		if(!front1->right)
		{
			break;
		}
		//we then push the parent 
		if(parent_dict[front1] && find(visited_array.begin() , visited_array.end() , parent_dict[front1]) == visited.end() )
		s1.push(parent_dict[front1]);

		distance ++ ;
	}

	cout<<"THE MINIMUM TIME TAKEN TO BURN THE TREE IS "<< distance<<endl;

}

int main()
{

}