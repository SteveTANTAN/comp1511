//5237560 Steve TAN
//reads characters from its input and writes the same characters to its output
#include <stdio.h>
void is_vowel(int character);
int main(void) {
    int ch = getchar ();
    while (ch != EOF) {
        is_vowel(ch);
        ch = getchar ();
    }
    


    return 0;
}

void is_vowel(int character) {
    if (character == 'a'
        ||character == 'e'
        ||character == 'i'
        ||character == 'o'
        ||character == 'u') {
            
    } else {
        putchar (character);
    }
   
}
