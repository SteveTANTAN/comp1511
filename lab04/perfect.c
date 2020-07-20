//steve TAN z5237560
//Date Oct. 2019
//a program for the perfect number and its divisors.

#include <stdio.h>
int main(void) {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);
    printf("The factors of %d are:\n", number);
    
    //circle the loop for the divisor.
    int i = 1;
    int sum = 0;
    while (i <= number) {
        if (number % i == 0) {
            printf("%d\n", i);
            //adding all the divisors.
            sum = sum + i;
        }
        i++;
    }
    
    printf("Sum of factors = %d\n", sum);
    //output the information.
    
    sum = sum / 2;
    if (number == sum) {
        printf("%d is a perfect number\n", number);
    } else {
        printf("%d is not a perfect number\n", number);
    }
    
    return 0;
}
