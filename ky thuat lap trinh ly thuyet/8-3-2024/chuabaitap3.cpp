#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct SV{
	char ht[30];
	int d;
	char t;
} SV;

void nhap(SV **a, int *n);
void in(const SV *a,int n);
void truongdiemcao(const SV *a,int n);
void SVdiemcao(const SV *a,int n);
int cmp(const void *a,const void *b);
	

int main(){
	SV *a;
	int n;
	nhap(&a,&n);
	in(a,n);
	truongdiemcao(a,n);
	SVdiemcao(a,n);
	qsort(a, n, sizeof(SV),cmp);
	printf("\nDanh sach sau khi sap xep: ");
	in(a,n);
}

void nhap(SV **a,int *n){
	printf("Nhap n:");
	scanf("%d",n);
	int m = *n;
	*a = (SV*)malloc(m*sizeof(SV));
	for(int i=0;i<m;i++){
		printf("\nNhap ho ten sinh vien: ");
		fflush(stdin);
		fgets((*a+i)->ht, 30, stdin);
		(*a+i)->ht[strlen((*a+i)->ht)-1] = '\0';
		printf("\nNhap diem: ");
		scanf("%d", &(*a+i)->d);
		printf("\nNhap truong: ");
		fflush(stdin);
		scanf("%c",&(*a+i)->t);
	}
}
void in(const SV *a,int n){
	for(int i=0; i<n ;i++){
		printf("\n%s - %d - %c",(a+i)->ht, (a+i)->d, (a+i)->t);
	}
}
void truongdiemcao(const SV *a,int n){
	int tong[] = {0, 0, 0, 0};
	for(int i=0;i<n;i++){
		tong[(a+i)->t - 'A'] += (a+i)->d;			
	}
	int max = tong[0];
	for(int i = 0;i<4;i++){
		if(tong[i] > max){
			max=tong[i];
		}
	}
	for(int i=0;i<4;i++){
		if(tong[i] == max){
			printf("\nTruong co tong diem cao nhat: %c",'A' + i);
		}
	}
}
void SVdiemcao(const SV *a,int n){
	int max = a->d;
	for(int i=0;i<n;i++){
		if((a+i)->d > max){
			max = (a+i)->d;
		}
	}
	printf("\nSV dat diem cao nhat: ");
	for(int i=0;i<n;i++){
		if((a+i)->d == max){
			printf("\n%s ",(a+i)->ht);
		}
	}
}
int cmp(const void *a,const void *b){
	SV *sv1 = (SV*)a;
	SV *sv2 = (SV*)b;
	return sv2->d - sv1->d; //sv1 - sv2 = nho den lon || sv2 - sv1 = lon den nho
	//return strcmp(sv1->ht, sv2->ht);
}
// Cach 2: (danh cho viec sap xep ho ten)
//int cmp(const void *a,const void *b){
//	SV *sv1 = (SV*)a;
//	SV *sv2 = (SV*)b;
//	if(strcmp(sv1->ht , sv2->ht) == 0){
//		return sv1->d - sv2->d;
//	}
//	return strcmp(sv1->ht, sv2->ht);
//}
