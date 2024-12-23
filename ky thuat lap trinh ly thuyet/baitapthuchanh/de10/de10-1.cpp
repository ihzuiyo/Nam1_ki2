#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	float x,y;
}Diem;
void nhap(Diem **p,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",&filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d",n);
	*p = (Diem*)malloc(*n*sizeof(Diem));
	for(int i=0;i<*n;i++){
		fscanf(f,"%f",&(*p+i)->x);
		fscanf(f,"%f",&(*p+i)->y);
	}
	fclose(f);
}
void in(Diem *p,int n){
	printf("\nSo diem la: ");
	for(int i=0;i<n;i++){
		printf("(%.2f ; %.2f) ",(p+i)->x,(p+i)->y);
		if(i == 4){
			printf("\n");
		}
	}
	printf("\n");
}
float khoangcach(Diem *p){
	return sqrt(p->x * p->x + p->y * p->y);
}
void so1(Diem *p,int n){
	int countt = 0,countn = 0;
	for(int i=0;i<n;i++){
		if(khoangcach(p+i) > 5){
			countt += 1;
		}
		else if(khoangcach(p+i) < 5){
			countn +=1;
		}
	}
	printf("\nSo diem nam trong duong tron la: %d",countt);
	printf("\nSo diem nam ngoai duong tron la: %d",countn);
}
void so2(Diem *p,int n){
	int countincycle = 0;
	for(int i=0;i<n-1;i++){
		for(int j=1;j<n;j++){
			if(khoangcach(p+i) < 5 && khoangcach(p+j) < 5){
				countincycle += 1;
			}
		}
	}
	printf("\nSo doan thang nam trong duong tron noi tren la: %d",countincycle);
		
}
main(){
	Diem *p;
	int n;
	nhap(&p,&n);
	in(p,n);
	so1(p,n);
	so2(p,n);
}