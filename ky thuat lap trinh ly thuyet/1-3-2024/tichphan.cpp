#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float tichphan(float (*f)(float), float a,float b, int n){
	float res=0;
	float h = (b-a)/n;
	for(int i=1;i<n;i++){
		res+=f(a+i*h);
	}
	return h/2*(f(a)+f(b)+2*res); // hàm trong hàm
}
float f(float x){
	return pow(x,6) + 3*pow(x,5) + 1;
}
int cmp(const void *a,const void *b){
	int x = *((int*)a); // giá trị của con trỏ a đang trỏ đến
	int y = *((int*)b); // giá trị của con trỏ b đang trỏ đến
	return x-y; //x-y tăng dần , y-x giảm dần
}

main(){
	printf("%f\n",tichphan(sin,0,M_PI,1000));
	printf("%f\n",tichphan(f,0,1,1000));
	int a[5] = {5,9,8,6,10};
	for(int i=0; i<5 ;i++){
		printf("%d ",a[i]);
	}
	
	// sap xep
	
	qsort(a, 5, sizeof(int), cmp);
	printf("\n");
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	//Tổng kết
	// Con trỏ hàm, mảng 2 chiều con trỏ , mảng 2 chiều trong hàm
}
