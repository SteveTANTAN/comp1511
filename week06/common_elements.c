// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination

int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    int counter = 0;
    int temp1 = 0, temp2 = 0;
    while (temp1 < length) {
        temp2=0;
        int result = 0; 
        while (temp2 < length) {
            if (source1[temp1] == source2[temp2]) {
                destination[counter] = source1[temp1];
                result++;
                if (result == 1) {
                    counter++;
                }
            }
            temp2++;
        }
        temp1++;
    }
    return counter;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.
