//accounts_merge.cpp

//here we would be given a username , and a set of accounts , we need to merge all the accounts belonging to the same person 
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
using namespace std;

//first we need to map list of strings to a name 
vector<vector<string>> main_function(vector<vector<string>> string_list)
{
	//we will initially give them a parent 
	vector<int> parent_list;
	for(int index = 0 ; index<string_list.size() ; index++)
	{
		parent_list.push_back(index);
	}

	map<string , int> parent_dict1;
	map<int , string> dict1;
	for(int index = 0 ; index < string_list.size() ; index++)
	{
		dict1[index] = string_list[index][0]; //maps the name 
	}
	//this maps position to name 

	for(int index = 0 ; index < string_list.size() ; index++)
	{
		for(int index1 = 1 ; index1 < string_list[index].size() ; index1++)
		{
			if(parent_dict1[list_string[index][index1]])
			{
				//that means the entry exists already , then we need to write the parent of the parent lsit as the earlier one 
				parent_list[index] = parent_dict1[list_string[index][index1]];
			}

			else
			{
				parent_dict1[list_string[index][index1]] = index;
			}
		}
	}

    
	//this maps email to position 

	//now we need to create a union function 

	//we now need to merge the elements to the true parents 
	//now lets reconstruct the emails 
	vector<set<string , greater<string>>> reconstructed_part(string_list.size() , {});
	for(int index = 0 ; index < string_list.size() ; index++)
	{
		//insert only the emails first 
		//then append the elements in the same order 
		for(int index1 = 1; index1 < string_list[index].size() ; index1++)
		{
			reconstructed_part[parent_list[index]].push_back(string_list[index][index1]);
		}
	}
	//this will give the emails in the corrected sorted position  , now we need to ad dthe name 
	//first we need to typecast them into vectors 
	

// conversion
		vector<vector<string>> result;
int current_index = 0 ;
for(auto &st : reconstructed_part)
{
    vector<string> temp(st.begin(), st.end());  // set -> vector

    temp.push_back(dict1[parent_list[current_index]]);              // add element at back

    reverse(temp.begin(), temp.end());          // reverse this vector

    result.push_back(temp);
}

return result 

}
