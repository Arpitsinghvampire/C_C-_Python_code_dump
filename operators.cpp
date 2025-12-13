#include<stdio.h>
#include<ctype.h>

int main()
{
    /*
     int a;
    int b;
    int c;
    int d;
    int e ;
    int f;
    int g;
    puts("ENTER THE NUMBER YOU WANT ");
    scanf("%d%i%i%i%o%u%x" , &a , &b, &c , &d ,&e , &f , &g);

    puts("THE INPUT DISPLAYED ON THE SCREEN IS ");
    printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, f, g);
*/
    int month =0;
    int day = 0;
    int year = 0 ;
    printf("ENTER THE DAY MONTH AND YEAR ");
    scanf("%d*c%d*c%d" , &month , &day , &year);
    printf("THE MONTH IS %d , the day is %d , and the year is %d" , month , day , year);
     printf("\n");
    printf("enter the 6 digit number");
    int x,y;
    //The first two numbers are 

    scanf("%2d%d" , &x , &y); //this will take first two digits and fir the nunbers into x and fir tteh reemianing numbers into y 
     
     printf("THE FIRST TWO NUMBERS ARE %d and the remaining number is %d" , x , y);



}
