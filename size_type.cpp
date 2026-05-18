#include<iostream>
#include<vector>
using namespace std;

bool ispresent(int number , vector<int> v2)
{
   bool flag = false;
   vector<int>::iterator iter_vec = v2.begin();
   while(iter_vec!= v2.end())
   {
     if(*iter_vec==number)
       {
        flag = true;
        return flag;
       }

    ++iter_vec;
   }
   return flag ;
}

vector<int> printvalues(const int ia[], size_t size) //this passes the array in the integer type 
{
  size_t i =0;
  vector<int> v1 ; //this initializes the 
  for(/* null */; i!=size ; i++) // here we already have initialized the variable , so we dont reinitialize
  {
      //lets see if the vecotr v1 is available in the vector or not 
      if(!ispresent(ia[i] , v1))
      {
      // if the number is not present in the vector  , then you need to pushback the value in the vector 
        v1.push_back(ia[i]);
      }
  }

  return v1;
}

int main()
{
    const int ia[]= {1 , 2, 3 , 2 , 2, 5 , 6 , 7 };

    vector<int> v3 = printvalues(ia , sizeof(ia)/sizeof(ia[0]));
   //this will give the vecotr v3 in the return type , where vector v3 still contains all the unique numbers 
   vector<int>::iterator iter_v3 = v3.begin();

   cout<<"THE UNIQUE ELEMENTS OF THE ARRAY ARE ";
   while(iter_v3!=v3.end())
   {
    cout<<*iter_v3;
    ++iter_v3;
   }
    
}
