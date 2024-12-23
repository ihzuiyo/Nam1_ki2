#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void nhap(int **a,int *n);
void xuat(int *a,int n);
void tbc(int *a,int n);
void check(int *a,int n);

main(){
	int *a;
	int n;
	nhap(&a,&n);
	xuat(a,n);
	tbc(a,n);
	check(a,n);
}
void nhap(int **a,int *n){
	char filename[100];
	printf("Nhap ten file ban muon doc:");
	scanf("%s", filename);
	FILE *f = fopen(filename, "r");
	fscanf(f, "%d " ,n);
	*a = (int*)malloc((*n)*(*n)*sizeof(int));
	for(int i=0;i<*n;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%d ",*a+i*(*n)+j);
		}
	}
}
void xuat(int *a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",*(a+i*n+j));
		}
		printf("\n");
	}
}
void tbc(int *a,int n){
	float tong=0;
	int dem=0;
	for(int i= 1 ; i< n;i++){
		for(int j=n-1; j>=n-i; j--){
			tong += *(a+i*n+j);
			dem++;
		}
	}
	if(dem == 0){
		printf("Ma tran ko co phan tu\n");
	}
	else{
		printf("TBC la: %f\n",tong/dem);
	}
}
void check(int *a,int n){
	float check=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			check += *(a+i*n+j);
		}
	}
	if(check != 0){
		printf("Ma tran da cho khong phai ma tran tam giac tren\n");
	}
	else{
		printf("Ma tran da cho la ma tran tam giac tren\n");
	}
}