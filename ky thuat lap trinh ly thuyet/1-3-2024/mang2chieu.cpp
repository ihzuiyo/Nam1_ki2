#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//Mảng 2 chiều (con trỏ)


main(){
	int m = 3,n = 5;
	// 2 cách viết
	// ---- Cách 1 ----
	int *a;  			// mảng tĩnh : a[50][50]
	a = (int*)malloc(m*n*sizeof(int));  
	// ví dụ i = 2 , j = 3 : địa chỉ của a[2][3] trong mảng tĩnh nằm ở a+i*n+j;
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("Nhap a[%d][%d]: ",i,j);
			scanf("%d ", a+i*n+j); // mảng tĩnh &a[i*n+j]
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ", *(a+i*n+j));
		}
		printf("\n");
	}
	// ---- Cách 2 ----
	// *((*(p+i)+j))
}