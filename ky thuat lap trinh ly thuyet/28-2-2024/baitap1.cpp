#include<stdio.h>
#include<math.h>
void nhap(int **a,int *n);
void xuat(int *a,int n);
float tbc(int *a,int n,int k,float avg);
float dathuc(int *a,int n,float tongdathuc);
main(){
	//a)
	int n;
	int *a;
	nhap(&a,&n);
	xuat(a,n);
	//b)
	float avg;
	int k;
	printf("\nTBC cua cac so chia het cho k = %.2f",tbc(a,n,k,avg));
	// c)
	float tongdathuc;
	printf("\nTong cua da thuc a(n-1) / a(n) la: %.2f",dathuc(a,n,tongdathuc)); // Chua lam duoc
	
}
// a)
void nhap(int **a,int *n){
	printf("Nhap so luong phan tu:");
	scanf("%d",n);
	*a = (int*)malloc((*n)*sizeof(int));
	for(int i=0;i<(*n);i++){
		printf("\nNhap phan tu a[%d]:",i);
		scanf("%d",*a+i);
	}
	
}
void xuat(int *a,int n){
	for(int i=0;i<n;i++){
		printf("\n%d ",*(a+i));
	}
}
// b)
float tbc(int *a,int n,int k,float avg){
	int sum = 0;
	int count = 0;
	printf("\nNhap gia tri k:");
	scanf("%d",&k);
	for(int i=0;i<n;i++){
		if(*(a+i) % k == 0){
			sum += *(a+i);
			count++;
		}
	}
	avg = (float)sum/count;
	return avg;

}
// c)
float dathuc(int *a,int n,float tongdathuc){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n-1;j++){
			tongdathuc +=*(a+i) / *(a+j);
		}
	}
	return tongdathuc;
}

