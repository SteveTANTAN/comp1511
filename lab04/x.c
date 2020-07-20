//steve TAN z5237560
//Date OCT. 2019
//photo shows X shape
#include <stdio.h>
int main(void) {

    int row = 1, clo = 1, size;
    printf("Enter size: ");
    scanf("%d", &size);
    while (row <= size) {
        while (clo <= size) {
            //printf for one line.       
            if (row == clo || clo == (size - row +1)  ) {
            
                printf("*");
            
            } else {
                printf("-");
            }
            
            clo ++; 
        }
        
        //for next line
        printf("\n");
        clo = 1;
        row ++;
    }
    return 0;
} 
