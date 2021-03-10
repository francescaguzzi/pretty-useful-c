#pragma once

// This library contains every function you need for basic linked
// lists operations. You can find here functions that create, modify
// and much more related to linked lists. You don't have to include "file.h"
// if you don't want to (although it is extremely useful), while "element.h"
// is required to define the node's struct.

// Made with <3 by some UNIBO students!

#define INCREASING -1
#define DECREASING 1
#define NUM 2
#define STR -2


#ifndef _ELEMENT_H_
#include "element.h"
#endif

#ifndef _FILE_H_
#include "file.h"
#endif


typedef struct listElement {           // Here the "node", the primary structure of the linked list is defined:
	element data;                      // it's composed by the data contained in the "element" struct (see "element.h").
	struct listElement* next;         
} node;

typedef node* list;

typedef enum {                         // The boolean type (defined here by this enumeration) can assume two values:
	false, true                        // true or false, respectively corresponding to 1 and 0.
} boolean;


// HARD-CODED FUNCTIONS - this means you don't have to change them! 

node* emptyList();

node* insertHead(list head, element src);

node* insertTail(list head, element src);

int compare(element v1, element v2, int type);              // <--  NOT HARD-CODED - you must change this function when you modify the struct defined
															//                       in "element.h" in order to make it work.
node* insertOrdered(node* head, element src, int ord);

void insertAfter(node* prevNode, element src);

void printNode(element data);								// <--  NOT HARD-CODED - you must change this function when you modify the struct defined
															//                       in "element.h" in order to make it work.
void printList(node* head);

int numberOfNodes(node* head);

boolean checkNode(node* head, int x);						// <--  NOT HARD-CODED - you must change this function when you modify the struct defined
															//                       in "element.h" in order to make it work.
void deleteList(node* head);
