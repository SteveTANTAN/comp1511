// Perform the ROT13 algorithm on a string
// Completed by
//  ... (z0000000)
// Completed on 2019-??-??

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 256

// Add your own #defines here

void rotate_thirteen(char *string);
char rotate_one(char c);
void rotate_thirteen(char *string);
int strings_equal(char *string1, char *string2);

// Add your own function prototypes here

int main(int argc, char *argv[]) {
    // Example tests
    char test_a[MAX_LENGTH] = "Hello, world!";
    rotate_thirteen(test_a);
    assert(strings_equal("Uryyb, jbeyq!", test_a));

    char test_b[MAX_LENGTH] = "abcdefghijklmnopqrstuvwxyz";
    rotate_thirteen(test_b);
    assert(strings_equal("nopqrstuvwxyzabcdefghijklm", test_b));

    char test_c[MAX_LENGTH] = "The quick brown fox jumped over the lazy dog.";
    rotate_thirteen(test_c);
    assert(strings_equal("Gur dhvpx oebja sbk whzcrq bire gur ynml qbt.", test_c));

    // Add your own tests here

    printf("All tests passed. You are awesome!\n");

    return 0;
}

void rotate_thirteen(char *string) {
    int count = 0;
    while (string[count] != '\0') {
        
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        string[count] = rotate_one(string[count]);
        
        count++;
    }  
}

char rotate_one(char c) {
    if (c >= 'a' && c <= 'z') {
        if (c == 'z') {
            c = 'a';
        } else {
        
            c = c + 1;
        }
    
    } else if (c >= 'A' && c <= 'Z') {
        if (c == 'Z') {
            c = 'A';
        } else {
        
            c = c + 1;
        }
    
    }  
    
    return c;
}

int strings_equal(char *string1, char *string2) {
    int count = 0;
    int test = 1;
    while (string1[count] != '\0' && string2[count] != '\0') {
        if (string1[count] != string2[count]) {
        
            test = 0;
        }
        count++;
    }
    
    if (string1[count] != '\0' || string2[count] != '\0'){
        test = 0;
    }
    return test;
}
