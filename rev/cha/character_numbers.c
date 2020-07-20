#include <stdio.h>
int main(void) {
    int count = 32;
    while (count <= 126) {
        printf("%3d 0x%x %c\n", count, count, count);

        count++;
    }
    return 0;
}
