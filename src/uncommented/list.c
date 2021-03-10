#define _CRT_SECURE_NO_WARNINGS

// Guzzi Francesca 0000969922
// Fondamenti di Informatica T-1 Modulo 2
// 21/01/21


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


node* emptyList() {
	return NULL;
}

boolean checkEmpty(node* head) {
	return (head == NULL);
}

node* insertHead(list head, element src) {             
														
	list tmp;                                           

	tmp = (list)malloc(sizeof(node));                   

	if (tmp == NULL) {                                  .
		return NULL;
	}
	else {
		tmp->data = src;                                
		tmp->next = head;                               
	}
	return tmp;
}

node* insertTail(list head, element src) {              
														
	list tmp, pnt;                                      

	tmp = calloc(1, sizeof(node));                      

	if (tmp == NULL) {
		return NULL;                                    
	}
	if (head == NULL) {
		head = tmp;                                     

	else {                                              
		pnt = head;                                     
		while (pnt->next != NULL)
			pnt = pnt->next;

		pnt->next = tmp;
	}

	tmp->data = src;                                    
	return head;
}

/* int compare(element v1, element v2, int type) {

	switch (type) {
	case NUM:                                           
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
		return strcmp(v1.content, v2.content);          

		break;
	}

	return 0;
} */

/* node* insertOrdered(node* head, element src, int ord) {

	node* pnt = NULL;
	node* current;
	node* tmp;
	int counter = 0;

	tmp = calloc(1, sizeof(node));                      
	if (tmp == NULL) {
		perror("There was an error while allocating the memory:");
		return NULL;
	}

	tmp->data = src;								   

	if (head == NULL)
		return tmp;

	switch (ord) {

	case INCREASING:
		if (compare(head->data, tmp->data, NUM) < 0) {
			tmp->next = head;
			return tmp;
		}

		current = head;                               

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

		current = head;                               

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
} */

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

/* void printNode(element data) {
	printf("%d\n", data.ID);
	printf("%s\n", data.content);
	printf("%c\n", data.type);
	printf("%d\n", data.qty);
	printf("%.2f\n", data.cost);
} */

/* void printList(node* tmp) {
	while (tmp != NULL) {
		printNode(tmp->data);
		printf("\n");
		tmp = tmp->next;
	}
} */

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

boolean checkNode(node* head, int x) {                  
	if (head == NULL)
		return false;

	if (head->data.ID == x)                             
		return true;

	return checkNode(head->next, x);
}

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