#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

// Mohamed Yasser Anwar Mahmoud AlKayd
// Encryption & Decryption Cipher Program

// - Start of the Program - 

// - Possible Errors - 

void errorMsg(char *msg){
// 4 Lines of output
printf("%s", msg);
// The first line is the parameter msg defining the specific type of error that occured
printf("%s", "\nProgram syntax: ./cipher SWITCH KEY LENGTH < FILENAME\n");
// The second line is the program syntax
printf("%s", "Legal Usage Example 1: ./cipher -e 10 100 < filename.txt\n");
printf("%s", "Legal Usage Example 2: ./cipher -d 10 200 < filename.e\n");
// The third and fourth lines are legal usage examples intended for the script when called
exit(0);
}

char inputData[500];
char matrix[500][500];

// Intialize the inputData array as a global variable
// - Encryption Function - 
void encrypt(int key, int length){
	int i, j, x, y;
	// Get the input from the redirected file
	for(int i=0 ; i<length; i++){
		inputData[i] = getc(stdin);			
	}

	for(i=0 ; i<length; i++){
		x = i%key;
		y = i/key; 
			matrix[x][y] = inputData[i];
	}						
	for(i=0; i<key; i++){
		for(j=0; j<((length/key)+1); j++){
			if(matrix[i][j]=='\0'){
				printf(" ");
			}
			else
			{
			printf("%c", matrix[i][j]);	
			}	
		}
	}
	printf("\n");
}
// - Decryption Function -
void decrypt(int key, int length){
	int i, j, x, y, n;
	int newLength = length+1+length/key;
	int numRows = length/key+1;
	for(int i=0 ; i<newLength; i++){
		inputData[i] = getc(stdin);			
	}

	for(i=0; i<newLength; i++){
       		y = i%numRows;
        	x = i/numRows;
            	matrix[y][x] = inputData[i];
	}
	for(i=0; i<(newLength); i++){
		printf("%s",matrix[i]);
	}
         printf("\n");  
}
// - Main - 
int main(int argc, char *argv[]){
	// Check for Errors
	// Error 1 when the number of parameters is wrong
	if(argc != 4){
		errorMsg("Error: Wrong number of arguements");
	}
	 int key, length;
         key = atoi(argv[2]);
         length = atoi(argv[3]);
	// Error 2 when the switch is wrong
	if(strcmp(argv[1],"-e") != 0){
	if(strcmp(argv[1],"-d") !=0){
		errorMsg("Error: Wrong switch");
}
}
	// Error 3 when the length is equal to 0
	if(length==0){
		errorMsg("Error: length==Zero");
}
	// Error 4 when the length is greater than 500
	if(length>500){
		errorMsg("Error: Long length");
}
	// Error 5 when the key is equal to the length
	if(key==length){
		errorMsg("Error: Key is equal to length");
}
	// Error 6 when the key is greater than the length
	if(key>length){
		errorMsg("Error: key greater than the length");
}

	// Encryption if the switch is -e
	if(strcmp(argv[1],"-e") ==0){
	encrypt(key, length);
}
	
	// Decryption if the switch is -d
	else if (strcmp(argv[1],"-d") ==0){
	decrypt(key, length);
}
}
// - End of the Program -
