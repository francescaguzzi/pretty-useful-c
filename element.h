#define _CRT_SECURE_NO_WARNINGS


// In this header file, you can declare the components of your struct, so called "element".
// This gives extreme flexibility to your code (even if C doesn't really give you the chance 
// to be so flexible, but we love him anyways) because you can shape your struct here, and 
// ONLY ONE TIME! 

// Made with <3 by some UNIBO students!

#ifndef INCREASING
#define INCREASING 1
#define DECREASING 0
#endif

#define DIM 2048

#define _ELEMENT_H_


typedef struct {

	int ID;
	char content[DIM];
	char type;
	int qty;
	float cost;

} element;

