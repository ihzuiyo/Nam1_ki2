#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void input(int **mt,int *n){
	char filename[100];
	printf("NHAP TEN FILE: ");
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d",n);
	*mt = (int*)malloc(*n**n*sizeof(int));
	for(int i=0;i<*n;i++){
		for(int j=0;j<*n;j++){
			fscanf(f,"%d ",*mt+i**n+j);
		}
	}
	fclose(f);
}
void output(int *mt,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",*(mt+i*n+j));
		}
		printf("\n");
	}
}
void tbcduoicheophu(int *mt,int n){
	int s=0,c=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i + j > n-1){
				s += *(mt+i*n+j);
				c += 1;
			}
		}
	}
	float tbc = (float)s/c;
	printf("\nTBC phan tu duoi cheo phu la: %.2f",tbc);
}
void matrantgt(int *mt,int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(*(mt+i*n+j) != 0){
				printf("\nKO PHAI MA TRAN TAM GIAC TREN\n");
				return;
			}
		}
	}
	printf("\nMA TRAN DA CHO LA MA TRAN TAM GIAC TREN\n");
}
void matrantgd(int *mt,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(*(mt+i*n+j) != 0){
				printf("\nKO PHAI MA TRAN TAM GIAC DUOI\n");
				return;
			}
		}
	}
	printf("\nMA TRAN DA CHO LA MA TRAN TAM GIAC DUOI");
}
main(){
	int n;
	int *mt;
	input(&mt,&n);
	output(mt,n);
	tbcduoicheophu(mt,n);
	matrantgt(mt,n);
	matrantgd(mt,n);
	
}