#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

// Disclaimer! The "node*" type can be easily replaced by the "list" type (which is basically a pointer to
// the linked list's nodes) defined in the header file, if you prefer.

// This function initializes an empty list.

node* emptyList() {
	return NULL;
}

// This function checks if your list is empty or not.

boolean checkEmpty(node* head) {
	return (head == NULL);
}

// This function inserts a node in your list starting from its head, meaning that if you need to insert, for
// example, a bunch of elements like "2 4 6 7", the printed output of your list will be "7 6 4 2", because the
// elements iterate from the top to the bottom.

node* insertHead(list head, element src) {              // This function takes in input an initialized "head" (a node*
														// or a list type, as you prefer) and a source struct where
	list tmp;                                           // your data is stored.

	tmp = (list)malloc(sizeof(node));                   // Dinamically allocates the memory.

	if (tmp == NULL) {                                  // Check if there's enough memory.
		return NULL;
	}
	else {
		tmp->data = src;                                // ...Else, allocates the data in it, and points the next
		tmp->next = head;                               // node to the head of the linked list.
	}
	return tmp;
}

// This function inserts a node in your list starting from its tail, meaning that if you need to insert, like
// above, a bunch of elements like "2 4 6 7", the printed output of your list will be "2 4 6 7", because the
// elements iterate from the bottom to the top.

node* insertTail(list head, element src) {              // This function takes in input an initialized "head" (a node*
														// or a list type, as you prefer) and a source struct where
	list tmp, pnt;                                      // your data is stored.

	tmp = calloc(1, sizeof(node));                      // Dinamically allocates the memory.

	if (tmp == NULL) {
		return NULL;                                    // Check if there's enough storage available.
	}
	if (head == NULL) {
		head = tmp;                                     // If the head of the list is empty, fills it with the temporary variable.
	}
	else {                                              // ...Else, creates a temporary list and iterates until it doesn't find
		pnt = head;                                     // any NULL node, scrolling from the bottom to the top.
		while (pnt->next != NULL)
			pnt = pnt->next;

		pnt->next = tmp;
	}

	tmp->data = src;                                    // Allocates the data in it.
	return head;
}

// This function takes in input two structs, and an integer to specify the
// type of comparison needed (NUM/STR), then compares them.
// Not hard-coded. Must change the parameters when needed.

int compare(element v1, element v2, int type) {

	switch (type) {
	case NUM:                                           // Numerical comparison.
		if (v1.ID < v2.ID) {
			return DECREASING;
		}
		else {
			if (v1.ID == v2.ID) {
				return 0;
			}
			else
				return INCREASING;
		}

		break;

	case STR:
		return strcmp(v1.content, v2.content);          // String comparison

		break;
	}

	return 0;
}

// This function, thanks to the previous one, takes the head of the list, a struct an
// an integer to specify the order (INCREASING/DECREASING), then inserts the elements
// in the list in a sorted way.

node* insertOrdered(node* head, element src, int ord) {

	node* pnt = NULL;
	node* current;
	node* tmp;
	int counter = 0;

	tmp = calloc(1, sizeof(node));                      // Dinamically allocates the memory.
	if (tmp == NULL) {
		perror("There was an error while allocating the memory:");
		return NULL;
	}

	tmp->data = src;								    // Puts the data in the temporary node.

	if (head == NULL)
		return tmp;

	switch (ord) {

	case INCREASING:
		if (compare(head->data, tmp->data, NUM) < 0) {
			tmp->next = head;
			return tmp;
		}

		current = head;                                // Sorts the elements in increasing order.

		while (current->next != NULL && !counter) {
			if (compare(current->next->data, tmp->data, NUM) < 0)
				counter = 1;
			else
				current = current->next;
		}

		if (!counter) {
			current->next = tmp;
			return head;
		}
		else {
			tmp->next = current->next;
			current->next = tmp;
			return head;
		}

		break;

	case DECREASING:
		if (compare(head->data, tmp->data, NUM) > 0) {
			tmp->next = head;
			return tmp;
		}

		current = head;                                // Sorts the elements in decreasing order.

		while (current->next != NULL && !counter) {
			if (compare(current->next->data, tmp->data, NUM) > 0)
				counter = 1;
			else
				current = current->next;
		}

		if (!counter) {
			current->next = tmp;
			return head;
		}
		else {
			tmp->next = current->next;
			current->next = tmp;
			return head;
		}

		break;
	}

	return head;
}

void insertAfter(node* prevNode, element src) {
	if (prevNode == NULL) {
		perror("The given previous node cannot be NULL");
		return;
	}

	node* newNode = calloc(1, sizeof(node));

	if (newNode == NULL) {
		perror("There was a problem while allocating the memory:");
		return;
	}

	newNode->data = src;

	newNode->next = prevNode->next;

	prevNode->next = newNode;
}

// This function prints a single node data.
// Not hard-coded. Must change when needed.

void printNode(element data) {
	printf("%d\n", data.ID);
	printf("%s\n", data.content);
	printf("%c\n", data.type);
	printf("%d\n", data.qty);
	printf("%.2f\n", data.cost);
}

// This function calls the previous one in order
// to print the whole list.

void printList(node* tmp) {
	while (tmp != NULL) {
		printNode(tmp->data);
		printf("\n");
		tmp = tmp->next;
	}
}

// This function counts the number of nodes in your
// list and returns you the result.

int numberOfNodes(node* head) {
	int count = 0;
	node* current = head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

// By passing this function a variable of your choice, it checks
// if it's part of one of your nodes and returns true (1) if
// successfully finds it or false (0) if doesn't.

boolean checkNode(node* head, int x) {                  // Must change second parameter when needed.
	if (head == NULL)
		return false;

	if (head->data.ID == x)                             // Must change when needed.
		return true;

	return checkNode(head->next, x);
}

// This function deletes your list by deallocating all the memory used for it.

void deleteList(node* head) {
	node* current = head;
	node* next;

	if (checkEmpty(head) == true) {
		perror("The list is already empty.");
	}

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;
}