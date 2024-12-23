#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void nhap(int **mt,int *m,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d %d",m,n);
	*mt = (int*)malloc(*m**n*sizeof(int));
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%d ",*mt+i**n+j);
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
void tbcchanchia3du1(int *mt,int m,int n){
	int sum = 0;
	int count = 0;
	for(int i=0;i<m*n;i++){
		if(*(mt+i) % 3 == 1 && *(mt+i) % 2 == 0){
			sum += *(mt+i);
			count += 1;
		}
	}
	printf("\nSUM = %d COUNT = %d",sum,count);
	float tbc = (float)sum/count;
	printf("\nTBC cac so chan chia het cho 3 du 1 la: %.2f",tbc);
}
void tongtunghang(int *mt,int m,int n){
	int tong[m];
	for(int i=0;i<m;i++){
		tong[i] = 0;
		for(int j=0;j<n;j++){
			tong[i] += *(mt+i*n+j);
		}
	}
	for(int i=0;i<m;i++){
		printf("\nTong cua hang %d la: %d",i+1,tong[i]);
	}
}
main(){
	int *mt,m,n;
	nhap(&mt,&m,&n);
	xuat(mt,m,n);
	tbcchanchia3du1(mt,m,n);
	tongtunghang(mt,m,n);
}