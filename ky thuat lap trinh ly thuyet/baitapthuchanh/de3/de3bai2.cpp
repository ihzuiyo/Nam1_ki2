#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct dangvien{
	char ht[100];
	int namsinh;
	int nkn;
};
void nhap(dangvien **dv,int *n){
	char filename[] = "inputde3bai2.txt";
	FILE *f = fopen(filename, "r");
	fscanf(f , "%d", n);
	if(n == 0){
		printf("This file have no person.\n");
		return;
	}
	*dv = (dangvien*)malloc(*n*sizeof(dangvien));
	for(int i=0;i<*n;i++){
		fgetc(f);
		fgets((*dv+i)->ht,100,f);
		(*dv+i)->ht[strlen((*dv+i)->ht)-1] = '\0';
		fscanf(f,"%d",&(*dv+i)->namsinh);
		fscanf(f,"%d",&(*dv+i)->nkn);
	}
	fclose(f);
}
void xuat(dangvien *dv,int n){
	for(int i=0;i<n;i++){
		printf("\tHo ten dong chi: ");
		printf("%s\n", (dv+i)->ht);
		printf("\tNam sinh: ");
		printf("%d\n",(dv+i)->namsinh);
		printf("\tNam ket nap: ");
		printf("%d\n", (dv+i)->nkn);
		printf("\n");
	}
}
//void xuatfile(dangvien *dv,int n){
//	FILE *f = fopen("outputde3bai2.txt", "w");
//	for(int i=0;i<n;i++){
//		fprintf(f ,"%s", (dv+i)->ht);
//		fprintf(f,"%d",(dv+i)->namsinh);
//		fprintf(f, "%d", (dv+i)->nkn);
//	}
//	fclose(f);
//}
int cmp(const void *a,const void *b){
	dangvien *dv1 = (dangvien*)a;
	dangvien *dv2 = (dangvien*)b;
	return dv1->nkn - dv2->nkn;
}
void thongke(dangvien *dv,int n){
	for(int i=0;i<n;i++){
		if(2024 - (dv+i)->nkn > 20){
			printf("\tHo ten dong chi: ");
			printf("%s \n", (dv+i)->ht);
			printf("\tNam sinh: ");
			printf("%d \n",(dv+i)->namsinh);
			printf("\tNam ket nap: ");
			printf("%d \n", (dv+i)->nkn);
		}
	}
}
int main(){
	int n;
	dangvien *dv;
	printf("Danh sach cac dang vien la:\n ");
	nhap(&dv,&n);
	xuat(dv,n);
	qsort(dv,n,sizeof(dangvien),cmp);
	printf("Danh sach cac dang vien sap xep theo nam ket nap tang dan la:\n");
	xuat(dv,n);
	printf("Danh sach cac dang vien co tu 20 nam tuoi la:\n");
	thongke(dv,n);
}
