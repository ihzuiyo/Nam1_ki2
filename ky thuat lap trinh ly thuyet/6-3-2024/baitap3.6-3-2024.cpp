#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
typedef struct sinhvien{
	char hoten[100];
	int sodiem;
	char tentruong;
};
// a)
void nhapsosinhvien(int n){
	sinhvien sv[n+1];
	for(int i=0;i<n;i++){
		printf("\nNhap ho ten sinh vien thu %d: ",i);
		fflush(stdin);
		gets(sv[i].hoten);
		printf("\nNhap so diem cua sinh vien thu %d: ",i);
		scanf("%d",&sv[i].sodiem);
		printf("\nNhap ten truong cua sinh vien thu %d: ",i);
		fflush(stdin);
		scanf("%c",&sv[i].tentruong);
	}
}
void insosinhvien(int n){
	sinhvien sv[n+1];
	for(int i=0;i<n;i++){
		printf("\n%s\t%d\t%c",sv[i].hoten,sv[i].sodiem,sv[i].tentruong);
	}
}
//b)
//void truongcotongdiemcaonhat(int n){
//	sinhvien sv[n+1];
//	int sumA=0;
//	int sumB=0;
//	int sumC=0;
	//for(int i=0;i<n;i++){
		
	//}
//}
main(){
	int n;
	scanf("%d",&n);
	sinhvien sv[n+1];
	nhapsosinhvien(n);
	insosinhvien(n);
	
}