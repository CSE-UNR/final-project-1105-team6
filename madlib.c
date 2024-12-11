// Matthew Boga, Daniela Dennis, and Ethan Hirrlinger
// 12/10/2024
// CS 135
// Final Project: Madlib Group Project

#include <stdio.h>
#define STR_CAP 100
#define FILE_NAME "madlib1.txt"

int lineLengthString(char string[STR_CAP]);
void readMadLibLines(FILE *fptr, char array[][STR_CAP], char readFromFileString[STR_CAP], int* linesPtr); 
void extractPlaceholders(char array[][STR_CAP], int lineCount, char placeholders[], int lineNumber[]);
void getUserInputs(char placeholders[], char array[][STR_CAP], int lineCount, int lineNumber[]);
void printArray(int rows, char array[rows][STR_CAP]);

int main() {
	int lines, letterLocations[STR_CAP];
	int* linesPtr;
	char readFileString[STR_CAP], lettersArray[STR_CAP], madLib[STR_CAP][STR_CAP];
	
	FILE *fptr;
	fptr = fopen(FILE_NAME, "r");
	if (fptr == NULL) {
		printf("Error opening file\n");
		return 0;
	}
	
	readMadLibLines(fptr, madLib, readFileString, &lines);
		char userWords[lines][STR_CAP];
	fclose(fptr);
	
	extractPlaceholders(madLib, lines, lettersArray, letterLocations);
	getUserInputs(lettersArray, madLib, lines, letterLocations);
	printArray(lines, madLib);
  
	return 0;
}

void extractPlaceholders(char array[][STR_CAP], int lineCount, char placeholders[], int lineNumber[]) {
int i, counter = 0;
	for(i=0; i<lineCount; i++){
		if(array[i][0] == 'A' && array[i][1] =='\n'){
			placeholders[counter] = array[i][0];
			lineNumber[counter] = i+1;
			counter++;
			}
		else if(array[i][0] == 'N' && array[i][1] == '\n'){
			placeholders[counter] = array[i][0];
			lineNumber[counter] = i+1;
			counter++;
			}
		else if(array[i][0] =='V' && array[i][1] == '\n'){
			placeholders[counter] = array[i][0];
			lineNumber[counter] = i+1;
			counter++;
			}
		}
	placeholders[counter] = '\0';
	lineNumber[i] = '\0';
}

void getUserInputs(char placeholders[], char array[][STR_CAP], int lineCount, int lineNumber[]) {
    for (int i = 0; i <= lineLengthString(placeholders); i++) {
        if (placeholders[i] == 'N') {
		printf("Please enter a noun: ");
		fgets(array[lineNumber[i]-1], STR_CAP, stdin);
		} 
	else if (placeholders[i] == 'V') {
		printf("Please enter a verb: ");
		fgets(array[lineNumber[i]-1], STR_CAP, stdin);
        	}
	else if (placeholders[i] == 'A') {
		printf("Please enter an adjective: ");
		fgets(array[lineNumber[i]-1], STR_CAP, stdin);
        	} 
        int j = 0;
        
        while (array[i][j] != '\0') {
            if (array[i][j] == '\n') {
                array[i][j] = '\0';
            }
            j++;   
        }  
    }
}

void readMadLibLines(FILE *fptr, char array[][STR_CAP], char readFromFileString[STR_CAP], int* linesPtr) {
    int j = 0;
    while (fgets(readFromFileString, STR_CAP, fptr) != NULL) {
        int k;
        for (k = 0; readFromFileString[k] != '\0'; k++) {
            array[j][k] = readFromFileString[k];
        }
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
  
