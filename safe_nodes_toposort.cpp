//safe_nodes_toposort.cpp

//we want to know all the nodes which are safe nodes , that is all paths lead to a node , which has no outgoing edges .
#include<iostream>
#include<queue>
#include<stack>
#include<vector>

using namespace std;

// so basically if we  find a cycle in the directed graph and also find the nodes connected to those elements of the cycle in the graph 
//then we can say that that node is not a safe node 

//basically first we want to find the nodes present in a cycle 

//approach -> we first reverse the graph ,  that is reverse all the edges in the graph , and then apply the topological sort  , we would get the safe nodes 
//we then need to sort the vector , so to put the elements in the increasing order 
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the temporary arrays back
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function
void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

vector<vector<int>> reverse_graph(vector<vector<int>> adj)
{
	vector<vector<int>> reverse(adj.size() , {});

	for(int index = 0 ; index< adj.size() ; index++)
	{
		for(int index1 = 0 ; index1 < adj[index].size() ; index1++)
		{
			reverse[adj[index][index1]].push_back(index);
		}
	}
	return reverse;
}
//after getting the reverse array , we need to find the topological sort 
void kahns_algorithm(vector<vector<int>> adj)
{
	//now we push into the stack the elements with the indegree 0 ;

	queue<int> s1;
	
	vector<int> indegree_node = get_indegree(adj);

	vector<bool> into_stack(adj.size() , false) ;
	//now lets look into the nodes which have indegree 0 
	for(int index = 0 ; index < adj.size() ; index++)
	{
		if(indegree_node[index] == 0)
		{
			s1.push(index);
			into_stack[index] = true;
		}
	}

	//after this we will get all the nodes which have indegree of 0 into the stack 
	vector<int> answer ;

	while(!s1.empty())
	{
		//we would need to get the connections to the node , and then subtract the indegrees of the corresponding node by 1 
		int front_node = s1.front();
		answer.push_back(front_node);
		s1.pop();

		//now subtract all the edges from that node 
		for(int index = 0 ; index < adj[front_node].size() ; index++)
		{
				indegree_node[adj[front_node][index]] --;

				if(indegree_node[adj[front_node][index]] == 0 && !into_stack[adj[front_node][index]])
				{
					into_stack[adj[front_node][index]]= true;
					s1.push(adj[front_node][index]);
				}
		}

	}
	// we then need to sort the vector since the question needs the nodes in the sorted order 
	mergeSort(answer , 0 , answer.size()-1);
	//now i think we just need to return the vector and all our work is done 

	return answer;

}