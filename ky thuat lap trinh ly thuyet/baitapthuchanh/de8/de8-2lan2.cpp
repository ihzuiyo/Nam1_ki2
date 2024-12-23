#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char hoten[100];
	int namsinh;
	int namketnap;
}DangVien;
void input(DangVien **dv,int *n){
	char filename[] = "input8-2.txt";
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*dv = (DangVien*)malloc(*n*sizeof(DangVien));
	for(int i=0;i<*n;i++){
		fgets((*dv+i)->hoten,100,f);
		(*dv+i)->hoten[strlen((*dv+i)->hoten) - 1] = '\0';
		fscanf(f,"%d ",&(*dv+i)->namsinh);
		fscanf(f,"%d ",&(*dv+i)->namketnap);
	}
	fclose(f);
}
void output(DangVien *dv,int n){
	printf("DANH SACH DANG VIEN: \n");
	for(int i=0;i<n;i++){
		printf("HO TEN: %s \n",(dv+i)->hoten);
		printf("NAM SINH: %d \n",(dv+i)->namsinh);
		printf("NAM KET NAP: %d \n",(dv+i)->namketnap);
	}
}
int cmp(const void *a,const void *b){
	DangVien *dv1 = (DangVien*)a;
	DangVien *dv2 = (DangVien*)b;
	return dv1->namketnap - dv2->namketnap;
}
void thongke20tuoidang(DangVien *dv,int n){
	printf("--------- DANH SACH DANG VIEN CO 20 NAM TUOI DANG TRO LEN ---------------\n");
	for(int i=0;i<n;i++){
		if((2024 - (dv+i)->namketnap) >= 20){
			printf("HO TEN: %s \n",(dv+i)->hoten);
			printf("NAM SINH: %d \n",(dv+i)->namsinh);
			printf("NAM KET NAP: %d \n",(dv+i)->namketnap);
		}
	}
}
void read_file(DangVien *dv,int n){
	FILE *f = fopen("output8-2.txt","w");
	for(int i=0;i<n;i++){
		if((2024 - (dv+i)->namketnap) >= 20){
			fprintf(f,"HO TEN: %s \n",(dv+i)->hoten);
			fprintf(f,"NAM SINH: %d \n",(dv+i)->namsinh);
			fprintf(f,"NAM KET NAP: %d \n",(dv+i)->namketnap);
		}
	}
	fclose(f);
}
main(){
	int n;
	DangVien *dv;
	input(&dv,&n);
	output(dv,n);
	qsort(dv,n,sizeof(DangVien),cmp);
	printf("-------------DANH SACH DANG VIEN KHI SAP XEP TANG DAN THEO NAM KET NAP---------------------- \n");
	output(dv,n);
	thongke20tuoidang(dv,n);
	read_file(dv,n);
}