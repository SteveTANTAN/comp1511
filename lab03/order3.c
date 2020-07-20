//z5237560
//steve TAN 
//Date Oct. 2019

#include <stdio.h>

int main(void) {
    int number_1, number_2, number_3, z;
    
    printf("Enter integer: ");
    scanf("%d", &number_1);
    printf("Enter integer: ");
    scanf("%d", &number_2);
    printf("Enter integer: ");
    scanf("%d", &number_3);
    
    //input all the information we need.    
    // exchange number_1 and number_2, make sure number_1 < number_2.    
    if (number_1 > number_2) {
        z = number_1;
        number_1 = number_2;
        number_2 = z;
    } 
    // exchange number_1 and number_3, make sure number_1 < number_3.      
    if (number_1 > number_3) {
        z = number_1;
        number_1 = number_3;
        number_3 = z;
    } 
    // exchange number_2 and number_3, make sure number_2 < number_3.     
    if (number_2 > number_3) {
        z = number_2;
        number_2 = number_3;
        number_3 = z;
    }  

    printf("The integers in order are: %d %d %d\n", number_1, number_2, number_3); 
   
    
    
    return 0;
}
