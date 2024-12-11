// Display Madlib
// Input 

#include <stdio.h>
#define MAX 100

void display(int numLines, char twodarray[][MAX]);

int main()
{
    char twodarray[MAX][MAX];
    int i,j, numLines = 5;

        for (j = 0; j < 8; j++) {
            twodarray[0][j] = '[';
  
        }
        for (j = 0; j < 3; j++) {
            twodarray[1][j] = '?';
  
        }
        for (j = 0; j < 3; j++) {
            twodarray[2][j] = '!';
  
        }
        for (j = 0; j < 3; j++) {
            twodarray[3][j] = '.';
  
        }
        for (j = 0; j < 11; j++) {
            twodarray[4][j] = '=';
  
        }
 
 
 display(numLines, twodarray);
 
 
    return 0;
}


void display(int numLines, char twodarray[][MAX]){
	int i,j, lengths[MAX];
	for(i=0;i<numLines;i++){
		j=0;
			while(twodarray[i][j]){
			j++;
			lengths[i]=j;
			}
		}

	for (i = 0; i < numLines; i++) {
	        for (j = 0; j < lengths[i]; j++) {
	            printf("%c", twodarray[i][j]);
		}
	        printf("\n");
		}
}







