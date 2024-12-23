#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char hoten[50];
	char quequan[50];
	char hocluc;
}Sinhvien;
void nhap(Sinhvien **sv,int *n){
	FILE *f = fopen("inputde9bai2.txt","r");
	fscanf(f,"%d ",n);
	*sv = (Sinhvien*)malloc(*n*sizeof(Sinhvien));
	for(int i=0;i<*n;i++){
		fgets((*sv+i)->hoten,50,f);
		(*sv+i)->hoten[strlen((*sv+i)->hoten) - 1] = '\0';
		fgets((*sv+i)->quequan,50,f);
		(*sv+i)->quequan[strlen((*sv+i)->quequan) - 1] = '\0';
		fscanf(f,"%c ",&(*sv+i)->hocluc);
	}
	fclose(f);
	printf("\n");
}
void xuat(Sinhvien *sv,int n){
	printf("DANH SACH SINH VIEN: \n");
	for(int i=0;i<n;i++){
		printf("Ho ten: %s - Que quan: %s - Hoc Luc: %c\n",(sv+i)->hoten,(sv+i)->quequan,(sv+i)->hocluc);
	}
}
void findstudent(Sinhvien *sv,int n){
	char findstudent[50];
	printf("Nhap ten sinh vien can tim: ");
	fgets(findstudent,50,stdin);
	findstudent[strlen(findstudent)-1] = '\0';
	for(int i=0;i<n;i++){
		if(strcmp(findstudent,(sv+i)->hoten) == 0){
			printf("Ho ten: %s - Que quan: %s - Hoc Luc: %c\n",(sv+i)->hoten,(sv+i)->quequan,(sv+i)->hocluc);
			return;
		}
	}
	printf("Khong tim thay sinh vien co ten %s\n",findstudent);
}
main(){
	int n;
	Sinhvien *sv;
	nhap(&sv,&n);
//	printf("Test: %s - %s - %c\n",(sv+3)->hoten,(sv+3)->quequan,(sv+3)->hocluc);
	xuat(sv,n);
	findstudent(sv,n);
}
