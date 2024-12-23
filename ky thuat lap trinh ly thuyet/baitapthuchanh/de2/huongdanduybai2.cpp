#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
// Dạng ma trận
// *(mt+i) là GIÁ TRỊ (VÍ DỤ NHƯ LÀ 1 2 3 4 5 6 7 8 9...)
// (*mt+i) là ĐỊA CHỈ ĐỂ CHỈ CÁI SỐ 1 2 3 4 5 6 7 8... NẰM Ở ĐÂU TRONG BỘ NHỚ
void nhap(float **mt,int *m,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f ,"%d%d",m,n);
	*mt = (float*)malloc((*m)*(*n)*sizeof(float));
	for(int i=0;i<*m;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%f",(*mt+i*(*n)+j)); //vị trí phần tử của ma trận
		}
	}
	fclose(f);
}
void xuat(float *mt,int m,int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%.2f ",*(mt+i*n+j));
		}
		printf("\n");
	}
}
void timgiatrilonhontbc(float *mt,int m,int n){ 
	float tongmatran = 0;
	for(int i=0;i<m*n;i++){
		tongmatran += *(mt+i);
	}
	float tbc = tongmatran/(m*n);
	float tonggiatrilonhontbc = 0;
	for(int i=0;i<m*n;i++){
		if(*(mt+i) > tbc){
			tonggiatrilonhontbc += *(mt+i); //giá trị nào lớn hơn TBC thì cộng nó vào cái biến này
		}
	}
	printf("Tong cac gia tri lon hon TBC la: %.2f\n",tonggiatrilonhontbc);
}
void timgiatriamlonnhat(float *mt,int m,int n){
	float max = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(*(mt+i*n+j) < 0){
				max = *(mt+i*n+j);
				break;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(*(mt+i*n+j) > max && *(mt+i*n+j) < 0){
				max = *(mt+i*n+j);
			}
		}
	}
	printf("Max am: %.2f\n",max);
}
main(){
	int m,n;
	float *mt;
	nhap(&mt,&m,&n);
	xuat(mt,m,n);
	timgiatrilonhontbc(mt,m,n);
	timgiatriamlonnhat(mt,m,n);	
}
