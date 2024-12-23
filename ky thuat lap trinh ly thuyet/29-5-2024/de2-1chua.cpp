#include<stdio.h>
#include<stdlib.h>
// a[i][j] = *(a+i*n+j)
void input(float **a,int *m,int *n){
	char filename[30];
	printf("Nhap ten file: ");
	scanf("%s",&filename);
	FILE *f = fopen(filename , "r");
	fscanf(f, "%d %d",m,n);
	*a = (float*)malloc((*m)*(*n)*sizeof(float));
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%f", *a+i*(*n)+j);
		}
	}
	fclose(f);
}
void output(float *a,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%f ",*(a+i*n+j));
		}
		printf("\n");
	}
	
}
void cau1(float *a,int m,int n){
	float S=0;
	for(int i=0;i<m*n;i++){
		S += *(a+i); 
	}
	float tbc = S/(m*n);
	S=0;
	int check = 0;
	for(int i=0;i<m*n;i++){
		if(*(a+i) > tbc){
			S+= *(a+i);	
			check = 1; 
		}
	}
	if(check == 0){
		printf("Khong co pt nao lon hon tbc");
	}
	else{
		printf("Tong cac phan tu lon hon tbc la: %.2f",S);
	}
	
}
void cau2(float *a,int m,int n){
	float max = *a;
	for(int i=0;i<m*n;i++){
		if((*(a+i) > max && *(a+i) < 0) || max >=0){
			max = *(a+i);
		}
	}
	if(max < 0){
		printf("Phan tu am lon nhat: %.2f\n",max);
	}
	else{
		printf("Khong co phan tu am trong ma tran\n");
	}
}
 
main(){
	float *a;
	int m,n;
	input(&a,&m,&n);
	output(a,m,n);
	cau1(a,m,n);
	cau2(a,m,n);
}