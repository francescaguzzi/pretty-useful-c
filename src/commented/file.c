#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "file.h" 


// A function that works like fopen, but with error handling.

FILE* openFile(char fileName[], char mode[]) {
		
	FILE* fp = fopen(fileName, mode);
	if (fp == NULL) {
		perror("There was an error opening the file: ");
	}

	return fp;
}

// A function that works like fclose, but with error handling.

int closeFile(FILE* src) {

	if (src != NULL) {
		fclose(src);
		return 0;
	}

	else return -1;
}

// A function that reads a single line from a file.

int readLine(FILE* src, char* line, int dimLine) {          // You should give this function a pointer to a file, the 
	                                                        // destination string and its dimension.
	char ch;
	int i = 0;

	if (src == NULL) {
		exit(EXIT_FAILURE);                                 // If the pointer to the file is empty, the function exits.
	}

	ch = fgetc(src);                                        // Reading the first character of the file.

	if (feof(src) != 0) {                                   // If you read past the EOF, the function exits with -1.
		return READ_PAST_EOF;
	}

	while (ch != '\n' && ch != EOF && i < (dimLine - 1)) {  // Reading the file's first line character by character.
		line[i++] = ch;
		ch = fgetc(src);
		if (feof(src) != 0) {                               // If you read past the EOF, the function exits with -1.
			return READ_PAST_EOF;
		}
	}

	line[i] = '\0';                                         // Assures the string ends with '\0'.
	if (i == (dimLine - 1) && ch != EOF && ch != '\n') {    // If the next character is an EOF or end of the line the line is longer than the dest dimension.
		return LINE_LONGER_THAN_DEST_DIM;
	}                                                       // ...Else the buffer was read correctly.

	return LINE_READ_CORRECTLY;        
}


// This function requires a string ("line", the string you read with the previous function, 
// "sep" the character that divides the tokens you want to get from the string, and a pointer
// array that'll store your tokens.

int getTokenLine(char* line, char* sep, char** token) {    

	int i = 0;
	char* next_token = NULL;							    // A pointer to the next token required by strtok_s to work.

	token[0] = strtok_s(line, sep, &next_token);			// Using strtok to get tokens from the line previously read.
	                                                        
	while (token[i] != NULL && i < (TOKEN_ARR_MAX_DIM - 1)) {
		token[++i] = strtok_s(NULL, sep, &next_token);
	}

	if (i == (TOKEN_ARR_MAX_DIM - 1) && token[i] != NULL) {
		token[i] = NULL;									// This part assures that the tokens'array always ends with a NULL pointer
		                                                    // even if some tokens won't be saved.
		return TOKEN_ARR_IS_TOO_SMALL;						// But it returns 1 to indicate that error.
	}

	token[i] = NULL;

	return TOKEN_ARR_BUILT_CORRECTLY;						// If the token array is built correctly we return 0.
}


// This function works like scanf and printf: it requires the pointers'array where you previously
// stored your tokens, the types in which you want your tokens to be converted ("%s%s%d" alike)
// and their destination address (the components of your struct).

// Even if it needs some refactoring, this function is extremely powerful and flexible: you can allocate
// the components of any struct you want, runtime!

void loadElementData(char** tokens, char* format, ...) {

	char parsedFormat[TOKEN_ARR_MAX_DIM];                   // String which characters represent the type of an argument.
	int value = 0;                        
	int j = 0;                                              // Loop counters.
	va_list args;                                            
	
	int* x = NULL;											// Pointers to int used for conversion.
	float* y = NULL;										// Pointer to float used for conversion.
	double* z = NULL;										// Pointer to double used for conversion.
					    
	int i = 0;
	int numberArg = 0;

	while (format[i] != '\0') {
		if (format[i] != '%') {
			if (format[i + 1] != '%' && format[i + 1] != '\0') {
				perror ("The string was formatted badly.");
			}
			parsedFormat[numberArg] = format[i];            // Getting the formatted input of the tokens.
			numberArg++;
		}
		i++;
	}
	parsedFormat[numberArg] = '\0';
	
	while (tokens[j++] != NULL) {                           // Counting the elements in the tokens'array.
		
		value++;										    // Setting the value to count the number of iterations
															// needed by the switch function.
	}


	va_start(args, format);

	for (int k = 0; k < value; k++)
	{
		switch (parsedFormat[k]) {						    // Switch case that takes the string parsedFormat and converts its values
		case 's':                                           // in tokens of the right type requested by the pointer passed by an argument of the function.
			strcpy(va_arg(args, char*), tokens[k]);			// String to string.
			break;
		case 'd':
			x = va_arg(args, int*);							// This will make the conversion return a pointer to int.
			*x = atoi(tokens[k]);							// String to int.
			break;
		case 'f':
			y = va_arg(args, float*);						// This will make the conversion return a pointer to float.
			*y = (float) atoll(tokens[k]);					// String to float.
			break;
		case 'c':
			strcpy(va_arg(args, char*), tokens[k]);			// This will make the conversion return a pointer to characters.
			break;
		case 'w':
			z = va_arg(args, double*);						// This will make the conversion return a pointer to double.
			*z = atof(tokens[k]);							// String to double.
			break;
		}
	}

	// Must add feature: number's arrays

	va_end(args);
}


