//steve Tan z5237560
//Date OCT. 2019
#include <stdio.h>
int main(void) {
    
    int first, second, third;
    printf("Enter integer: ");
    scanf("%d", &first);
    printf("Enter integer: ");
    scanf("%d", &second);
    printf("Enter integer: ");
    scanf("%d", &third);
    
    
    //find the max and mini value.
    int max, mini, middle;
    if (first >= second) {
        mini = second;
        max = first;
    } else {
        mini = first;
        max = second;
    }
    
    if (max >= third) {
        
    } else {
        max = third;
    }
    
    if (mini <= third) {
    } else {
        mini = third;
    }
    
    //find the middle value.    
    middle = first + second + third -max-mini; 
    //printf 
    printf("Middle: %d\n", middle);
    return 0;
}

