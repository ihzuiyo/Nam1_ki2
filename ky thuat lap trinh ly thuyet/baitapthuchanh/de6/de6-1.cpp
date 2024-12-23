#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void nhap(float **a,int *m,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",&filename);
	FILE *f = fopen(filename, "r");
	fscanf(f, "%d%d",m,n);
	*a = (float*)malloc((*m)*(*n)*sizeof(float));
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			fscanf(f, "%f",*a+i*(*n)+j);
		}
	}
	fclose(f);
}
void xuat(float *a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%.2f ",*(a+i*n+j));
		}
		printf("\n");
	}
}
void tbchangle(float *a,int m,int n){
	float s=0;
	float c=0;
	for(int i=0;i<m;i+=2){
		for(int j=0;j<n;j++){
			if(*(a+i*n+j) > 0){
				s += *(a+i*n+j);
				c++;
			}
		}
	}
	if(c == 0){
		printf("Khong co phan tu co gia tri duong thoa man dieu kien\n");
	}
	else{
		printf("TBC cac phan tu duong thuoc hang le la: %.2f\n",s/c);
	}
	
}
void timnhonhat(float *a,int m,int n){
	float min = *a;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(((*a+i*n+j) < min) && ((*a+i*n+j) > 0) || min <= 0){
				min = *(a+i*n+j);
			}
		}
	}
	if(min > 0){
		printf("Phan tu duong nho nhat cua ma tran la : %.2f\n",min);
	}
	else{
		printf("Khong co phan tu duong trong ma tran\n");
	}
}
main(){
	float *a;
	int m,n;
	nhap(&a,&m,&n);
	tbchangle(a,m,n);
	timnhonhat(a,m,n);
	printf("Ma tran thuc: \n");
	xuat(a,m,n);
}