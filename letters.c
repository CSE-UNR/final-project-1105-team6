// Matthew Boga
// CS 135
// 12/5/24

#include <stdio.h>
#define STR_CAP 1000
#define FILE_NAME "madlib1.txt"

int stringLength(char[]);
int lineCount(FILE *fptr);
void letters(FILE *fptr, char lettersArray[]);

int main(){
	int numLines;
	char string1[STR_CAP], lettersArray[STR_CAP];
	
	FILE *fptr;

	fptr = fopen(FILE_NAME, "r");
    
	if (fptr == NULL) 
	{	
		printf("Error opening file\n");
		return 0;
	}
	
	letters(fptr,lettersArray);
	
	fclose(fptr);	
	
	
	return 0;
}

void letters(FILE *fptr,char lettersArray[]){
	int j =0;
	char string[STR_CAP];
	while(fgets(string, STR_CAP, fptr) != NULL){
		fgets(string, STR_CAP, fptr);
		lettersArray[j] = string[0];
		j++;
 	}	
 
}






