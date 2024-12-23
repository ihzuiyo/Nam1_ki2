#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void read_input(int **a,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*a = (int*)malloc(*n*sizeof(int));
	for(int i=0;i<*n;i++){
		fscanf(f,"%d ",(*a+i));
	}
	fclose(f);
}
void print(int *a,int n){
	printf("Day so cua file: ");
	for(int i=0;i<n;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}
float max_odd(int *a,int n,int max){
	max = *a;
	for(int i=0;i<n;i++){
		if(*(a+i) > max && *(a+i) % 2 == 1 || max % 2 == 0){
			max = *(a+i);
		}
	}
	if(max % 2 == 0){
		printf("Day khong co phan tu le\n");
	}
	else{
		printf("Phan tu le lon nhat cua day so: %d\n",max);
	}
	return max;
}
void write_file(int *a,int n){
	int max = max_odd(a,n,max);
	FILE *f = fopen("output1.txt" , "w");
	fprintf(f,"Day so la: ");
	for(int i=0;i<n;i++){
		fprintf(f,"%d ",*(a+i));
	}
	fprintf(f,"\n");
	if(max % 2 == 0){
		fprintf(f,"Khong co phan tu le trong day so");
	}
	else{
		fprintf(f,"Phan tu le lon nhat cua ma tran la: %d\n",max);
	}
	fclose(f);
}
main(){
	int *a,n,max;
	read_input(&a,&n);
	print(a,n);
//	max_odd(a,n,max);
	write_file(a,n);
}