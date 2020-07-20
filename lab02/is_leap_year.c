//Date Sept. 2019
//steve TAN Z5237560
#include<stdio.h>
int main(void) {
    int yearNumber;
    printf("Enter year:\t");
    scanf("%d", &yearNumber);
    //input the year number
    
    if ((yearNumber % 100 !=0 && yearNumber %4 == 0) || yearNumber % 400 == 0) {
        printf("%d is a leap year.\n", yearNumber);
    }   
    
    //calculate if it is a leap year.
    else {
        printf("%d is not a leap year.\n", yearNumber);
    }
    
    return 0;
}
