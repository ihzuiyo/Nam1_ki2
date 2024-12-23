#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main(){
	int *a,n;
	printf("Nhap so luong phan tu: ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		printf("Nhap a[%d]:",i);
		scanf("%d",a+i); //address
	}
	for(int i=0; i<n ; i++){
		printf("%d ",*(a+i)); //value
	}
	// lien quan den mang la dung con tro
	
}