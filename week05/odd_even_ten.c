// steve Tan Z5237560
// the program reads 10 integers and prints the odd numbers on one line, then prints the even numbers on one line.  
#define max_num 10
#include <stdio.h>

void input ( int n, int array[n]); 
void outodd (int n, int array[n]);
void outeven (int n, int array[n]);

int main(void) {
    int array1 [max_num]= {0};
    input(max_num, array1);
    outodd(max_num,array1);
    outeven(max_num,array1);
    return 0;
}

void input ( int n, int array[n]) {
    int i = 0;
    while (i < n) {
        scanf("%d", &array[i]);
        i++;
    }
}

void outodd (int n, int array[n]) {
    int i = 0;
    printf("Odd numbers were: ");
    while (i<n) {
        if ((array[i] % 2) != 0 ) {
            printf("%d ", array[i]);
        } else {
        }
    i++;
    }
    printf("\n");
}


void outeven (int n, int array[n]) {
    int i = 0;
    printf("Even numbers were: ");
    while (i<n) {
        if ((array[i] % 2) == 0 ) {
            printf("%d ", array[i]);
        } else {
        }
    i++;
    }
    printf("\n");
}

