//Date: Sept. 2019
//steve TAN z5237560
#include<stdio.h>
int main(void) {
    int number1, number2, sum;
    printf("Please enter two integers:\t");
    scanf("%d %d", &number1, &number2);
    //input the two integers.
    
    sum = number1 + number2;
    printf("%d + %d = %d\n", number1, number2, sum);
    //calculate and output.
    
    return 0;
}
