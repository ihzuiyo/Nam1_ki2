#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

// a)
void nhapdayso(int *n,int **a){
	scanf("%d",n);
	*a = (int*)malloc((*n)*sizeof(int));
	for(int i=0;i<(*n);i++){
		printf("\nNhap phan tu thu %d cua day so: ",i);
		scanf("%d",*a+i);
		
	}
}
void indayso(int n,int *a){
	for(int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
}
// b)
void kiemtrab(int n,int *a){
	int count=0;
	for(int i=0;i<n;i++){
		if(*a != 0){
			printf("\nPhan tu dau tien cua day khac 0");
			break;
		}
		else{
			printf("\nPhan tu dau tien cua day = 0");
			break;
		}
		if(*(a+i) % *a == 0){
			count++;
		}
	}
	printf("\nCo %d phan tu chia het cho phan tu dau tien",count);
}
// e)
void phanduongnhonhat(int n,int *a){
	int min = *a;
	for(int i=0;i<n;i++){
		if(*(a+i) > 0){
			min = *(a+i); //tim phan tu duong
			for(int j=i+1; j<n ;j++){
				if(*(a+j) < min && *(a+j) > 0){
					min = *(a+j); //xet phan tu duong thoa man dieu kien
				}				  
			}
			printf("\nMin duong = %d",min);
			return;
		}
	}
	
}
// c)
void baphantulonnhat(int n,int *a,int *m1,int *m2,int *m3){
	int temp = *(a)> *(a+1) ? *a : *(a+1);
	*m1 = *a, *m2 = *(a+1) , *m3=*(a+2);
	*m1 = temp > *(a+2) ? temp : *(a+2);
	temp = *a < *(a+1) ? temp : *(a+1);
	*m3 = temp < *(a+2) ? temp : *(a+2);
	*m2 = *a + *(a+1) + *(a+2) - *m1 - *m3;
	for(int i = 3; i < n ;i++){
		if(*(a+i) > *m1){
			*m3 = *m2;
			*m2 = *m1;
			*m1 = *(a+i);
		}
		else if(*(a+i) > *m2){
			*m3 = *m2;
			*m2 = *(a+1);
		}
		else if(*(a+1) > *m3){
			*m3 = *(a+1);
		}
	}
	printf("\nBa phan tu lon nhat: %d %d %d ",*m1,*m2,*m3);
}
////d)
//void bo3phantucotonglonnhat(int n,int *a){
//	for(int i=0;i<n;i++){
//		
//	}
//}
	

main(){
	int n;
	int *a;
	int m1,m2,m3;
	nhapdayso(&n,&a); //a)
	indayso(n,a);		//a)
	kiemtrab(n,a); //b)
	phanduongnhonhat(n,a); //e)
	baphantulonnhat(n,a,&m1,&m2,&m3); //c)
	
}