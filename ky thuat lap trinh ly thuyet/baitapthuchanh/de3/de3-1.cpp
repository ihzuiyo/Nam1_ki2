#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void nhap(int **mt,int *m,int *n);
void xuat(int *mt,int m,int n);
float tbc(int *mt,int m,int n);
void tonghang(int *mt,int m,int n);
main(){
	int *mt;
	int m,n;
	nhap(&mt,&m,&n);
	printf("Tbc cua cac phan tu chia het cho 3 du 1 la: %.1f\n",tbc(mt,m,n));
	printf("Tong cua cac hang la:\n");
	tonghang(mt,m,n);
}
void nhap(int **mt,int *m,int *n){
	char filename[100];
	printf("Nhap ten file ban muon nhap: ");
	scanf("%s",&filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d%d",m,n);
	*mt = (int*)malloc((*m)*(*n)*sizeof(int));
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%d", *mt+i*(*n)+j);
		}
	}
	fclose(f);
}
void xuat(int *mt,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",*(mt+i*n+j));
		}
		printf("\n");
	}
}
float tbc(int *mt,int m,int n){
	int tong=0;
	int dem=0;
	for(int i=0;i<m*n;i++){
		if((*(mt+i) % 2 == 0) && (*(mt+i) % 3 == 1)){
			tong += *(mt+i);
			dem +=1;
		}
	}
	if(dem == 0){
		printf("Khong co phan tu chan nao chia het cho 3 du 1\n");
	}
	else{
		return tong/dem;
	}
}
void tonghang(int *mt,int m,int n){
	int tonghang[m];
	for(int i=0;i<m;i++){
			tonghang[i] = 0; 
		for(int j=0;j<n;j++){
			tonghang[i] += *(mt+i*n+j);
		}
	}
	for(int i=0;i<m;i++){
		printf("Hang %d: %d\n",i+1,tonghang[i]);
	}	
}