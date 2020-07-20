//z5237560 steve TAN
//Date 29/10/2019 
#include <stdio.h>
#define max_size 10000
//the fuction used for getting the maximum value
int maxvalue (int array[], int n);
//to scanf value
int input ( int n, int array[n]);
//to find out the missing value.
void the_missing(int max, int num, int array[num]);
int main(void) {
    int array[max_size];
    int temp = 0;
    temp = input(max_size, array);

   
    int maxnum = maxvalue (array, temp);
    
    the_missing(maxnum, temp, array);
   
    
    

    return 0;
}
//find out the missing value
void the_missing(int max, int num, int array[num]) {
    int temp = 1;
    int i = 0;
    int result = 1;
    while (temp < max) {
        i = 0;
        result = 1; 
        while (i < num) { 
            
             
            if (array[i] == temp) {
                result = result * 0;
            } else {
                result = result * 1;
            }
            i++;
        }
   
        if (result == 1) {
            printf("%d ", temp);   
        }
        temp++;    
    }
    printf("\n");

}
//input value
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



int maxvalue (int array[], int n) {
    int temp; 
    int i = 0;
    while (i < n) {
        if (array[i] >= array[0]) {
            temp = array[i];
            array[i] = array[0];
            array[0] = temp;
        }
        i ++;
    }
    return array [0];
}
