#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct Sinhvien{
	char hoten[100];
	char quequan[100];
	char hocluc;
};
// - Doc va xuat
void scan(int *n,Sinhvien **sv){
	printf("Nhap so sinh vien: ");
	scanf("%d",n);
	*sv = (Sinhvien*)malloc((*n)*sizeof(Sinhvien));
	for(int i=0;i<*n;i++){
		printf("\nNhap ten sinh vien:  ");
		fflush(stdin);
		fgets((*sv+i)->hoten,100,stdin);
		(*sv+i)->hoten[strlen((*sv+i)->hoten)-1] = '\0';
		printf("\nQue quan cua sinh vien: ");
		fgets((*sv+i)->quequan,100,stdin);
		(*sv+i)->quequan[strlen((*sv+i)->quequan)-1] = '\0';
		printf("\nHoc luc cua sinh vien: ");
		scanf("%c",&(*sv+i)->hocluc);
	}
}
void print(int n,Sinhvien *sv){
	for(int i=0;i<n;i++){
		printf("\n%s \t %s \t %c",(sv+i)->hoten,(sv+i)->quequan,(sv+i)->hocluc);
	}
}
// Tim ten 1 sinh vien co trong danh sach sinh vien do khong?
void findstudent(const Sinhvien *sv,int n){
	char timhocsinh[100];
	int check=0;
	printf("\nNhap ten hoc sinh ban muon tim: ");
	fflush(stdin);
	fgets(timhocsinh,100,stdin);
	timhocsinh[strlen(timhocsinh)-1] = '\0';
	int result;
	for(int i=0;i<n;i++){
		result = strcmp( (sv+i)->hoten , timhocsinh);
		if(result == 0){
			check = 1;
			printf("\n%s \t %s \t %c",(sv+i)->hoten,(sv+i)->quequan,(sv+i)->hocluc);
		}
	}
	if(check == 0){
		printf("\nKhong co ten hoc sinh ma ban dang tim");
	}
}
main(){
	int n;
	Sinhvien *sv;
	scan(&n,&sv);
	print(n,sv);
	findstudent(sv,n);
}
	