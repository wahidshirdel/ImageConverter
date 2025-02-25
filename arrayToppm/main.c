#include <stdio.h>
#include <stdlib.h>

#define WIDTH 512
#define HEIGHT 512
void PPMimage(FILE *ppm_file1,FILE *ppm_file2);
void RAWgenerator(FILE *ppm_file1,FILE *ppm_file2);
int chartoint(char name[]);
int main(int argc, char *argv[]) {
	unsigned char  ch;
	int i ;
	
	
	// Open a file for the PPM output
    FILE *ppm_file1 = fopen("lena.txt", "r");  // input image array 
	
    if (ppm_file1 == NULL) {

        perror("Error opening file1");

        return EXIT_FAILURE;
    }
    FILE *ppm_file2 = fopen("RAWdata.txt", "r"); //output RAW data /input RAW data

    if (ppm_file2 == NULL) {

        perror("Error opening file1");

        return EXIT_FAILURE;
    }
    FILE *ppm_file3 = fopen("lena.ppm", "w");  //output lena picture 

    if (ppm_file3 == NULL) {

        perror("Error opening file1");

        return EXIT_FAILURE;
    }
//---------------------------------------

	PPMimage(ppm_file1,ppm_file3);
    fclose(ppm_file1);
	fclose(ppm_file2);
	fclose(ppm_file3);

	return 0;
}
int  chartoint(char names[]){
	int i=0, number;
//	printf("%s",name);
	   while (names[i] != '\0'){
		number = names[2]-'0' + 10*(names[1]-'0')+ 100*(names[0]-'0');
    	i++;
	}
//		printf("inner = %d",number);

	return number; 
}
/*
*
*this function get the lena.txt file and genrate PPM file format 
*and we can see the result in an image 
*
*/
void PPMimage(FILE *ppm_file1,FILE *ppm_file2){
	unsigned char  ch;
	int i ;
	fprintf(ppm_file2, "P2\n");
    fprintf(ppm_file2, "%d %d\n", WIDTH, HEIGHT);
    fprintf(ppm_file2, "256\n");
    while (ch != '{'){// Loop until ch is '{'
    	ch = fgetc(ppm_file1);
	}
    while ((ch = fgetc(ppm_file1)) != '}') // Loop until ch is '}'
{
    if (ch == ',') {
        ch = '\n'; // Replace ',' with a newline
        i++;
    }
    fprintf(ppm_file2, "%c", ch); // Print the character to ppm_file2
}
	
}

/*
*
*this function get the lena.txt file and genrate raw file 
*and each pixel data in one line 
*
*/
void RAWgenerator(FILE *ppm_file1,FILE *ppm_file2){
	unsigned char  ch;
	int i ;
    while (ch != '{'){
    	ch = fgetc(ppm_file1);
	}
    while ((ch = fgetc(ppm_file1)) != '}') // Loop until ch is '}'
{
    if (ch == ',') {
        ch = '\n'; // Replace ',' with a newline
        i++;
    }
    fprintf(ppm_file2, "%c", ch); // Print the character to ppm_file2
}
}