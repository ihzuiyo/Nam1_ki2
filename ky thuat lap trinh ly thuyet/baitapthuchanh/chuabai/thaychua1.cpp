#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void read_file(int **a,int *n){
	char filename[100];
	printf("NHAP TEN FILE: ");
	scanf("%s",&filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*a = (int*)malloc(*n*sizeof(int));
	for(int i=0;i<*n;i++){
		fscanf(f,"%d ",(*a+i));
	}
	fclose(f);
	printf("\n");
}
void print_array(const int *a,int n){
	printf("Day so: ");
	for(int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}
void max_odd(const int *a,int n){
	int max = *a;
	for(int i=1;i<n;i++){
		if(*(a+i) > max && *(a+i) % 2 != 0 || max % 2 == 0){
			max = *(a+i);
		}
	}
	if(max % 2 ==0){
		printf("Khong co phan tu le trong day\n");
	}
	else{
		printf("Max le la: %d\n",max);
	}
}
main(){
	int *a;
	int n;
	read_file(&a,&n);
//	printf("Test: %d\n",*(a+4));
	print_array(a,n);
	max_odd(a,n);
}