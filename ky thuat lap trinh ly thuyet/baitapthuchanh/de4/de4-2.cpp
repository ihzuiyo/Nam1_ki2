#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct SV{
	char hoten[100];
	char quequan[100];
	char hocluc;
};
void nhap(SV **sv,int *n){
	char filename[] = "de4bai2.txt";
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d",n);
	*sv = (SV*)malloc(*n*sizeof(SV));
	for(int i=0;i<*n;i++){
		fgetc(f);
		fgets((*sv+i)->hoten,100,f);
		(*sv+i)->hoten[strlen((*sv+i)->hoten) - 1] = '\0';
		fgets((*sv+i)->quequan,100,f);
		(*sv+i)->quequan[strlen((*sv+i)->quequan)-1] = '\0';
		fscanf(f, "%c",&(*sv+i)->hocluc);
	}
	fclose(f);
}
void xuat(SV *sv,int n){
	for(int i=0;i<n;i++){
		printf("Ho ten sinh vien:");
		printf("%s\n",(sv+i)->hoten);
		printf("Que quan: ");
		printf("%s\n",(sv+i)->quequan);
		printf("Hoc luc: ");
		printf("%c\n",(sv+i)->hocluc);
	}
}
void thongke(SV *sv,int n){
	int count[3]={0};
	for(int i=0;i<n;i++){
		count[(sv+i)->hocluc-'A']++;
	}
	for(int i = 0; i < n; i++){
		printf("So sinh vien truong %c la: %d\n", 'A'+i, count[i]);
	}
}
void tim(SV *sv,int n){
	char timkiem[100];
	printf("Nhap ten sv can tim: ");
	fgets(timkiem,100,stdin);
	timkiem[strlen(timkiem)-1] = '\0';
	for(int i=0;i<n;i++){
		if(strcmp(timkiem , (sv+i)->hoten) == 0){
			printf("Ho ten sinh vien:");
			printf("%s \n",(sv+i)->hoten);
			printf("Que quan: ");
			printf("%s \n",(sv+i)->quequan);
			printf("Hoc luc: ");
			printf("%c \n",(sv+i)->hocluc);
			return;
		}
	}
	printf("Khong tim thay sinh vien can tim\n");
}
main(){
	int n;
	SV *sv;
	nhap(&sv,&n);
	xuat(sv,n);
	thongke(sv,n);
	tim(sv,n);
}
