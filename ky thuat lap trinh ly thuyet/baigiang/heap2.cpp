#include<stdio.h>
#include<stdlib.h>
main(){
	int *p;
	int *q;
	p = (int*)malloc(sizeof(int));
	q = (int*)malloc(sizeof(int));// cap bo nho
	*p = 5; *q=10;
	int tmp = *p;
	*p = *q;
	*q = tmp;
	free(p); // free neu ko dung nua
	p = (int*)malloc(sizeof(int)); //tim bo nho 4 byte trong heap
	
}