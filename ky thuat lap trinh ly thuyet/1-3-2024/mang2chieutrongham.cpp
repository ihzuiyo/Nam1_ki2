#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//Mảng 2 chiều (con trỏ)
void nhap(int **p,int *m,int *n){
	*p = (int*)malloc((*m)*(*n)*sizeof(int));  
	scanf("%d %d", m, n);
	for(int i=0;i<(*m);i++){
		for(int j=0;j<(*n);j++){
			printf("Nhap a[%d][%d]: ",i,j);
			scanf("%d ", *p+i*(*n)+j); // mảng tĩnh &a[i*n+j]
		}
	}
}


main(){
	int m,n;
	int *a;  			// mảng tĩnh : a[50][50]
	nhap(&a,&m,&n);
	for(int i=0;i < m;i++){
		for(int j=0;j < n;j++){
			printf("%d ", *(a+i*n+j));
		}
		printf("\n");
	}
	
}