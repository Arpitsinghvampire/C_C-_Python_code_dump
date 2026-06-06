//minimum_insertion_deletion.cpp

//in this problem statement we are given two strings we have to find the minimum number of insertion or deletion to convert one string into another 
//basic thought process is to find the maximum common subsequence and then add the length not equla in both so we would need to add them 
#include<iostream>
#include<vector>

using namespace std;

void find_subsequences(string s , int index , string current_sequence , vector<string> &subsequence_vector)
{
	if(index == s.size())
	{
		subsequence_vector.push_back(current_sequence);
		return ;
	}
	else
	{
		//either add your index to the current sequence or not 
		find_subsequences(s , index + 1 ,current_sequence+s[index] , subsequence_vector);
		//or you dont
		find_subsequences(s , index +1 , current_sequence , subsequence_vector);
	}
}

//now find the maximum possible commonality between the two subsequences and then add the length which is not common to them 
//now we find the max length common subsequence and hence the 
void find_min_operations(vector<string> sub_seq1 , vector<string> sub_seq2 , string s1 , string s2)
{
	int min_operations = INT_MAX;
	int required_index = 0;
	for(int index = 0 ; index < sub_seq1.size() ; index++)
	{
		for(int index1 = 0 ; index1 < sub_seq2.size() ; index1++)
		{
			if(sub_seq1[index] == sub_seq2[index1])
			{
				if (min_operations > s1.size()-sub_seq1[index].size() + s2.size() - sub_seq2[index1].size())
				{
					min_operations = s1.size()-sub_seq1[index].size() + s2.size() - sub_seq2[index1].size();
					required_index = index;
				}
			}
		}
	}

	cout<<"THE MINIMUM NUMBER OF INSERTIONS /DELETIONS NEEDED ARE  :: "<<min_operations<<endl ;
	cout<<"THE REQUIRED MAX COMMON SUBARRAY IS GIVEN AS "<<sub_seq1[required_index]<<endl;
}

int main()
{
	string s1 = "iamgroot";
	string s2 = "iamarpitsingh";

	vector<string> result1 ;
	vector<string> result2 ;

	find_subsequences(s1 , 0 , "" , result1);
	find_subsequences(s2 , 0 , "" , result2);


	find_min_operations(result1 , result2 , s1 , s2);

}