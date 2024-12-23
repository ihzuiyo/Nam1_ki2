#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct Point{
	float x,y;
};
void nhap(Point **diem,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",&filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d",n);
	*diem = (Point*)malloc(*n*sizeof(diem));
	for(int i=0;i<*n;i++){
		fscanf(f,"%f",&(*diem+i)->x);
		fscanf(f,"%f",&(*diem+i)->y);
	}
	fclose(f);
}
void xuat(Point *diem,int n){
	printf("Day diem tren mat phang la: \n");
	for(int i=0;i<n;i++){
		printf("[%.2f ; %.2f] ",(diem+i)->x,(diem+i)->y); //diem[i].x
	}
	printf("\n");
}
float kc(Point *diem){
	return sqrt(diem->x * diem->x + diem->y * diem->y);
}
float tim1diemxagoctoado(Point *diem,int n){
	float max = kc(diem);
	int toado = 0;
	for(int i=1;i<n;i++){
		if(kc(diem+i) > max){
			max = kc(diem+i);
			toado = i;
		}
	}
	return toado;
}
int demdiem(Point *diem,int n){
	int count=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if((diem+i)->x < 0 && (diem+j)->y < 0 && (diem+j)->x < 0 && (diem+j)->y <0){
				count++;
			}
		}
	}
	return count;
}
main(){
	int n;
	Point *diem;
	nhap(&diem,&n);
	xuat(diem,n);
	int toado = tim1diemxagoctoado(diem,n);
	printf("Diem xa goc toa do nhat la: [%.2f ; %.2f] \n",(diem+toado)->x , (diem+toado)->y);
	printf("So doan thang thuoc goc phan tu thu ba la: %d\n",demdiem(diem,n));
	
	
}