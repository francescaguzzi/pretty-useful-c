#define _CRT_SECURE_NO_WARNINGS

// Guzzi Francesca 0000969922
// Fondamenti di Informatica T-1 Modulo 2
// 21/01/21



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "file.h" 


FILE* openFile(char fileName[], char mode[]) {
		
	FILE* fp = fopen(fileName, mode);
	if (fp == NULL) {
		perror("There was an error opening the file: ");
	}

	return fp;
}

int closeFile(FILE* src) {

	if (src != NULL) {
		fclose(src);
		return 0;
	}

	else return -1;
}

int readLine(FILE* src, char* line, int dimLine) {          

	char ch;
	int i = 0;

	if (src == NULL) {
		exit(EXIT_FAILURE);                                 
	}

	ch = fgetc(src);                                        

	if (feof(src) != 0) {                                   
		return READ_PAST_EOF;
	}

	while (ch != '\n' && ch != EOF && i < (dimLine - 1)) {  
		line[i++] = ch;
		ch = fgetc(src);
		if (feof(src) != 0) {                               
			return READ_PAST_EOF;
		}
	}

	line[i] = '\0';                                         
	if (i == (dimLine - 1) && ch != EOF && ch != '\n') {    
		return LINE_LONGER_THAN_DEST_DIM;
	}                                                       

	return LINE_READ_CORRECTLY;        
}

int getTokenLine(char* line, char* sep, char** token) {    

	int i = 0;
	char* next_token = NULL;							   

	token[0] = strtok_s(line, sep, &next_token);			
	                                                        
	while (token[i] != NULL && i < (TOKEN_ARR_MAX_DIM - 1)) {
		token[++i] = strtok_s(NULL, sep, &next_token);
	}

	if (i == (TOKEN_ARR_MAX_DIM - 1) && token[i] != NULL) {
		token[i] = NULL;									
		                                                    
		return TOKEN_ARR_IS_TOO_SMALL;						
	}

	token[i] = NULL;

	return TOKEN_ARR_BUILT_CORRECTLY;						
}

void loadElementData(char** tokens, char* format, ...) {

	char parsedFormat[TOKEN_ARR_MAX_DIM];                   
	int value = 0;                        
	int j = 0;                                              
	va_list args;                                            
	
	int* x = NULL;											
	float* y = NULL;										
	double* z = NULL;										
					    
	int i = 0;
	int numberArg = 0;

	while (format[i] != '\0') {
		if (format[i] != '%') {
			if (format[i + 1] != '%' && format[i + 1] != '\0') {
				perror ("The string was formatted badly.");
			}
			parsedFormat[numberArg] = format[i];            
			numberArg++;
		}
		i++;
	}
	parsedFormat[numberArg] = '\0';
	
	while (tokens[j++] != NULL) {                           
		
		value++;										    
															
	}


	va_start(args, format);

	for (int k = 0; k < value; k++)
	{
		switch (parsedFormat[k]) {						    
		case 's':                                           
			strcpy(va_arg(args, char*), tokens[k]);	
			break;
		case 'd':
			x = va_arg(args, int*);							
			*x = atoi(tokens[k]);							
			break;
		case 'f':
			y = va_arg(args, float*);						
			*y = (float) atoll(tokens[k]);					
			break;
		case 'c':
			strcpy(va_arg(args, char*), tokens[k]);			
			break;
		case 'w':
			z = va_arg(args, double*);						
			*z = atof(tokens[k]);							
			break;
		}
	}

	va_end(args);
}


