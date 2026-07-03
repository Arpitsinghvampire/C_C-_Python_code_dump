//right_side.cpp
//here we have to print the right side /left side view of the tree
//this is basically the level order traversal part 
#include<iostream>
#include<queue>
#include<map>
#include<utility>

using namespace std;

struct node
{
	int data ;
	node* left;
	node* right;
};

void assign_coordinates(node* root)
{
    //if the tree is empty
    if(root == NULL)
    {
        return;
    }

    node* temp = root;

    //assign the coordinates of the root node
    temp->x_coordinate = 0;
    temp->y_coordinate = 0;

    //we can start with the level order traversal
    queue<node*> s1;

    //push the root node
    s1.push(temp);

    //this map stores
    //x coordinate -> y coordinate -> sorted values
    map<int, map<int, multiset<int>>> vertical_nodes;

    while(!s1.empty())
    {
        //find the front node
        node* front1 = s1.front();
        s1.pop();

        //insert the node into the corresponding coordinate
        vertical_nodes[front1->y_coordinate]
                      [front1->x_coordinate]
                      .insert(front1->data);

        //we then need to insert the left and the right node

        if(front1->left)
        {
            s1.push(front1->left);

            front1->left->x_coordinate =
                front1->x_coordinate - 1;

            front1->left->y_coordinate =
                front1->y_coordinate + 1;
        }

        if(front1->right)
        {
            s1.push(front1->right);

            front1->right->x_coordinate =
                front1->x_coordinate + 1;

            front1->right->y_coordinate =
                front1->y_coordinate + 1;
        }
    }

    //with this we have assigned the coordinates to all the nodes
    //now print the vertical order traversal

    cout << "\nHORIZONTAL ORDER TRAVERSAL\n";

    for(auto &row : vertical_nodes) //print only the first element of each column
    {
        cout << "Row " << row.first << " : ";

        for(auto &level : column.second)
        {
            cout<< *level.second.rbegin()<<endl;
        }

        cout << endl;
    }
}
void insert_element(node* root , int number)
{
    node* temp = root;

    while(temp)
    {
        if(number > temp->data && temp->right != NULL)
        {
            temp = temp->right;
        }

        else if(number <= temp->data && temp->left != NULL)
        {
            temp = temp->left;
        }

        else
        {
            node* T = new node;

            T->data = number;
            T->left = NULL;
            T->right = NULL;

            //initialize the coordinates
            T->x_coordinate = 0;
            T->y_coordinate = 0;

            if(number > temp->data)
            {
                //insert in the right hand side
                temp->right = T;
            }

            else
            {
                //insert in the left hand side
                temp->left = T;
            }

            break;
        }
    }
}


int main()
{
	cout<<"Enter the numbers, press -1 to stop taking input"<<endl;

    node* root = NULL;

    while(true)
    {
        int number;
        cin >> number;

        if(number == -1)
        {
            break;
        }

        if(root == NULL)
        {
            //create the first node

            node* T = new node;

            T->data = number;
            T->left = NULL;
            T->right = NULL;

            //initialize coordinates
            T->x_coordinate = 0;
            T->y_coordinate = 0;

            root = T;
        }

        else
        {
            insert_element(root, number);
        }
    }
}