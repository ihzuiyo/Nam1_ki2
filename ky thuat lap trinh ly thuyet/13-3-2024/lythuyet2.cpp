#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct node{
	int data;
	node *next;
	
} node;

void insert(node **head,int data){
	node *tmp = *head;
	if(*head == NULL){
		*head = (node*)malloc(sizeof(node));
		(*head)->data = data;
		(*head)->next = NULL;
	}
	else{
		while(tmp->next != NULL){
		tmp = tmp->next;
		}
		tmp->next = (node*)malloc(sizeof(node));
		tmp->next->data = data;
		tmp->next->next = NULL;
	}
	
}
void print(node *head){
	node *tmp = head;
	while(tmp != NULL){
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}
}
void deleteLast(node **head){
	node *tmp = *head;
	if(*head == NULL){
		return; //stop function
	}
	if((*head)->next == NULL){
		free(*head);
		*head = NULL;
		return;
	} 
	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}
	free(tmp->next);
	tmp->next = NULL;
	
}


main(){
	node *head = NULL;
	insert(&head,3);
	insert(&head,7);
	insert(&head,4);
	insert(&head,5);
	insert(&head,9);
	print(head);
	printf("\nAfter delete:\n");
	deleteLast(&head);
	print(head);
}