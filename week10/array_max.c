// Find the maximum value in an array.

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 1000

int array_max(int size, int array[size]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    int array[MAX_SIZE];

    // Get the array size.
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    assert(size > 0);

    // Scan in values for the array.
    printf("Enter array values: ");
    int i = 0;
    while (i < size) {
        assert(scanf("%d", &array[i]) == 1);
        i = i + 1;
    }

    printf("Maximum value is %d.\n", array_max(size, array));

    return 0;
}

// Return the largest value in a given array.
int array_max(int size, int array[size]) {
    int max;
    int temp = 0;
    while (temp < size) {
        if (array[0] < array[temp]) {
            max = array[temp];
            array[temp] = array[0];
            array[0] = max;
            
        }
        temp++;
    }
    return array[0];
}
