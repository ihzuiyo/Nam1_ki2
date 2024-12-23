#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap(int **a,int *n);
void in(int *a,int n);

main(){
	int *a,n;
	nhap (&a,&n); //truyen vao dia chi cua a va dia chi cua n
	in(a,n);
	// lien quan den mang la dung con tro
	
}
void nhap(int **a,int *n){
	printf("Nhap so luong phan tu: ");
	scanf("%d",n);
	*a  = (int*)malloc((*n)*sizeof(int));
	 // lay gia tri cua n thi phai *n
	 
	for(int i=0;i<(*n);i++){
		printf("Nhap a[%d]:",i);
		scanf("%d",*a+i); //address
	}
}
void in(int *a,int n){
	for(int i=0; i<n ; i++){
		printf("%d ",*(a+i)); //value
	}
}