#include<stdio.h>
#include<math.h>
float area(float x, float y){
	printf("address of x: %p\n", &x);
	printf("address of y: %p\n", &y);
	return x*y;
}
void swap(float *x, float *y){
	float temp = *x;
	*x = *y;
	*y = temp;
	printf("address of x: %p\n", &x);
	printf("address of y: %p\n", &y);
	printf("value of x: %p\n", x);
	printf("value of y: %p\n", y);
}
main(){
	float a = 5;
	float b = 10;
	printf("address of a: %p\n", &a);
	printf("address of b: %p\n", &b); 
	float c = area(a,b);
	printf("address of c: %p\n", &c);
	printf("%.2f\n", c);
	swap (&a,&b);
	return 0;
}