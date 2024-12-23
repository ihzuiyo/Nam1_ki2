#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void nhap(int **mt,int *n){
	char filename[50];
	printf("Nhap ten file: ");
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*mt = (int*)malloc(*n**n*sizeof(int));
	for(int i=0;i<*n;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%d ",(*mt+i*(*n)+j));
		}
	}
	fclose(f);
}
void tbc(int *mt,int n){
	float sum=0;
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i + j > n - 1){
				sum += *(mt+i*n+j);
				count += 1;
			}
		}
	}
	printf("TBC cac phan tu nam ben duoi duong cheo phu la: %.2f\n",sum/count);
}
void mtthua(int *mt,int n){
	float c = 0;
	for(int i=0;i<n*n;i++){
		if(*(mt+i) == 0){
			c += 1;
		}
	}
	float kq = c/(n*n);
	if(kq*100 < 60){
		printf("Ma tran tren khong phai la ma tran thua\n");
	}
	else{
		printf("Ma tran tren ma tran thua\n");
	}
}
main(){
	int *mt,n;
	nhap(&mt,&n);
	tbc(mt,n);
	mtthua(mt,n);
}