#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("*p = %d , *q = %d\n", *a, *b);
}
main(){
	int *p;
	int *q;
	p = (int*)malloc(sizeof(int));
	q = (int*)malloc(sizeof(int));
	*p = 5;
	*q = 10;
	swap(p,q);
}