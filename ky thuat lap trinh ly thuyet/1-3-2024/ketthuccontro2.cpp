#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct Point{
	float x,y,z;
	
};
main(){
	int n;
	Point *a;
	printf("\nNhap n:");
	
	scanf("%d",&n);
	a = (Point*)malloc(n*sizeof(Point));
	for(int i=0;i<n;i++){
		printf("\nNhap toa do diem: ");
		scanf("%f %f %f", &(a+i)->x , &(a+i)->y , &(a+i)->z ); 		// &(p+i).x ...
	}
	for(int i=0;i<n;i++){
		printf("\n%f;%f;%f", (a+i)->x, (a+i)->y , (a+i)->z); //vi?t b?ng con tr?  		 a[i].x , a[i].y , a[i].z (m?ng tinh)
	}
	
}