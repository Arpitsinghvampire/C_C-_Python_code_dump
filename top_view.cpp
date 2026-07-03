//top_view.cpp

//this code builds on the fact of the vertical order traversal 
//earlier we were appending the elements into the column  , but here the only catch is that each column wiuld have 
//only one element and tgen we wont push the other element 


#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>

using namespace std;

//here we will define the x and the y coordinate for each node
struct node
{
    int data;
    node* left;
    node* right;

    int x_coordinate;
    int y_coordinate;
};

//first we will assign coordinates to all the nodes
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
        vertical_nodes[front1->x_coordinate]
                      [front1->y_coordinate]
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

    cout << "\nVERTICAL ORDER TRAVERSAL\n";

    for(auto &column : vertical_nodes) //print only the first element of each column
    {
        cout << "Column " << column.first << " : ";

        for(auto &level : column.second)
        {
            cout<< *level.second.begin()<<endl; //begin returns the iterator hence we need to dereference it thats why we put the stat
            //also the first element of the level is the y coordinate , we need the set , which is the second coordinate 
            //thats why we put the level.second
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

    assign_coordinates(root);

    return 0;
}
