#include<stdio.h>
#include<math.h>
#include<stdlib.h>
main(){
	int a = 5; // vi du a co dia chi 48
	int *b = &a; // b co gia tri la dia chi cua a = 48; b co dia chi la 40 (int 4 byte)
	int *p;
	p = (int*)malloc(sizeof(int)); // memory allocation, cu phap <bien> = malloc(sizeof(kieu du lieu cua p))
	printf("value of p: %p\n", p);
	printf("address of p: %p\n", &p);
	*(p+1) = a;
	printf("value of *p: %d\n", *(p+1));
	
	
	
}