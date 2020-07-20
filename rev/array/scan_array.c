// Scan in an array.
// Created by
//  ... (z0000000)
// Created on 2019-??-??

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 1000

void scan_array(int size, int array[size]);
void show_array(int size, int array[size]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // Create the array.
    int array[MAX_SIZE];

    // Get the array size.
    int size;
    printf("Enter array size: ");
    assert(scanf("%d", &size) == 1);
    assert(size > 0);

    // Scan in values for the array.
    printf("Enter array values: ");
    scan_array(size, array);

    // Print the values.
    show_array(size, array);

    return 0;
}

// This function reads in values from standard input into an array.
void scan_array(int size, int array[size]) {
    int count = 0;
    while (count < size) {
        scanf("%d", &array[count]);
        count++;
    }
    
}

// This function prints the array in the format
// [1, 2, 3, ...]
void show_array(int size, int array[size]) {
    printf("[");
    
    int count = 1;
    printf("%d",array[0]); 
    while (count < size) {
    
        printf(", %d",array[count]);
        count++;
    }
    printf("]\n");
}
