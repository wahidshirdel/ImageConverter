#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main(int argc, char *argv[]) {

	FILE *output = fopen("hexpict.txt","w");
	if (output == NULL){
		perror("Error opening file");
		return EXIT_FAILURE;
	}
//	printf("the number is %02x" ,24);
for  (int j= 0 ;j<512 ;++j){
	for (int i=0 ; i<640;i++){
   if (i < 100)
        fprintf(output, "%02x,\n", 13);
    else if (i < 200)
        fprintf(output, "%02x,\n", 42);
    else if (i < 300)      
        fprintf(output, "%02x,\n", 84);
    else if (i < 400)      
        fprintf(output, "%02x,\n", 150);
    else if (i < 500)      
        fprintf(output, "%02x,\n", 200);
    else                   
        fprintf(output, "%02x,\n", 255);	

	}
	}

	    fclose(output);

	return 0;
}
