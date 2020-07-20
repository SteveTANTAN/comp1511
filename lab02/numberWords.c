//Date Sept. 2019
//steve TAN z5237560
#include<stdio.h>

int main(void){
    int number;
    printf("Please enter an integer:\t");
    scanf("%d", &number);
    
    if (number < 1) {
        printf("You entered a number less than one.\n");
    }
    
    else {    
    
        if (number > 5) {
            printf("You entered a number greater than five.\n");
    }
    //test for the integer which is greater or less than five.
        else {
            if (number == 1) {
                printf("You entered one.\n");
            }
            if (number == 2) {
                printf("You entered two.\n");
            }
            if (number == 3) {
                printf("You entered three.\n");
            }
            if (number == 4) {
                printf("You entered four.\n");
            }
            if (number == 5) {
                printf("You entered five.\n");
    }
    
    //transform the number to the word formation.
    
    }
    }
    return 0;
}
