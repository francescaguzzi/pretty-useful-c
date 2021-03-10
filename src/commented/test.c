#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
	
	char line[STD_LINE_DIM];
	char* token[TOKEN_ARR_MAX_DIM];
	list head;
	element src;
	FILE* fp;

	fp = openFile("./negozio.txt", "r");
	if (fp == NULL) {
		exit(-1);
	}

	head = emptyList();

	while (readLine(fp, line, STD_LINE_DIM) >= 0) {
		getTokenLine(line, " ", token);
		loadElementData(token, "%d%s%c%d%f", &src.ID, &src.content, &src.type, &src.qty, &src.cost);
		
		//head = insertHead(head, src);

		//head = insertTail(head, src);
		// insertAfter(head, src);

		head = insertOrdered(head, src, INCREASING);
	}
	
	printList(head);

	/* printf("\nThere are %d nodes in your linked list.\n", numberOfNodes(head));

	
	puts("Enter the ID of the item you want to buy.");
	int x = scanf("%d", &x);
	if (checkNode(head, x) == true) {
		puts("The item you're searching for is available.");
	}
	else {
		puts("Sorry, we couldn't find that item.");
	} */



	return closeFile(fp);
} 
