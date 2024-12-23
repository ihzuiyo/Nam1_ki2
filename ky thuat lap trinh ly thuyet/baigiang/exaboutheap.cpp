#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap(int *p){
	*p = (int*)malloc(5*sizeof(int));
	for(int i=0;i<5;i++){
		*(*p+i) = i+1;
	}
}
void in(int *p){
	for(int i=0;i<5;i++){
		printf("p[%d] = %d\n ", i, *(*p+i));
	}
}

main(){
	int *p;
	nhap(&p);
	in(p);
}