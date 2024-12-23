#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void nhap(float **mt,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f, "%d",n);
	*mt = (float*)malloc(*n**n*sizeof(float));
	for(int i=0;i<*n;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%f",*mt+i**n+j);
		}
	}
	fclose(f);
}
void xuat(float *mt,int n){
	printf("Ma tran da cho: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%.1f ",*(mt+i*n+j));
		}
		printf("\n");
	}
}
void tbccheophu(float *mt,int n){
	float s=0;
	int c=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i + j > n - 1){
				s += *(mt+i*n+j);
				c += 1;
			}
		}
	}
	printf("TBC cac so nam duoi duong cheo phu la: %.2f \n",s/c);
}
void matranthua(float *mt,int n){
	float count=0;
	for(int i=0;i<n*n;i++){
		if(*(mt+i) == 0){
			count += 1;
		}
	}
	float sosanh = count/(n*n);
	printf("So sanh = %.2f voi count = %.2f\n",sosanh,count);
	if(sosanh >= 0.6){
		printf("Ma tran da cho la ma tran thua\n");
	}
	else{
		printf("Ma tran da cho ko phai ma tran thua\n");
	}
}
main(){
	int n;
	float *mt;
	nhap(&mt,&n);
	xuat(mt,n);
	tbccheophu(mt,n);
	matranthua(mt,n);
}