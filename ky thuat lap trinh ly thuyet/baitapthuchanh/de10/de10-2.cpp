#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char hoten[100];
	float diem;
	char truong;
}Thisinh;
void nhap(Thisinh **sv,int *n){
	char filename[] = "inputde10bai2.txt";
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*sv = (Thisinh*)malloc(*n*sizeof(Thisinh));
	for(int i=0;i<*n;i++){
		fgets((*sv+i)->hoten, 100, f);
		(*sv+i)->hoten[strlen((*sv+i)->hoten) - 1] = '\0';
		fscanf(f, "%f ",&(*sv+i)->diem);
		fscanf(f, "%c ",&(*sv+i)->truong);
	}
	fclose(f);
}
void xuat(Thisinh *sv,int n){
	for(int i=0;i<n;i++){
		printf("Ho ten:%s  Diem:%.1f \t Truong:%c\n",(sv+i)->hoten,(sv+i)->diem,(sv+i)->truong);
	}
}
//void xuat(Thisinh *sv,int n){
//	for(int i=0;i<n;i++){
//		printf("Ho ten:%s  ",(sv+i)->hoten);
//		printf("\nDiem: %.1f ",(sv+i)->diem);
//		printf("\nTruong: %c\n",(sv+i)->truong);
//	}
//}
void tongdiemcactruong(Thisinh *sv,int n){
	float tong[4]= {0,0,0,0};
	for(int i=0;i<n;i++){
			tong[(sv+i)->truong - 'A'] += (sv+i)->diem;
	}
	float max = -1;
	for(int i=0;i<4;i++){
		if(tong[i] > max){
			max = tong[i];
		}
	}
	for(int i=0;i<4;i++){
		printf("Tong diem cua truong %c la: %.1f\n",'A'+i,tong[i]);
	}
	for(int i=0;i<4;i++){
		if(tong[i] == max){
			printf("Truong co tong diem cao nhat la: %c\n",'A' + i);
			printf("Co so diem la: %.2f",tong[i]);
			break;
		}
	}
}
void thisinhcaonhat(Thisinh *sv,int n){
	float max = -1;
	for(int i=0;i<n;i++){
		if((sv+i)->diem > max){
			max = (sv+i)->diem;
		}
	}
	printf("\nCac sinh vien co so diem cao nhat la: \n");
	for(int i=0;i<n;i++){
		if((sv+i)->diem == max){
			printf("Ho ten:%s  Diem:%.1f \t Truong:%c\n",(sv+i)->hoten,(sv+i)->diem,(sv+i)->truong);
		}
	}
}
main(){
	int n;
	Thisinh *sv;
	nhap(&sv,&n);
	xuat(sv,n);
	tongdiemcactruong(sv,n);
	thisinhcaonhat(sv,n);
}