#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
typedef struct Sach{
	char tensach[200];
	char tacgia[200];
	int nam;
};
void scan(Sach **sach,int *n){
	printf("\nNhap so luong sach: ");
	scanf("%d",n);
	*sach = (Sach*)malloc((*n)*sizeof(Sach));
	for(int i=0;i<(*n);i++){
		printf("\n\tTen sach: ");
		fflush(stdin);
		fgets((*sach+i)->tensach , 200, stdin);
		(*sach+i)->tensach[strlen((*sach+i)->tensach)-1] = '\0';
		printf("\n\tTac gia: ");
		fgets((*sach+i)->tacgia , 200 , stdin);
		(*sach+i)->tacgia[strlen((*sach+i)->tacgia)-1] = '\0';
		printf("\n\tNam: ");
		scanf("%d",&(*sach+i)->nam);
	}
}
void print(const Sach *sach,int n){
	for(int i=0;i<n;i++){
		printf("\n%s - %s - %d",(sach+i)->tensach , (sach+i)->tacgia , (sach+i)->nam);
	}
}
// 1)
//void findbook(const Sach *sach,int n){
//	char timsach[200];
//	int check=0;
//	printf("\nNhap ten sach ban muon tim: ");
//	fflush(stdin);
//	fgets(timsach,200,stdin);
//	timsach[strlen(timsach)-1] = '\0';
//	int result;
//	for(int i=0;i < n;i++){
//		result = strcmp( (sach+i)->tensach , timsach);
//		if(result == 0){
//			check=1;
//			printf("\n%s - %s - %d",(sach+i)->tensach , (sach+i)->tacgia , (sach+i)->nam);
//		}
//	}
//	if(check == 0){
//		printf("\nQuyen sach ban dang tim khong co trong danh sach");
//	}
//}
// 2) in ra danh sach sach co nam san xuat duoi 2000,sap xep tang dan
int cmp(const void *a,const void *b){
	Sach *sach1 = (Sach*)a;
	Sach *sach2 = (Sach*)b;
	return sach1->nam - sach2->nam;
}
main(){
	int n;
	Sach *sach;
	scan(&sach , &n);
	print(sach , n);
//	findbook(sach,n);
	qsort(sach , n , sizeof(Sach), cmp);
	printf("\nDanh sach sau sap xep: ");
	for(int i=0;i<n;i++){
		if((sach+i)->nam < 2000){
			printf("\n%s - %s - %d",(sach+i)->tensach,(sach+i)->tacgia,(sach+i)->nam);
		}
	}
	
}