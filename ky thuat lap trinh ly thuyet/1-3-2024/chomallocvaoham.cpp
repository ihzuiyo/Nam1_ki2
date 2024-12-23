#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct Point{
	float x,y,z;
	
};
void nhap(Point **p,int *n){
	printf("\nNhap n:");
	scanf("%d", n);
	*p = (Point*)malloc((*n)*sizeof(Point));
	for(int i=0;i<*n;i++){
		printf("\nNhap toa do diem thu %d: ",i);
		scanf("%f %f %f", &(*p+i)->x , &(*p+i)->y , &(*p+i)->z ); 		
	}
}
void in(const Point *p,int n){
	for(int i=0;i<n;i++){
		printf("\n%.1f; %.1f; %.1f", (p+i)->x, (p+i)->y , (p+i)->z); //viết bằng con trỏ (đi thi nên khai báo con trỏ) 		
	//	[ p[i].x , p[i].y , p[i].z (mảng tĩnh) ]
	}
}

main(){
	int n;
	Point *a;
	nhap(&a, &n);
	in (a,n);
	
}