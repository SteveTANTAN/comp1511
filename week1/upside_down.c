//Steve Tan z5237560
//Date Oct. 2019
//weekly test 03 indicate whether they are strictly increasing, decreasing or neither.
#include <stdio.h>
int main(void) {
    double number_1, number_2, number_3;
    
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &number_1, &number_2, &number_3);
    
    //for the increasing
    if (number_1 < number_2 && number_2 < number_3) {
        printf("up\n");
    
    } else {
        
        //for the decreasing.
        if (number_1 > number_2 && number_2 > number_3) {
            printf("down\n"); 
        } else {
            printf("neither\n");
        }
    }
    return 0;
}    
         
