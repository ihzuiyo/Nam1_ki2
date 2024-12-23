#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct NhanVien{
	char hoten[100];
	int luong;
	int macongviec;
};
void nhap(NhanVien **nv,int *n){
	char filename[100];
	printf("Nhap ten danh sach: ");
	scanf("%s",&filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*nv = (NhanVien*)malloc(*n*sizeof(NhanVien));
	for(int i=0;i<*n;i++){
		fgets((*nv+i)->hoten,100,f);
		(*nv+i)->hoten[strlen((*nv+i)->hoten) - 1] = '\0';
		fscanf(f, "%d ",&(*nv+i)->luong);
		fscanf(f,"%d ", &(*nv+i)->macongviec);
	}
	fclose(f);
}
void xuat(NhanVien *nv,int n){
	printf("DANH SACH NHAN VIEN: \n");
	printf("SO NHAN VIEN: %d\n",n);
	for(int i=0;i<n;i++){
		printf("HO TEN: %s - LUONG: %d - MA CONG VIEC: %d\n",(nv+i)->hoten,(nv+i)->luong,(nv+i)->macongviec);
	}
}
void trungbinhtheomacongviec(NhanVien *nv,int n){
	float tong[3] = {0};
	int count[3] = {0};
	for(int i=0;i<n;i++){
		if((nv+i)->macongviec == 1){
			tong[0] += (nv+i)->luong;
			count[0] +=1;
		}
		else if((nv+i)->macongviec == 2){
			tong[1] += (nv+i)->luong;
			count[1] +=1;
		}
		else if((nv+i)->macongviec == 3){
			tong[2] += (nv+i)->luong;
			count[2] +=1;
		}
	}
	printf("Trung binh luong cua nhan vien co ma cong viec 1 la: %.2f\n",tong[0]/count[0]);
	printf("Trung binh luong cua nhan vien co ma cong viec 2 la: %.2f\n",tong[1]/count[1]);
	printf("Trung binh luong cua nhan vien co ma cong viec 3 la: %.2f\n",tong[2]/count[2]);
}
main(){
	int n;
	NhanVien *nv;
	nhap(&nv,&n);
	trungbinhtheomacongviec(nv,n);
	xuat(nv,n);
	
}