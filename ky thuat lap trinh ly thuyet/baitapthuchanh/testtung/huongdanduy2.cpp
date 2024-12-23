#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct Thuvien{
	char tensach[100];
	char tacgia[100];
	int nam;
};
void nhap(Thuvien **sach,int *n){
	char filename[] = "input.txt";
	FILE *f = fopen(filename, "r");
	fscanf(f , "%d ", n);
	*sach = (Thuvien*)malloc((*n)*sizeof(Thuvien));
	for(int i=0;i<*n;i++){
		fgets((*sach+i)->tensach,100,f);
		(*sach+i)->tensach[strlen((*sach+i)->tensach) -1] == '\0';
		fgets((*sach+i)->tacgia,100,f);
		(*sach+i)->tacgia[strlen((*sach+i)->tacgia) -1] == '\0';  //xu li dau cach
		fscanf(f, "%d ",&(*sach+i)->nam);
	}
	fclose(f);
}
void xuat(Thuvien *sach,int n){
	printf("Danh sach sach cua thu vien la: \n");
	for(int i=0;i<n;i++){
		printf("TEN SACH: %s TAC GIA: %s NAM XUAT BAN: %d\n",(sach+i)->tensach , (sach+i)->tacgia , (sach+i)->nam);
	}
}
main(){
	int n;
	Thuvien *sach;
	nhap(&sach,&n);
	xuat(sach,n);
}