//word_ladder_2.cpp

//in this code block we would be given a word list like the one we were given previously , we want to find all the possible sequences to get to the target strinf 
#include<iostream>
#include<queue>
#include<utility>
#include<vector>

using namespace std;

vector<string> get_neighbours(vector<string> vocab_list , string  current_word)
{
	//the words in the vocab list are all the same lenght
	vector<string> result ;
	for(int index = 0 ; index < vocab_list.size() ; index++)
	{
		int difference = 0 ;
		for(int index1 = 0 ;index1 < current_word.size() ; index1++)
		{
			if(current_word[index1] != vocab_list[index][index1])
			{
				difference++;
			}
		}
		if(difference == 1)
		{
			result.push_back(vocab_list[index]);
		}
	}
	return result;
}

void eligible_patterns(vector<string> vocab_list , string current_word , string final_word)
{
	//here we will use the queue data structure 
	queue<vector<string>> s1;
	map<string , bool> visited ;

	//we then push the current_word into the queue
	vector<string> initial_vector = {current_word};
	s1.push(initial_vector);
	visited[current_word] = true;

	while(!s1.empty())
	{
		//find the front node , then get the last element of that list  , and then append the further neighbours into it 
		vector<string> top_string = s1.front();
		//get the last element of the string 
		string last_element = top_string.back();
		//after getting the last element check for its neighbours 
		if(last_element != final_word)
			s1.pop();
		if(last_element == final_word)
		{
			cout<<"POSSIBLE SEQUENCE "<< endl;
			//then we need to print the list and then pop the element
			for(string x: top_string)
			{
				cout<< x<<endl;
			}

			cout<<endl;
		}

		vector<string> neighbours = get_neighbours(vocab_list , last_element);

		for(int index = 0 ; index < neighbours.size() ; index++)
		{
			if(!visited[neighbours[index]])
			{
				//then create a new copy of the string
				vector<string> new_copy(top_string);
				new_copy.push_back(neighbours[index]);
				s1.push(new_copy);
			}
		}
	}

}