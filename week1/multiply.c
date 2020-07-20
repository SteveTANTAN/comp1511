//Steve Tan z5237560
//Date Oct. 2019
//weekly test the absolute Multiple of two integers
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    //input the variables
    int number_1, number_2, absproduct, product;
    scanf("%d %d", &number_1, &number_2);
    product = number_1 * number_2;
    
    absproduct = abs(product);
    //transfer to absolute value. 
    if (absproduct == 0) {
        printf("zero\n");   
    } else {
        printf("%d\n", absproduct);
    }
    return 0;
}
