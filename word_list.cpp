//word_list.cpp

//here in this question we would be given a intiital word and we would want to get the final word , in what minimum way can we get the target word 
#include<iostream>
#include<queue>
#include<utility>
#include<string>
#include<map>
#include<vector>

using namespace std;

vector<string> neighbours(vector<string> vocabulary_list , string current_word )
{
	vector<string> final_result ;
	vector<int> result ;
	for(int index = 0 ; index < vocabulary_list.size() ; index++)
	{
		if(vocabulary_list[index] == current_word)
		{
			result.push_back(-1);
		}
		else
		{
			int difference = 0 ;
			for(int index1 = 0 ; index1 < current_word.size(); index1++)
			{
				if(current_word[index1] != vocabulary_list[index][index1])
				{
					difference++;
				}
			}
			result.push_back(difference);

		}
	}
	for(int index = 0 ; index < vocabulary_list.size() ; index++)
	{
		if(result[index] == 1)
		{
			final_result.push_back(vocabulary_list[index]);
		}
	}
	return final_result; //this returns all the nodes to which the current distance is 1 ;
}

int minimum_length(vector<string> vocabulary_list , string initial_word , string final_word)
{
	queue<pair<string ,int>> d1;
	d1.push({initial_word , 1});

	map<string , bool> visited;
	for(int index = 0 ; index < vocabulary_list.size() ; index++)
	{
		visited[vocabulary_list[index]] = false;
	}

	//if the initial word is in thte vocab list , marks it as visited 
	visited[initial_word] = true;
	//now we push the neighbours into the  string 

	while(!d1.empty())
	{
		pair<string ,int > front_node = d1.front();
		d1.pop();
		

		string current_word = front_node.first;
		int current_level = front_node.second;

		if(current_word == final_word)
		{
			return current_level-1;
			
		}
		//now we need to get the neighbours of that strinf 
		vector<string> neighbours1 = neighbours(vocabulary_list ,current_word );

		for(int index1 = 0 ; index1 < neighbours1.size() ; index1++)
		{
			if(!visited[neighbours1[index1]])
			{
				//then we visit them
				visited[neighbours1[index1]] = true;
				d1.push({neighbours1[index1] , current_level+1});

			}
		}
	}
	//if we still do not return inside the loop that the means the word is not reachable , hence we return 0 ;
	return  0;


}