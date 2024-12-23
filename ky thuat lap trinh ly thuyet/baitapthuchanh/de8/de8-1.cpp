#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void nhap(int **mt,int *m,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",&filename);
	if(filename == NULL){
		printf("ERROR");
		return;
	}
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d%d",m,n);
	*mt = (int*)malloc((*m)*(*n)*sizeof(int));
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%d",(*mt+i*(*n)+j));
		}
	}
	fclose(f);
}
void in(int *mt,int m,int n){
	printf("MA TRAN: \n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",*(mt+i*n+j));
		}
		printf("\n");
	}
}
void tbcsochanchia3du1(int *mt,int m,int n){
	int tong=0;
	int dem=0;
	for(int i=0;i<m*n;i++){
		if((*(mt+i) % 3 == 1) && (*(mt+i) % 2 == 0)){
			tong+= *(mt+i);
			dem +=1;
		}
	}
	if(dem == 0){
		printf("Khong co phan tu chan nao chia het cho 3 du 1\n");
	}
	else{
		printf("TBC so chan chia 3 du 1 la: %.2f",tong/dem);
	}
}
void tonghang(int *mt,int m,int n){
	int tong[m];
	for(int i=0;i<m;i++){
		tong[i] = 0;
		for(int j=0;j<n;j++){
			tong[i] += *(mt+i*n+j);
		}
	}
	for(int i=0;i<m;i++){
		printf("Tong cua hang %d la: %d\n",i+1,tong[i]);
	}
}
void printf_file(int *mt,int m,int n){
	FILE *f = fopen("tepvanban1.txt", "w");
	fprintf(f,"Ma tran ban vua nhap vao la: \n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			fprintf(f,"%d\t",*(mt+i*n+j));
		}
		fprintf(f,"\n");
	}
	fclose(f);
}
main(){
	int m,n;
	int *mt;
	nhap(&mt,&m,&n);
	in(mt,m,n);
	tbcsochanchia3du1(mt,m,n);
	tonghang(mt,m,n);
	printf_file(mt,m,n);
}