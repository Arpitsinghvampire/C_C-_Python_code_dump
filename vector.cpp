#include<iostream>
#include<vector>
void vector_insert()
{
    std :: vector<int> numbers {0,1};

    //now lets insert into the vector 
    numbers.insert(numbers.begin() , -123); //insert in the vector at a given position 

    //now lets push back the element 
    numbers.push_back(- 123);

    for(auto const number1 : numbers)
    {
        (std:: cout<< number1) << std:: endl ;
    }

}


int main()
{

 std :: vector<int> numbers {0,1,2,3,4,5};
 //this prints all  numbers in the element 
 for(const auto number : numbers)
 {
    (std:: cout<< number) << std:: endl ;
 }
 //push_back element 
 numbers.push_back(-123);

 for(const auto number1 : numbers)
 {
    (std:: cout<<number1) << std:: endl ;
 }
//now lets insert the values 
  std:: cout<< "THis is the vector function "<<std ::endl;
  
   vector_insert();
}