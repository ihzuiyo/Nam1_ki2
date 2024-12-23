#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *next;
	
} node;
main(){
	node *head = NULL;
	head = (node*)malloc(sizeof(node));
	head->data = 7;
	head->next = NULL;
	// ----------- //
	head->next = (node*)malloc(sizeof(node));
	head->next->data = 11;
	head->next->next = NULL;
	printf("\n%d",head->data);
	printf("\n%d",head->next->data);
	
}