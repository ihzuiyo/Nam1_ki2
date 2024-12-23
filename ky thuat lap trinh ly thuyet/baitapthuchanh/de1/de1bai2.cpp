#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char tensach[100];
	char tacgia[100];
	int namxb;
}Sach;
void read_input(Sach **s, int *n){
	char filename[100];
	FILE *f = fopen("inputde2bai2.txt" , "r");
	fscanf(f,"%d",n);
	*s = (Sach*)malloc(*n*sizeof(Sach));
	for(int i=0;i<*n;i++){
		fgetc(f);
		fgets((*s+i)->tensach,100,f);
		(*s+i)->tensach[strlen((*s+i)->tensach)-1] = '\0';
		fgets((*s+i)->tacgia,100,f);
		(*s+i)->tacgia[strlen((*s+i)->tacgia)-1] = '\0';
		fscanf(f,"%d",&(*s+i)->namxb);
	}
	fclose(f);
}
void findbook(Sach *s,int n){
	char findbook[100];
	printf("Nhap ten sach muon tim: ");
	fgets(findbook,100,stdin);
	findbook[strlen(findbook)-1] = '\0';
	for(int i=0;i<n;i++){
		if(strcmp(findbook,(s+i)->tensach) == 0){
			printf("Ten sach: %s - Tac gia %s - Nam XB: %d\n",(s+i)->tensach,(s+i)->tacgia,(s+i)->namxb);
			return;
		}
	}
	printf("Khong tim thay quyen sach co ten '%s' \n",findbook);
}
void truoc2000(Sach *s,int n){
	int check = 0;
	printf("DANH SACH QUYEN SACH CO NAM XUAT BAN TRUOC 2000 LA: \n");
	for(int i=0;i<n;i++){
		if((s+i)->namxb < 2000){
			printf("%s - %s - %d\n",(s+i)->tensach,(s+i)->tacgia,(s+i)->namxb);
			check = 1;
		}
	}
	if(check == 0){
		printf("Khong co quyen sach nao xuat ban truoc nam 2000\n");
	}
}
int cmp(const void *a,const void *b){
	Sach *a1 = (Sach*)a;
	Sach *a2 = (Sach*)b;
	return a2->namxb - a1->namxb;	
}
void print(Sach *s,int n){
	FILE *f = fopen("outputde1bai2.txt", "w");
	int check = 0;
	fprintf(f,"Thu vien co nhung quyen sach xuat ban truoc nam 2000 la: \n");
	for(int i=0;i<n;i++){
		if((s+i)->namxb < 2000){
			fprintf(f,"%s - %s - %d\n",(s+i)->tensach,(s+i)->tacgia,(s+i)->namxb);
			check = 1;
		}
	}
	if(check == 0){
		fprintf(f,"Khong co sach nao xuat ban truoc nam 2000\n");
	}
	fclose(f);
}
main(){
	int n;
	Sach *s;
	read_input(&s,&n);
	findbook(s,n);
	qsort(s,n,sizeof(Sach),cmp);
	truoc2000(s,n);
	print(s,n);
}