#include <stdio.h>
int main (void) {
    int ch;
    ch = getchar();
    while (ch != EOF) {
        printf("%d\n", ch);
        ch = getchar();
    
    }


    return 0;
}
