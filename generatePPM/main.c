#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for using time fucntion 


#define WIDTH 6
#define HEIGHT 6
int headerType(FILE *file );
int main(int argc, char *argv[]) {	
	unsigned char  ch;
	FILE *ppm_file = fopen("generate.ppm", "w");
	FILE *ppm_file2 = fopen("generate2.txt", "w");

	if (ppm_file == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
    }
    time_t t1; // declare time variable  
      
    /* define the random number generator */  
    srand ( (unsigned) time (&t1)); // pass the srand() parameter  
    printf("\n"); // print the space  
    /* generate random number between 0 to 50 */
    headerType(ppm_file);
	for (int i ;i<HEIGHT*WIDTH;i++) {
			unsigned int mynumber = rand() %128; 
	printf("NUMBER%d => %c && %d\n",i ,mynumber,mynumber);
	fprintf(ppm_file,"%d\n",mynumber);
	fprintf(ppm_file2,"%c",mynumber);

	}
	fclose(ppm_file);

	return 0;
}
int headerType(FILE *file ){
	fprintf(file,"P2\n");
    fprintf(file, "%d  %d\n", WIDTH, HEIGHT);
	fprintf(file, "256\n");

	return 0;
}
