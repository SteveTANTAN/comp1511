// Steve TAN z5237560
// Date Oct. 2019
// the program reads 3 integers and prints them from smallest to largest. 
#include <stdio.h>
int main(void) {
    int number_1, number_2, number_3, maxnum, mininum, middle ;
    
    //input the variables.
    printf("Enter integer: ");    
    scanf("%d", &number_1);
    printf("Enter integer: ");    
    scanf("%d", &number_2);
    printf("Enter integer: ");    
    scanf("%d", &number_3);
    //calculate for the max, middle and mini number.
    mininum = number_1 * (number_1 <= number_2 && number_1 <= number_3) 
    + number_2 * (number_2 < number_1 && number_2 <= number_3)
     + number_3 * (number_3 < number_1 && number_3 < number_2);
  
   
    maxnum = number_1 * (number_1 >= number_2 && number_1 >= number_3 )
     + number_2 * (number_2 > number_1 && number_2 >= number_3) 
     + number_3 * (number_3 > number_1 && number_3 > number_2);
     
     
    middle = number_1 + number_2 + number_3 - mininum - maxnum; 
   
    
    
    printf("The integers in order are: %d %d %d\n", mininum, middle, maxnum);
    return 0;
}
