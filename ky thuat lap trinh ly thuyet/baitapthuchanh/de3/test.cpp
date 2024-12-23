#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void nhap(int **a,int *n);
void xuat(int *a,int n);
float tbc(int *a,int n);
void check(int *a,int n);

main(){
	FILE *in;
	int *a;
	int n;
	nhap(&a,&n);
	xuat(a,n);
	check(a,n);
}
void nhap(FILE **file, int **a,int *n){
	char filename[100];
	printf("Nhap ten file ban muon doc:");
	scanf("%s", filename);
	FILE *file = fopen(filename, "r");
	fscanf(f, "%d" ,n);
	*a = (int*)malloc((*n)*(*n)*sizeof(int));
	for(int i=0;i<*n;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%d",*a+i*(*n)+j);
		}
	}
	fclose(f);
}
void xuat(int *a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",*(a+i*n+j));
		}
		printf("\n");
	}
}
//float tbc(float *a,int n){
//	float tong;
//	int dem;
//	for(int i= ; i<n;i++){
//		for(int j=n;)
//	}
//}
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