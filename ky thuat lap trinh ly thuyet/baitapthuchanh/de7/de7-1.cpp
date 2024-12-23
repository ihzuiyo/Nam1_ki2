#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct Diem{
	float x,y;
};
void nhap(Diem **p,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",&filename);
	FILE *f = fopen(filename, "r");
	fscanf(f, "%d ",n);
	*p = (Diem*)malloc(*n*sizeof(Diem));
	for(int i=0;i<*n;i++){
		fscanf(f,"%f%f",&(*p+i)->x,&(*p+i)->y);
	}
	fclose(f);
}
void xuat(Diem *p,int n){
	for(int i=0;i<n;i++){
		printf("[%.2f ; %.2f] ",p[i].x,p[i].y);
	}
	printf("\n");
}
float distance(Diem *p){
	return sqrt(p->x * p->x + p->y * p->y);
}
float timmax(Diem *p,int n){
	float max = distance(p);
	for(int i=1;i<n;i++){
		if(distance(p+i) > max){
			max = distance(p+i);
		}
	}
	return max;
}
int demdoanthangtaoboihaidiemvacattruchoang(Diem *p, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((p+i)->y * (p+j)->y <= 0){
                count++;
            }
            else if((p+i)->x!=(p+j)->x && (p+i)->y*(p+j)->y==0){
                count++;
            }
        }
    }
    return count;
}

main(){
	int n;
	Diem *p;
	nhap(&p,&n);
	xuat(p,n);
	float max = timmax(p,n);
	printf("Cac diem o xa goc toa do nhat la: \n");
	for(int i=0;i<n;i++){
		if(distance(p+i) == max){
			printf("[%.2f ; %.2f] ",p[i].x,p[i].y);
		}
	}
	printf("\n");
	printf("So doan thang tao boi tap nam tren va cat truc hoanh la: %d\n",demdoanthangtaoboihaidiemvacattruchoang(p,n));
	
}