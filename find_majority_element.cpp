//in this code , we have to find the element whose count is at least or greater than the n/3 where n is the number of elements
#include<iostream>
#include<vector>

using namespace std;

vector<int> majority_element(vector<int> vector_result)
{
	//there can be atmost two elements witht  the number of elements greater than or equal to n/3
	int majority_element1 = 0 ;
	int count_1 = 0 ;

	int majority_element2 = 0;
	int count_2 = 0;

	for(int index = 0 ; index < vector_result.size() ; index++)
	{
		//first check if the majority_element1 is set or not 
		if(majority_element1 == vector_result[index])
		{
			//then set the majority_element1
			count_1++;
		}
		//now if the majority_element1 is set ,and we recieve another number , we then check if the majority_element2 is set or not 
		else if(majority_element2 == vector_result[index])
		{
			count2 ++;
		}

		//now if the above two cases are not matching , then we have recieved another number 
		else if(count_1 == 0)
			{
				//then update the elements
				majority_element1 = vector_result[index];
				count_1 =1 ;
			}

		else if(count_2 == 0)
		{
			majority_element2 = vector_result[index];
			count_2 = 1;
		}

		else
		{
			count_1 --;
			count_2 -- ;
		}
		
	}
	return {majority_element1 , majority_element2};

}