//steve Tan z5237560
//Date OCT. 2019
//a function to find sum.
#include <stdio.h>
int main(void) {
    //enter the size
    int row = 1, clo = 1, size;
    printf("Enter size: ");
    scanf("%d", &size);
    while (row <= size) {
        while (clo <= size) {
            //paint for the one row
            if (clo == 1 || clo == row || row == size) {
                printf("*"); 
            } else {
                printf(" ");
            }
            
            clo++;
        }
        //repeat for the next one
        printf("\n");
        clo = 1;
        row++;   
    }     
    return 0;
}
