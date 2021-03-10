#pragma once

// Guzzi Francesca 0000969922
// Fondamenti di Informatica T-1 Modulo 2
// 21/01/21



// A Library that gives you the utilities for reading through a text file.
// It provides all sort of useful wrappers for C standard functions with simple error handling.
// You can also find functions to parse through the line you read and load the values in a struct
// while converting different file types.

// Made with <3 by some UNIBO students!

// Commented version: https://github.com/hydrangeax/data-structures-c

#define STD_LINE_DIM 256

#define LINE_LONGER_THAN_DEST_DIM 1
#define LINE_READ_CORRECTLY 0
#define READ_PAST_EOF -1

#define TOKEN_ARR_MAX_DIM 50
#define TOKEN_ARR_IS_TOO_SMALL 1
#define TOKEN_ARR_BUILT_CORRECTLY 0

#define _FILE_H_

FILE* openFile(char fileName[], char mode[]);

int closeFile(FILE* src);

int readLine(FILE* src, char* line, int dimLine);

int getTokenLine(char* line, char* sep, char** tokens);

void loadElementData(char** tokens, char* format, ...);



