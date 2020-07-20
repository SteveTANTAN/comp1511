//steve Tan z5237560
//Date OCT. 2019
//a function to find sum.
#include <stdio.h>
int main(void) {
    int numbers;
    // looping times
    printf("How many numbers: ");
    scanf("%d", &numbers);
    
    //input and calculate the sum
    int i = 1, temp;
    int sum = 0;
    while (i <= numbers) {
        scanf("%d", &temp);
        sum = sum + temp;
        i++;
    }
    
    
    printf("The sum is: %d\n", sum);
    return 0;
}
