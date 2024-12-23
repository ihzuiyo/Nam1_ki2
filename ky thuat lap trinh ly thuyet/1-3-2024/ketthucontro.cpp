#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct Point{
	float x,y,z;
	
}; Point;
main(){
	Point *p; // luu trong heap
	p = (Point*)malloc(sizeof(Point));
	p->x = 9 // p->x = (*p).x
	p->y = 8;
	p->z = 5;
	// (p+1)-> x,y,z = ...;
	printf("%f\n",(*p).x);
	
}