#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char inputFilename[] = "lena.txt";  // Input file containing decimal numbers
    char outputFilename[] = "output.txt"; // Output file to store hex numbers
    int decimalNumber;

    // Open the input file for reading
    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file %s\n", inputFilename);
        return 1;
    }

    // Open the output file for writing
    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file %s\n", outputFilename);
        fclose(inputFile);  // Close input file if output file fails to open
        return 1;
    }

    // Read each decimal number from the file and convert to hexadecimal
//    while (fscanf(inputFile, "%d", &decimalNumber) != EOF) {
//        // Write the decimal number and its hexadecimal equivalent to the output file
//        fprintf(outputFile, "%X,\n", decimalNumber);
//    }
//for (int i = 0; i<10;i++){
// fscanf(inputFile, "%d", &decimalNumber);
//printf("%d\n",decimalNumber);
//}
        // Write the decimal number and its hexade
for (int i = 0; i<512;i++){
	for (int j = 0 ;j<640;j++){
		if (j<=511){
		 fscanf(inputFile, "%d", &decimalNumber);
    	 fprintf(outputFile, "%02x,\n", decimalNumber);	
	 }
	 else 
	      fprintf(outputFile, "%02x,\n", 0);	


	}
}
    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion completed. Check the file %s for results.\n", outputFilename);

    return 0;
}