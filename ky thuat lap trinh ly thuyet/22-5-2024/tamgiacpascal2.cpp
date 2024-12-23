#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void pascaltriangle(int ***pt,int *n){
	printf("Nhap n: ");
	scanf("%d ",n);
	*pt = (int**)malloc(*n*sizeof(int*));
	for(int i=0;i<*n;i++){
		*(*pt+i) = (int*)malloc((i+1)*sizeof(int));
		for(int j=0;j<=i;j++){
			if(j==0 || j == i){
				*(*(*pt+i)+j) = 1;
			}
			else{
				*(*(*pt+i)+j) = *(*(*pt+i-1)+j-1);
			}
		}
	}
}
void print(int **pt,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			printf("%d ",*(*(pt+i)+j));
		}
		printf("\n");
	}
}
main(){
	int **pt;
	int n;
	pascaltriangle(&pt,&n);
	print(pt,n);
}