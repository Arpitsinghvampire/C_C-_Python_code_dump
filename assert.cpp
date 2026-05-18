#include<iostream>
#include<cassert>
auto find_max(const std:: array<double , 5> & numbers)  //this is the pass by reference 
{
   auto max = numbers[0];
   for (int i = 0 ;i<5 ;++i)
   {
    if(max<=numbers[i])
    {
       max = numbers[i];
    }
    
   }
    std :: cout<< max <<std :: endl;
}

int main()
{
    std:: array<double  , 5> numeric {1 , 2, 3 ,45 , 56};
    std :: cout<< numeric[0]<<std::endl; 

    find_max(numeric);

 std:: cout<<"this is the main programme" ;
}