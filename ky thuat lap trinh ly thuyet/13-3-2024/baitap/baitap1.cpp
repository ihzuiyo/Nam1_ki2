#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Diem{
	float x,y;
};
void scan(int *n,Diem **point){
	printf("\nNhap so diem: ");
	scanf("%d",n);
	*point = (Diem*)malloc((*n)*sizeof(Diem));
	for(int i=0;i<(*n) ; i++){
		printf("\nNhap diem thu %d: ",i);
		scanf("%f %f", &(*point+i)->x , &(*point+i)->y);
	}
	
}
void print(const Diem *point , int n){
	printf("\nCac diem ban vua nhap: ");
	for(int i=0;i<n;i++){
		printf("\nDiem thu %d: (%.2f ; %.2f)",i , (point+i)->x , (point+i)->y);
	}
}
// 1)
void count(const Diem *point,int n){
	int countngoai=0;
	int counttrong=0;
	for(int i=0;i<n;i++){
		if((pow((point+i)->x,2) + pow((point+i)->y,2)) > 5){ //1
			countngoai++;
		}
		if((pow((point+i)->x,2) + pow((point+i)->y,2)) < 5){ //2
			counttrong++;
		}
	}
	printf("\nSo diem nam ngoai hinh tron co R = 5 la: %d",countngoai);
	printf("\nSo diem nam trong hinh tron co R = 5 la: %d",counttrong);
}
// 2)
void timdiemdoixung(Diem *point,int n){
	int check[n];
	int countdx=0;
	printf("\nCac diem doi xung qua goc toa do la: ");
	Diem *doixung;
	doixung = (Diem*)malloc(n*sizeof(Diem));
	for(int i=0;i<n;i++){
		check[i] = 0;
		for(int j=i+1;j<n;j++){
			if((point+i)->x == (-1)*(point+j)->x && (point+i)->y == (-1)*(point+j)->y){ //x1 = -x2 && y1=-y2;
				check[i]+=1;
				(doixung+i)->x = (-1)*(point+j)->x;
				(doixung+i)->y = (-1)*(point+j)->y;
			}
		}
		if(check[i] >= 1){
			printf("\n(%.2f ; %.2f) & (%.2f ; %.2f)",(point+i)->x , (point+i)->y ,(doixung+i)->x , (doixung+i)->y);
			countdx+=2;
		}
	}
	if(countdx == 0){
		printf("\nKhong co diem doi xung nao");
	}
	else{
		printf("\nSo diem doi xung la: %d",countdx);
	}
	
}
main(){
	int n;
	Diem *point;
	scan(&n,&point);
	print(point,n);
	count(point,n);
	timdiemdoixung(point,n);
}