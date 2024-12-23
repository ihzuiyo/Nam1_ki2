#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap(int **a,int *n);
void in(const int *a,int n);
int timmax(const int *a,int n);
void tim3Max(const int *a,int n,int *m1,int *m2,int *m3);

main(){
	int *a,n;
	nhap (&a,&n); //truyen vao dia chi cua a va dia chi cua n
	in(a,n);
	// lien quan den mang la dung con tro
	printf("\nMax = %d\n",timmax(a,n) );
	int m1,m2,m3;
	tim3Max(a,n,&m1,&m2,&m3);
	printf("Ba gia tri lon nhat: %d %d %d\n",m1 , m2 , m3);
}
void nhap(int **a,int *n){
	printf("Nhap so luong phan tu: ");
	scanf("%d",n);
	*a  = (int*)malloc((*n)*sizeof(int));
	 // lay gia tri cua n thi phai *n
	 
	for(int i=0;i<(*n);i++){
		printf("Nhap a[%d]:",i);
		scanf("%d",*a+i); //address
	}
}
void in(const int *a,int n){ // const lam cho gia tri khi gan vao se khong doi (ko muon thay doi gia tri cua a trong ham)
	for(int i=0; i<n ; i++){
		printf("%d ",*(a+i)); //value
	}
}
int timmax(const int *a,int n){
	int max = *a;
	for(int i=0;i<n;i++){
		if(*(a+i) > max){
			max = *(a+i);
		}
	}
	return max;
}
void tim3Max(const int *a,int n,int *m1,int *m2,int *m3){ //nen tim hieu ki
	int tmp = *a > *(a+1) ? *a : *(a+1);
	*m1 = tmp > *(a+2) ? tmp : *(a+2);
	tmp = *a < *(a+1) ? *a : *(a+1);
	*m3 = tmp < *(a+2) ? tmp: *(a+2);
	*m2 = *a + *(a+1) + *(a+2) - *m1 - *m3;
	for(int i=3;i<n;i++){
		if(*(a+i) > *m1){
			*m3 = *m2;
			*m2 = *m1;
			*m1 = *(a+i);	
		}
		else if(*(a+i) > *m2){
			*m3 = *m2;
			*m2 = *(a+i);
		}
		else if(*(a+i) > *m3){
			*m3 = *(a+i);
		}
		
	}
}