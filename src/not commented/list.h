#pragma once

// Guzzi Francesca 0000969922
// Fondamenti di Informatica T-1 Modulo 2
// 21/01/21



// This library contains every function you need for basic linked
// lists operations. You can find here functions that create, modify
// and much more related to linked lists. You don't have to include "file.h"
// if you don't want to (although it is extremely useful), while "element.h"
// is required to define the node's struct.

// Made with <3 by some UNIBO students!

// Commented version: https://github.com/hydrangeax/data-structures-c

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


typedef struct listElement {           
	element data;                      
	struct listElement* next;         
} node;

typedef node* list;

typedef enum {                         
	false, true                        
} boolean;


node* emptyList();

node* insertHead(list head, element src);

node* insertTail(list head, element src);

//int compare(element v1, element v2, int type);              
															
//node* insertOrdered(node* head, element src, int ord);

void insertAfter(node* prevNode, element src);

//void printNode(element data);								
															
//void printList(node* head);

int numberOfNodes(node* head);

boolean checkNode(node* head, int x);						
															
void deleteList(node* head);
