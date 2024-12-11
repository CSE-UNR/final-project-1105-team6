#include <stdio.h>
#define STR_CAP 100
#define FILE_NAME "madlib2.txt"


int lineLengthString(char string[STR_CAP]);
void printArray(int rows, char array[rows][STR_CAP]);
void extractPlaceholders(char array[][STR_CAP], int lineCount, char letters[], int lineNumber[]);
void readMadLibLines(FILE *fptr, char file[][STR_CAP], char readFromFileString[STR_CAP], int* linesPtr); 
void getUserInputs(char letters[], char input[][STR_CAP], int lineCount, int lineNumber[]);


int main() {
	int lines, letterLocations[STR_CAP];
	int* linesPtr;
	char readFileString[STR_CAP], lettersArray[STR_CAP], file[STR_CAP][STR_CAP];
	FILE *fptr;
	fptr = fopen(FILE_NAME, "r");
	if (fptr == NULL) {	
		printf("Error opening file\n");
		return 0;
	}
    
    readMadLibLines(fptr, file, readFileString, &lines);
    fclose(fptr);
    
    char userWords[lines][STR_CAP];
  
    
    
    extractPlaceholders(file, lines, lettersArray, letterLocations);
    getUserInputs(lettersArray, file, lines, letterLocations);
    printArray(lines, file);
  


    return 0;
}

void extractPlaceholders(char array[][STR_CAP], int lineCount, char letters[], int lineNumber[]) {
int i, counter = 0;
	for(i=0; i<lineCount; i++){
		if(array[i][0] == 'A' && array[i][1] =='\n'){
			letters[counter] = array[i][0];
			lineNumber[counter] = i+1;
			counter++;
			}
		else if(array[i][0] == 'N' && array[i][1] == '\n'){
			letters[counter] = array[i][0];
			lineNumber[counter] = i+1;
			counter++;
			}
		else if(array[i][0] =='V' && array[i][1] == '\n'){
			letters[counter] = array[i][0];
			lineNumber[counter] = i+1;
			counter++;
			}
		}
	letters[counter] = '\0';
	lineNumber[i] = '\0';
}

void getUserInputs(char letters[], char file[][STR_CAP], int lineCount, int lineNumber[]) {
    for (int i = 0; i <= lineLengthString(letters); i++) {
        if (letters[i] == 'N') {
		printf("Please enter a noun: ");
		fgets(file[lineNumber[i]-1], STR_CAP, stdin);
		} 
	else if (letters[i] == 'V') {
		printf("Please enter a verb: ");
		fgets(file[lineNumber[i]-1], STR_CAP, stdin);
        	}
	else if (letters[i] == 'A') {
		printf("Please enter an adjective: ");
		fgets(file[lineNumber[i]-1], STR_CAP, stdin);
        	} 
        int j = 0;
        
        while (file[i][j] != '\0') {
            if (file[i][j] == '\n') {
                file[i][j] = '\0';
            }
            j++;   
        }  
    }
}

void readMadLibLines(FILE *fptr, char file[][STR_CAP], char readFromFileString[STR_CAP], int* linesPtr) {
    int j = 0;
    while (fgets(readFromFileString, STR_CAP, fptr) != NULL) {
        int k;
        for (k = 0; readFromFileString[k] != '\0'; k++) {
            file[j][k] = readFromFileString[k];
        }
     //   file[j][k] = '\0';
        *linesPtr = j;
        j++;
    }

}

void printArray(int rows, char array[rows][STR_CAP]) {
    for (int i = 0; i < rows; i++) {
        int j = 0;
        if(array[i][j] != '.' && array[i][j] != ',' && array[i][j] != '!' && array[i][j] != '?' 
        && array[i][j] != ':' && array[i][j] != ';' && array[i][j] != '"' && array[i][j] != '\''){
		printf(" ");
     		}
        while (array[i][j] != '\0') {
		if (array[i][j] != '\n') {
			printf("%c", array[i][j]);
			}
		j++;
		}
   	 }
    printf("\n");
}
        

int lineLengthString(char string[STR_CAP]) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length-1;
}

        
        
        
