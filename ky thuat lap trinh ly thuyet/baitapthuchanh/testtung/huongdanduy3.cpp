#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct Thisinh{
	char hoten[100];
	float diem;
	char truong;
};
void nhap(Thisinh **ts,int *n){
	char filename[] = "huongdanduy3.txt";
	FILE *f = fopen(filename, "r");
	fscanf(f ,"%d ",n);
	*ts = (Thisinh*)malloc((*n)*sizeof(Thisinh));
	for(int i=0;i<*n;i++){
		fgets((*ts+i)->hoten,100,f);
		(*ts+i)->hoten[strlen((*ts+i)->hoten) - 1] = '\0';
		fscanf(f,"%f ",&(*ts+i)->diem);
		fscanf(f,"%c ",&(*ts+i)->truong);
	}
	fclose(f);
}
void xuat(Thisinh *ts,int n){
	printf("Danh sach thi sinh thi Olympic: \n");
	for(int i=0;i<n;i++){
		printf("HO TEN: %s - DIEM: %.2f - TRUONG: %c\n",(ts+i)->hoten,(ts+i)->diem,(ts+i)->truong);
	}
}
void tinhtongtruongcodiemcaonhat(Thisinh *ts,int n){
	float tong[3] = {0}; //tổng 0 1 2 3 đều = 0 và nó tương ứng với trường A B C D
	for(int i=0;i<n;i++){
		if((ts+i)->truong == 'A'){
			tong[0] += (ts+i)->diem;
		}
		if((ts+i)->truong == 'B'){
			tong[1] += (ts+i)->diem;
		}
		if((ts+i)->truong == 'C'){
			tong[2] += (ts+i)->diem;
		}
		if((ts+i)->truong == 'D'){
			tong[3] += (ts+i)->diem;
		}
	}
	float max = tong[0];
	int index = 0;
	for(int i=0;i<4;i++){
		if(tong[i] > max){
			max = tong[i];
			index = i;
		}
	}
	if(index == 0){
		printf("Truong A co tong diem cao nhat\n");
	}
	else if(index == 1){
		printf("Truong B co tong diem cao nhat\n");
	}
	else if(index == 2){
		printf("Truong C co tong diem cao nhat\n");
	}
	else if(index == 3){
		printf("Truong D co tong diem cao nhat\n");
	}
}
void thisinhdiemcaonhat(Thisinh *ts,int n){
	float max = -1;
	int c=1;
	for(int i=0;i<n;i++){
		if((ts+i)->diem > max){
			max = (ts+i)->diem;
		}
	}
	printf("Cac thi sinh co diem cao nhat la: \n");
	for(int i=0;i<n;i++){
		if((ts+i)->diem == max){
			printf("HO TEN: %s - DIEM: %.2f - TRUONG: %c\n",(ts+i)->hoten,(ts+i)->diem,(ts+i)->truong);
		}
	}
}
main(){
	int n;
	Thisinh *ts;
	nhap(&ts,&n);
	xuat(ts,n);
	tinhtongtruongcodiemcaonhat(ts,n);
	thisinhdiemcaonhat(ts,n);
}