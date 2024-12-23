#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct Dangvien{
	char hoten[100];
	int namsinh;
	int namketnap;
};
void nhap(Dangvien **dv,int *n){
	char filename[] = "input.txt";
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*dv = (Dangvien*)malloc((*n)*sizeof(Dangvien));
	for(int i=0;i<*n;i++){
		fgets((*dv+i)->hoten,100,f);
		(*dv+i)->hoten[strlen((*dv+i)->hoten) -1] = '\0';
		fscanf(f,"%d ",&(*dv+i)->namsinh);
		fscanf(f,"%d ",&(*dv+i)->namketnap);
	}
	fclose(f);
}
void xuat(Dangvien *dv,int n){
	printf("- DANH SACH DANG VIEN -: \n");
	for(int i=0;i<n;i++){
		printf("HO TEN: %s - NAM SINH: %d - NAM KET NAP : %d\n",(dv+i)->hoten,(dv+i)->namsinh,(dv+i)->namketnap);
	}
}
int sapxep(const void *a,const void *b){
	Dangvien *dv1 = (Dangvien*)a;
	Dangvien *dv2 = (Dangvien*)b;
	return dv1->namketnap - dv2->namketnap;
}
void thongke(Dangvien *dv,int n){
	printf("Danh sach cac dang vien co hon 20 nam tuoi dang la: \n");
	for(int i=0;i<n;i++){
		if(2024 - (dv+i)->namketnap > 20){
			printf("HO TEN: %s - NAM SINH: %d - NAM KET NAP : %d\n",(dv+i)->hoten,(dv+i)->namsinh,(dv+i)->namketnap);
		}
	}
}
main(){
	int n;
	Dangvien *dv;
	nhap(&dv,&n);
	xuat(dv,n);
	qsort(dv,n,sizeof(Dangvien),sapxep);
	printf("Danh sach sau khi sap xep nam ket nap theo thu tu tang dan: \n");
	xuat(dv,n);
	thongke(dv,n);
}