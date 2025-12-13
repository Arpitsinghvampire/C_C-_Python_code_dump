#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum months {
        JAN = 1, FEB , MARCH , APRIL , MAY , JUNE , JULY , AUGUST , SEPTEMBER , 
        OCTOBER , NOVEMBER , DECEMBER
    };


int main()
{
    const char* monthname[] = {"JAN" , "FEB" , "MARCH" , "APRIL" , "MAY" , "JUNE" , 
    "JULY" , "AUGUST" , "SEPTEMBER" , "OCTOBER" , "NOVEMBER" , "DECEMBER"};

  for (enum months month = JAN; month <= DECEMBER; month++)
    printf("%2d  %-11s\n", month, monthname[month-1]);

}



