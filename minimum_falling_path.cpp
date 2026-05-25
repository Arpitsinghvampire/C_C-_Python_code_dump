#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

/*Given a 2d array called matrix consisting of integer values. Return the minimum path sum that can be obtained by starting 
at any cell in the first row and ending at any cell in the last row.

Movement is allowed only to the bottom, bottom-right, or bottom-left cell of the current cell.*/

// basically start from anywhere in the topmost row and reach the lowest row with minimum cost 

vector<vector<int>> min_sum(vector<vector<int>> dp_row , int rows , int columns) // this takes in the vector of vector and the starting index of the 
{

	// here we need to choose the minimum path length for each cell 
	//we walready have the  first column for the vector ,  now we will create another path from which we get the minimum
	vector<vector<int>> s(rows , vector<int> (columns , 0));
	//now lets first write the base cases for updating the above matrix
	for(int index = 0 ; index < rows ; index++)
	{
		for(int index1 = 0 ; index1 < columns ; index1++)
		{
			if(index == 0) // now we have filled our first row 
				s[index][index1] = dp_row[index][index1];
			else if(index > 0 && index1 == 0) // you are at the first column
			{
				s[index][index1] = dp_row[index][index1] + min(s[index-1][index1] ,s[index-1][index1+1]);
			}
			else if(index>0 && index1 == columns-1) //you are at the last column
			{
				s[index][index1] = dp_row[index][index1] + min(s[index-1][index1] ,s[index-1][index1-1]); 
			}
			else //this is the general case 
			{
				int min_element = min(s[index-1][index1] ,s[index-1][index1-1]);

				s[index][index1] = dp_row[index][index1] + min(min_element , s[index-1][index1+1]);
			}


		}
	}
	//now we return our last element 
	return s; // returns the last row  for the minimum element 
}

int main()
{
	vector<vector<int>> s {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};

	vector<vector<int>> result = min_sum(s,4 ,4);

	for(int i = 0 ; i < 4;i++)
	{
		for(int j = 0 ; j<4;j++)
		{
			if(j==3)
			{
				cout<<setw(3)<<result[i][j]<<endl;
			}
			else
			{
				cout<<setw(3)<<result[i][j];
			}
		}
	}
}