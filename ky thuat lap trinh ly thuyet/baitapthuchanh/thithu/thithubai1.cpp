#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void nhap(int **a,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d",n);
	*a = (int*)malloc(*n*sizeof(int));
	for(int i=0;i<*n;i++){
		fscanf(f,"%d ",(*a+i));
	}
	fclose(f);
}
void xuat(int *a,int n){
	for(int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}
void phantulelonnhat(int *a,int n){
	int max = *a;
	for(int i=0;i<n;i++){
		if(*(a+i) > max && *(a+i) % 2 == 1){
			max = *(a+i);
		}
	}
	if(max % 2 == 0){
		printf("Khong co phan tu le trong ma tran\n");
	}
	else{
		printf("Phan tu le lon nhat cua day so la: %d\n",max);
	}
}
main(){
	int n;
	int *a;
	nhap(&a,&n);
	xuat(a,n);
	phantulelonnhat(a,n);
}