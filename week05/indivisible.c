// steve Tan Z5237560
// the program reads 10 integers and prints the odd numbers on one line, then prints the even numbers on one line.  
#define max_num 1000
#include <stdio.h>
//fuction input and divi
int input ( int n, int array[n]); 
void divi (int n, int array[n]);

int main(void) {
    int array1[max_num];
    int temp = input(max_num, array1);
    divi (temp,array1);
    return 0;
}
//scanf for all values
int input ( int n, int array[n]) {
    int i = 0;
    int result = scanf("%d", &array[i]);
    i++;
    while (i < n && result == 1) {
        result = scanf("%d", &array[i]);
        i++;
    }
    i--;
    return (i); 
}
//test if it is able to divise
void divi (int n, int array[n]) {
    printf("Indivisible numbers: ");
    int m = 0;
    
    while (m < n) {
        int e = 1;
        int w = 0 ;
        while (w < n) {
            if (array[m] % array[w] == 0 && m != w ) {
                //if it is able to divise, time 0.
                e = e*0;
            } else { 
                e=e*1;
            }
            w++;
        }
        if (e == 0) {
            
        } else {
            printf("%d ", array[m]);
        }
        m++;
    }
    printf("\n");
}

