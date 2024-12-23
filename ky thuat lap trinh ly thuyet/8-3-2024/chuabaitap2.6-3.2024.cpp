#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap(int **a,int *n);
void in(const int *a,int n);
float tbc(const int *a,int n);
int ptcln(const int *a,int n);
int kiemtratgd(const int *a,int n);


int main(){
	int *a;
	int n;
	nhap(&a,&n);
	in(a,n);
//	printf("TBC = %.1f\n",tbc(a,n));
//	int tmp = ptcln(a,n);
//	if(tmp % 2==0){
//		printf("Phan tu chan lon nhat: %d\n",tmp);
//	}
//	else{
//		printf("Khong co phan tu chan nao\n");
//	}
//	if(kiemtratgd(a,n) ==1){
//		printf("Ma tran tam giac duoi\n");
//	}
//	else{
//		printf("Khong phai ma tran tam giac duoi\n");
//	}
}

void nhap(int **a,int *n){
	printf("Nhap n:");
	scanf("%d", n); //dia chi cua n (*n)
	int m = *n;
	*a = (int*)malloc(m*m*sizeof(int));
	for(int i=0; i<m ;i++){
		for(int j=0; j<m; j++){
			printf("Nhap a[%d][%d]: ",i,j);
			scanf("%d", *a+i*m+j);
		}
	}
};
void in(int *a,int n){
	for(int i=0; i<n;i++){
		printf("\n");
		for(int j=0; j < n ;j++){
			printf("%6d", *(a+i*n+j));
		}
	}
}
