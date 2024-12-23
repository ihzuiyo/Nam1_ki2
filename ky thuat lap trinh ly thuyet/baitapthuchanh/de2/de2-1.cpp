#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void read_input(int **a,int *m,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",filename);
	FILE *f = fopen(filename,"r");
	fscanf(f,"%d %d",m,n);
	*a = (int*)malloc((*m)*(*n)*sizeof(int));
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%d ",(*a+i**n+j));
		}
	}
	fclose(f);
}
void sumlargerthanaverage(int *a,int m,int n){
	int sum = 0;
	for(int i=0;i<m*n;i++){
		sum += *(a+i);
	}
	float avg = sum/(m*n);
	float sumlargerthanavg=0;
	int check = 0;
	for(int i=0;i<m*n;i++){
		if(*(a+i) > avg){
			sumlargerthanavg += *(a+i);
			check = 1;
		}
	}
	if(check = 0){
		printf("Khong co phan tu nao lon hon gia tri tb\n");
	}
	else{
		printf("Tong cac ptu lon hon gttb la: %.2f\n",sumlargerthanavg);
	}
}
void findminlargest(int *a,int m,int n){
	int max = *a;
	for(int i=0;i<m*n;i++){
		if(*(a+i) > max && *(a+i) < 0 || max >= 0){
			max = *(a+i);
		}
	}
	if(max >= 0){
		printf("Khong co phan tu am trong ma tran\n");
	}
	else{
		printf("Phan tu am co gia tri lon nhat la: %d",max);
	}
}
main(){
	int *a;
	int m,n;
	read_input(&a,&m,&n);
	sumlargerthanaverage(a,m,n);
	findminlargest(a,m,n);
}