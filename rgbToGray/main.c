//-----------------------------------convert p6 to p5 grayscale
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//    unsigned char r, g, b;
//} Pixel;
//
//int main() {
//    FILE *inputFile, *outputFile;
//    char format[3];
//    int width, height, maxColorValue;
//    
//    // Open the input PPM file in binary mode
//    inputFile = fopen("colorful_image.ppm", "rb");
//    if (inputFile == NULL) {
//        printf("Error: Unable to open input file!\n");
//        return 1;
//    }
//    
//    // Read PPM header (P6 format)
//    fscanf(inputFile, "%s", format);
//    if (format[0] != 'P' || format[1] != '6') {
//        printf("Error: Unsupported PPM format! Only binary PPM (P6) is supported.\n");
//        fclose(inputFile);
//        return 1;
//    }
//    
//    // Skip comments in the header
//    char c = fgetc(inputFile);
//    while (c == '#') {
//        while (fgetc(inputFile) != '\n');
//        c = fgetc(inputFile);
//    }
//    ungetc(c, inputFile);
//    
//    // Read image dimensions and max color value
//    fscanf(inputFile, "%d %d %d", &width, &height, &maxColorValue);
//    fgetc(inputFile); // Read the newline after the max color value
//    
//    // Allocate memory for the pixel data
//    Pixel *image = (Pixel *)malloc(width * height * sizeof(Pixel));
//    if (image == NULL) {
//        printf("Error: Memory allocation failed!\n");
//        fclose(inputFile);
//        return 1;
//    }
//    
//    // Read pixel data
//    fread(image, sizeof(Pixel), width * height, inputFile);
//    fclose(inputFile);
//    
//    // Open output file for the grayscale image
//    outputFile = fopen("output.pgm", "wb");
//    if (outputFile == NULL) {
//        printf("Error: Unable to open output file!\n");
//        free(image);
//        return 1;
//    }
//    
//    // Write PGM header (P5 format for grayscale)
//    fprintf(outputFile, "P5\n%d %d\n%d\n", width, height, maxColorValue);
//    
//    // Convert RGB to grayscale and write to the output file
//    for (int i = 0; i < width * height; i++) {
//        unsigned char gray = (unsigned char)(0.299 * image[i].r + 0.587 * image[i].g + 0.114 * image[i].b);
//        fwrite(&gray, sizeof(unsigned char), 1, outputFile);
//    }
//    
//    // Cleanup
//    fclose(outputFile);
//    free(image);
//    
//    printf("Conversion to grayscale completed successfully.\n");
//    
//    return 0;
//}
///----------------------------------------------------convert p6 to p2
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct {
//    unsigned char r, g, b;
//} Pixel;
//
//int main() {
//    FILE *inputFile, *outputFile;
//    char format[3];
//    int width, height, maxColorValue;
//    
//    // Open the input PPM file in binary mode
//    inputFile = fopen("colorful_image.ppm", "rb");
//    if (inputFile == NULL) {
//        printf("Error: Unable to open input file!\n");
//        return 1;
//    }
//    
//    // Read PPM header (P6 format)
//    fscanf(inputFile, "%s", format);
//    if (format[0] != 'P' || format[1] != '6') {
//        printf("Error: Unsupported PPM format! Only binary PPM (P6) is supported.\n");
//        fclose(inputFile);
//        return 1;
//    }
//
//    // Skip comments in the header
//    char c = fgetc(inputFile);
//    while (c == '#') {
//        while (fgetc(inputFile) != '\n');
//        c = fgetc(inputFile);
//    }
//    ungetc(c, inputFile);
//    
//    // Read image dimensions and max color value
//    fscanf(inputFile, "%d %d %d", &width, &height, &maxColorValue);
//    fgetc(inputFile);  // Read the newline after the max color value
//    
//    // Allocate memory for the pixel data
//    Pixel *image = (Pixel *)malloc(width * height * sizeof(Pixel));
//    if (image == NULL) {
//        printf("Error: Memory allocation failed!\n");
//        fclose(inputFile);
//        return 1;
//    }
//
//    // Read pixel data from P6 file
//    fread(image, sizeof(Pixel), width * height, inputFile);
//    fclose(inputFile);
//
//    // Open the output PGM file (P2 format)
//    outputFile = fopen("output2.ppm", "w");
//    if (outputFile == NULL) {
//        printf("Error: Unable to open output file!\n");
//        free(image);
//        return 1;
//    }
//
//    // Write P2 header
//    fprintf(outputFile, "P2\n%d %d\n%d\n", width, height, maxColorValue);
//    
//    // Convert each RGB pixel to grayscale and write the data to the P2 file
//    for (int i = 0; i < width * height; i++) {
//        unsigned char r = image[i].r;
//        unsigned char g = image[i].g;
//        unsigned char b = image[i].b;
//        unsigned char gray = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
//        fprintf(outputFile, "%d ", gray);
//        
//        // Optionally, add a newline after every row of pixels for formatting
//        if ((i + 1) % width == 0) {
//            fprintf(outputFile, "\n");
//        }
//    }
//
//    // Cleanup
//    fclose(outputFile);
//    free(image);
//    
//    printf("Conversion to grayscale (P2) completed successfully.\n");
//
//    return 0;
//}

//----------------------------------convert image to starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Characters used to represent pixel brightness (darker to lighter)
const char *ascii_chars = "@#%*+=-:. ";

int main() {
    FILE *inputFile;
    char format[3];
    int width, height, maxColorValue;
    
    // Open the input PGM (P2 or P5) file in binary mode
    inputFile = fopen("colorful_image - Copy.ppm", "rb");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file!\n");
        return 1;
    }

    // Read PGM header (P2 or P5 format)
    fscanf(inputFile, "%s", format);
    if (format[0] != 'P' || (format[1] != '2' && format[1] != '5')) {
        printf("Error: Unsupported PGM format! Only P2 (ASCII) or P5 (binary) is supported.\n");
        fclose(inputFile);
        return 1;
    }

    // Skip comments in the header
    char c = fgetc(inputFile);
    while (c == '#') {
        while (fgetc(inputFile) != '\n');
        c = fgetc(inputFile);
    }
    ungetc(c, inputFile);
    
    // Read image dimensions and max color value
    fscanf(inputFile, "%d %d %d", &width, &height, &maxColorValue);
    fgetc(inputFile);  // Read the newline after the max color value

    // Allocate memory for the pixel data
    unsigned char *image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (image == NULL) {
        printf("Error: Memory allocation failed!\n");
        fclose(inputFile);
        return 1;
    }

    // Read pixel data (for P5 binary format)
    if (format[1] == '5') {
        fread(image, sizeof(unsigned char), width * height, inputFile);
    } else {
        // Read pixel data (for P2 ASCII format)
        for (int i = 0; i < width * height; i++) {
            fscanf(inputFile, "%hhu", &image[i]);
        }
    }
    fclose(inputFile);

    // Convert grayscale values to ASCII characters and print them
    int numChars = strlen(ascii_chars);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Normalize the pixel value to the range of ascii_chars
            int grayValue = image[y * width + x];
            int charIndex = (grayValue * (numChars - 1)) / maxColorValue;
            printf("%c", ascii_chars[charIndex]);
        }
        printf("\n");  // Move to the next line after each row
    }

    // Cleanup
    free(image);

    return 0;
}

