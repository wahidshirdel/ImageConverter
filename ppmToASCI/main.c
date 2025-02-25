#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input_file, *output_file;
    char line[10];  // Buffer to store each line from the file
    int int_arr[512*512];  // Array to store the integers, assuming a max of 100 numbers
    int count = 0;  // To keep track of the number of integers

    // Open the input file for reading
    input_file = fopen("RAWdata.txt", "r");

    if (input_file == NULL) {
        printf("Error opening the input file!\n");
        return 1;  // Exit if the file can't be opened
    }

    // Read each line from the file, convert it to an integer, and store it in the array
    while (fgets(line, sizeof(line), input_file)) {
        int_arr[count] = atoi(line);  // Convert each line to an integer
        count++;  // Increment the count of integers
    }

    // Close the input file after reading
    fclose(input_file);

    // Open the output file for writing
    output_file = fopen("output_numbers.txt", "w");

    if (output_file == NULL) {
        printf("Error opening the output file!\n");
        return 1;  // Exit if the file can't be opened
    }

    // Write the integers back into the file in ASCII format (as plain text)
    for (int i = 0; i < count; i++) {
        fprintf(output_file, "%c", int_arr[i]);  // Write each integer as ASCII text
    }

    // Close the output file after writing
    fclose(output_file);

    printf("Data has been written to 'output_numbers.txt'.\n");

    return 0;
}
