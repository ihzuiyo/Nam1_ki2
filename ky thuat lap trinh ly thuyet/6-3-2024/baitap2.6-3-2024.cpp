#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
// a)
void nhapmatran(int *n,int **a){
	printf("\nNhap co cua ma tran vuong: ");
	scanf("%d",n);
	*a = (int*)malloc((*n)*(*n)*sizeof(int));
	for(int i=0;i<(*n);i++){
		for(int j=0;j<(*n);j++){
			printf("\nNhap a[%d][%d]: ",i,j);
			scanf("%d", *a+i*(*n)+j);
		}
	}
}
void inmatran(int *n,int **a){
	for(int i=0;i<(*n);i++){
		printf("\n");
		for(int j=0;j<(*n);j++){
			printf("%d ",*(*a+i*(*n)+j));
		}
	}
}
// b)
void tbcduongcheochinh(int *n,int **a){
	int sumcc=0;
	printf("\nCac phan tu tren duong cheo chinh la: ");
	for(int i=0;i<(*n);i++){
		sumcc += *(*a+i*(*n)+i);
	}
	float tbc =(float) sumcc / (*n);
	printf("\nTBC = %.2f",tbc);
}

//c)


main(){
	int n;
	int *a;
	int sumb=0;
	nhapmatran(&n,&a);
	inmatran(&n,&a);
	tbcduongcheochinh(&n,&a);
}