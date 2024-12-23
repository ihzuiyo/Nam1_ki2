#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void scan(int *n,int **a){
	printf("\nNhap hang cua ma tran vuong: ");
	scanf("%d",n);
	*a = (int*)malloc((*n)*(*n)*sizeof(int));
	for(int i=0;i<*n;i++){
		for(int j=0;j<*n;j++){
			printf("\nNhap [%d][%d]: ",i,j);
			scanf("%d",*a+i*(*n)+j);
		}
	}
}
void print(int n,const int *a){
	for(int i=0;i<n;i++){
		printf("\n");
		for(int j=0;j<n;j++){
			printf("%d ",*(a+i*n+j));
		}
	}
}
// tinh trung binh cong cac so nam duoi duong cheo phu
float TBC(const *a,int n){
	float Scheophu=0;
	int count=0; //n*(n-1)/2;
	for(int i=0;i<n;i++){
		for(int j = n-i;j>n-i-1;j--){
			Scheophu += (*a+i*n+j);
			count++;
		}
	}
	if(count == 0){
		printf("\nKhong tinh duoc TBC");
	}
	else{
		return Scheophu/count;
	}
}
int checktgt(const *a,int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(*(a+i*n+j) != 0){
				return 0;
			}
		}
	}
	return 1;
}
void thua(const *a,int n){
	int t=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(*(a+i*n+j) == 0){
				t++;
			}	
		}
	}
	float tong=(float)t*100.0/(n*n);
	if(tong > 60.0){
		printf("\nMa tran thua");
	}
	else{
		printf("\nkphai ma tran thua");
	}
	//if(tong > 60.0){
	//	return 1;
	//}
	//else{
	//	return 0;
	//}
}
main(){
	int n;
	int *a;
	scan(&n,&a);
	print(n,a);
	printf("\nTBC duong cheo phu: %.2f",TBC(a,n));
	if(checktgt(a,n) == 0){
		printf("\nKhong phai ma tran tam giac tren");
	}
	else{
		printf("\nMa tran da cho la ma tran tam giac tren");
	}
	thua(a,n);
	// if(thua(a,n) == 1){
	// printf("\nMa tran thua);
	//	}
	// else{
	// printf("\nKo phai ma tran thua);
	//}
}
