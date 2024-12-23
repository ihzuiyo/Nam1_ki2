#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char hoten[100];
	char quequan[100];
	char hocluc;
}Sinhvien;
void nhap(Sinhvien **sv,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*sv = (Sinhvien*)malloc(*n*sizeof(Sinhvien));
	for(int i=0;i<*n;i++){
		fgets((*sv+i)->hoten,100,f);
		(*sv+i)->hoten[strlen((*sv+i)->hoten) - 1] = '\0';
		fgets((*sv+i)->quequan,100,f);
		(*sv+i)->quequan[strlen((*sv+i)->quequan) - 1] = '\0';
		fscanf(f,"%c ",&(*sv+i)->hocluc);
	}
	fclose(f);
}
void xuat(Sinhvien *sv,int n){
	for(int i=0;i<n;i++){
		printf("%d)\n",i+1);
		printf("Ho ten: %s \n",(sv+i)->hoten);
		printf("Que quan: %s \n",(sv+i)->quequan);
		printf("Hoc luc:  %c\n",(sv+i)->hocluc);
	}
}
void timsinhvien(Sinhvien *sv,int n){
	fflush(stdin);
	char timsinhvien[100];
	printf("\nNhap ten sinh vien can tim: ");
	fgets(timsinhvien,100,stdin);
	timsinhvien[strlen(timsinhvien) - 1] = '\0';
	for(int i=0;i<n;i++){
		if(strcmp(timsinhvien,(sv+i)->hoten) == 0){
			printf("Ho ten: %s \n",(sv+i)->hoten);
			printf("Que quan: %s \n",(sv+i)->quequan);
			printf("Hoc luc:  %c\n",(sv+i)->hocluc);
			return;
		}
	}
	printf("\nKhong co hoc sinh nao ten %s\n",timsinhvien);
}
main(){
	int n;
	Sinhvien *sv;
	nhap(&sv,&n);
	xuat(sv,n);
	timsinhvien(sv,n);
}