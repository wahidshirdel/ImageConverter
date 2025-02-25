#include <stdio.h>

#include <stdlib.h>





#define WIDTH 512

#define HEIGHT 512

int main(){

			unsigned char  ch;

		int header= 1080;

	    // Open a file for the PPM output

    FILE *ppm_file = fopen("MINEh.ppm", "r");

    if (ppm_file == NULL) {

        perror("Error opening file1");

        return EXIT_FAILURE;

    }
    FILE *ppm_file1 = fopen("MINEh2.ppm", "w");




      if (ppm_file1 == NULL) {

        perror("Error opening file2");

        return EXIT_FAILURE;

    }
    
		   ch = fgetc(ppm_file);
		    fprintf(ppm_file1,"%d \n",ch);

//    fprintf(ppm_file1, "P2\n");
//
//    fprintf(ppm_file1, "%d %d\n", WIDTH, HEIGHT);
//
//    fprintf(ppm_file1, "256\n");
//
//		for (int i=0;i<HEIGHT*WIDTH;i++){
//
//		   ch = fgetc(ppm_file);
//
//		    if(i>=header)
//
//		    fprintf(ppm_file1,"%d \n",ch);
//
//		  //  printf("%x\n",ch);
//
//		    }



        fclose(ppm_file);

        fclose(ppm_file1);





	return 0 ;

}