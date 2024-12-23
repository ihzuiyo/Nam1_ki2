#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct Olp{
	char hoten[100];
	float diem;
	char truong;
};
void nhap(Olp **sv,int *n){
	char filename[] = "inputde6bai2.txt";
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*sv = (Olp*)malloc(*n*sizeof(Olp));
	for(int i=0;i<*n;i++){
		fgets((*sv+i)->hoten, 100, f);
		(*sv+i)->hoten[strlen((*sv+i)->hoten) - 1] = '\0';
		fscanf(f, "%f ",&(*sv+i)->diem);
		fscanf(f, "%c ",&(*sv+i)->truong);
	}
	fclose(f);
}
void truongdiemcao(Olp *sv,int n){
	float tong[4] = {0};
	for(int i=0;i<n;i++){
		if((sv+i)->truong == 'A'){
			tong[0] += (sv+i)->diem;
		}
		if((sv+i)->truong == 'B'){
			tong[1] += (sv+i)->diem;
		}
		if((sv+i)->truong == 'C'){
			tong[2] += (sv+i)->diem;
		}
		if((sv+i)->truong == 'D'){
			tong[3] += (sv+i)->diem;
		}
	}
	//
	int c=0;
	float max = -1;
	for(int i=0;i<4;i++){
		if(tong[i] > max){
			max = tong[i];
			c++;
		}
	}
	if(c == 1){
		printf("Truong co tong diem cao nhat la: ");
	}
	else{
		printf("Nhung truong co tong diem cao nhat la: ");
	}
	for(int i=0;i<4;i++){
		if(tong[i] == max){
			printf(" %c ", 'A'+i);
		}
	}
	printf("\n");
}
void thisinhdiemcao(Olp *sv,int n){
	int count = 0;
	float max = -1;
	for(int i=0;i<n;i++){
		if((sv+i)->diem > max){
			max = (sv+i)->diem;
			count++;
		}
	}
	if(count == 1){
		printf("Thi sinh co diem cao nhat la: \n");
	}
	else{
		printf("Nhung thi sinh co diem cao nhat la: \n");
	}
	for(int i=0;i<n;i++){
		if((sv+i)->diem == max){
			printf("Ho ten:  %s \t Diem :%.2f \t Truong: %c\n",(sv+i)->hoten,(sv+i)->diem,(sv+i)->truong);
		}
	}
}
void xuat(Olp *sv,int n){
	for(int i=0;i<n;i++){
		printf("Ho ten:%s \t Diem:%.2f \t Truong:%c\n",(sv+i)->hoten,(sv+i)->diem,(sv+i)->truong);
	}
}
main(){
	Olp *sv;
	int n;
	nhap(&sv,&n);
	printf("Danh sach thi sinh: \n");
	xuat(sv,n);
	truongdiemcao(sv,n);
	thisinhdiemcao(sv,n);
}