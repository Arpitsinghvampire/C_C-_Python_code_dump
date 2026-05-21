#include<iostream>
using namespace std;

int nth_root_iterative_method(int n, int m)
{   
    int potential_answer = 0 ;
    for(int number = 1; number <= m; number++)
    {
        long long power = 1;

        // calculate number^n
        for(int count = 0; count < n; count++)
        {
            power *= number;
        }

        if(power == m)
        {
            return number;
        }

        else if(power > m)
        {
            break;
        }

        else
        {
            potential_answer = number ;
        }

    }

    return potential_answer;
}

int nth_root_optimized_method(int n , int m )
{
    // we use the similar approach of binaary search algorithm like we used in the previous programme 
    int low = 0 ;
    int high = m;

    while(low<=high)
        {
            // we need to check the nth power of the above value
            int power =1 ;
            int count = 0 ;
            while(count < n)
            {
                power *= (low+high)/2 ; // power of the mid 
                count ++ ;
            }
            if(power == m)
            {
                return (low+high)/2 ;
            }
            else if(power>m)
            {
                // if the power is greater than  m , , we would need to reduce it by moving toward the first half of the vector 
                high = (low+high)/2 -1 ;
            }

            else // this case arises when the power is less than m , so we would need to move towards the right hand side 
            {
                low = (low+high)/2+1;
            }
        }

        // if we still do not get the result , we return -1 
        return high;
}

int main()
{
    int n, m;

    cout << "ENTER THE VALUE OF N (nth root): ";
    cin >> n;

    cout << "ENTER THE VALUE OF M: ";
    cin >> m;

    int result = nth_root_iterative_method(n, m);

    
        cout << "The nth root of " << m << " is " << result << endl;

   int result_optimized = nth_root_optimized_method(n , m);

   cout<< result_optimized <<endl;

    return 0;
}