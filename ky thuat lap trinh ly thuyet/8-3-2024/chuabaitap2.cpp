#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap(int **a,int *n);
void in(const int *a,int n);
float tbc(const int *a,int n);
int ptcln(const int *a,int n);
int kiemtratgd(const int *a,int n);


int main(){
	int *a;
	int n;
	nhap(&a,&n);
	in(a,n);
	printf("\nTBC = %.1f\n",tbc(a,n));
	int tmp = ptcln(a,n);
	if(tmp % 2==0){
		printf("Phan tu chan lon nhat: %d\n",tmp);
	}
	else{
		printf("Khong co phan tu chan nao\n");
	}
	if(kiemtratgd(a,n) == 1){
		printf("Ma tran tam giac duoi\n");
	}
	else{
		printf("Khong phai ma tran tam giac duoi\n");
	}
}

void nhap(int **a,int *n){
	printf("Nhap n:");
	scanf("%d", n); //dia chi cua n (*n)
	int m = *n;
	*a = (int*)malloc(m*m*sizeof(int));
	for(int i=0; i<m ;i++){
		for(int j=0; j<m; j++){
			printf("Nhap a[%d][%d]: ",i,j);
			scanf("%d", *a+i*m+j);
		}
	}
};
void in(const int *a,int n){
	for(int i=0; i<n;i++){
		printf("\n");
		for(int j=0; j < n ;j++){
			printf("%6d", *(a+i*n+j));
		}
	}
}
float tbc(const int *a, int n){
	int S=0;
	for(int i=0;i<n;i++){
		S += *(a+i*n+i);
	}
	return (float)S/n;
}
//int ptcln(const int *a,int n){
//	int max = *(a+1);
//	for(int i=0 i < n; i++){
//		for(int j=0 ;j < n ;j++){
//			if(i<j){ // i<j nua tren i>j nua duoi i=j duong cheo chinh
//				if(*(a+i*n+j) > max && *(a+i*n+j) % 2 == 0 || max % 2 !=0){
//					max = *(a+i*n+j);
//				}
//			}
//		}
//	}
//  return max;	
//}

int ptcln(const int *a,int n){
	if(n <= 1){
		return 1;
	}
	int max = *(a+1);
	for(int i=0; i < n-1; i++){
		for(int j=i+1 ;j < n ;j++){
			if(*(a+i*n+j) > max && *(a+i*n+j) % 2 == 0 || max % 2 !=0){
				max = *(a+i*n+j);
			}
		}
	}
	return max;
}
int kiemtratgd(const int *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(*(a+i*n+j) != 0){
				return 0;
			}
		}
	}
	return 1;
}