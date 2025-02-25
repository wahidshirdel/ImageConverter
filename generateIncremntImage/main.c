#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define WIDTH 640
#define HEIGHT 512
int main(int argc, char *argv[]) {
	// Open a file for the PPM output
    FILE *image = fopen("image.ppm", "w");  // input image array 
	
    if (image == NULL) {

        perror("Error opening file1");

        return EXIT_FAILURE;
    }
    
	fprintf(image, "P2\n");
    fprintf(image, "%d %d\n", WIDTH, HEIGHT);
    fprintf(image, "256\n");

unsigned char value = 0;
for (int i =0 ;i<HEIGHT;i++){
	for (int j = 0 ;j<WIDTH;j++){
	    fprintf(image, "%d\n", value); // Print the character to ppm_file2
	    value ++ ;
	}
}
    fclose(image);

	return 0;
}