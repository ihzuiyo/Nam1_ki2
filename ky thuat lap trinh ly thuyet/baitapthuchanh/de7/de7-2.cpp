#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct NhanVien{
	char hoten[30];
	int luong;
	int macv;
};
void nhap(NhanVien **nv, int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",&filename);

	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*nv = (NhanVien*)malloc(*n*sizeof(NhanVien));
	for(int i=0;i<*n;i++){
		fgets((*nv+i)->hoten,30,f);
		(*nv+i)->hoten[strlen((*nv+i)->hoten)-1] == '\0';
		fscanf(f,"%d ",&(*nv+i)->luong);
		fscanf(f,"%d ",&(*nv+i)->macv);
	}
	fclose(f);
}
void xuat(NhanVien *nv,int n){
	printf("So nhan vien: %d\n",n);
	for(int i=0;i < n;i++){
		printf("Ho ten: %s",(nv+i)->hoten);
		printf("Luong: %d\n",(nv+i)->luong);
		printf("Ma Cong Viec: %d\n",(nv+i)->macv);
	}
}
void sapxep(NhanVien *nv,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if((nv+i)->luong > (nv+j)->luong){
				NhanVien temp = *(nv+i);
				*(nv+i) = *(nv+j);
				*(nv+j) = temp;
			}
		}
	}
}
main(){
	NhanVien *nv;
	int n;
	nhap(&nv,&n);
	xuat(nv,n);
	printf("Danh sach sau khi sap xep: \n");
	sapxep(nv,n);
	xuat(nv,n);	
}