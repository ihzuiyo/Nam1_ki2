#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	float x,y;
}xOy;
void read_input(xOy **diem,int *n){
	char filename[100];
	printf("NHAP TEN FILE: ");
	if(filename == NULL){
		printf("ERROR!");
		return;
	}
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*diem = (xOy*)malloc(*n*sizeof(xOy));
	for(int i=0;i<*n;i++){
		fscanf(f,"%f %f",&(*diem+i)->x,&(*diem+i)->y);
	}
	fclose(f);
}
float distance(xOy diem){
	return sqrt(diem.x*diem.x + diem.y*diem.y);
}
void count(xOy *diem,int n){
	int count_i = 0;
	int count_o = 0;
	for(int i=0;i<n;i++){
		if(distance(*(diem+i)) < 5){
			count_i +=1;
		}
		if(distance(*(diem+i)) > 5){
			count_o +=1;
		}
	}
	printf("Co %d diem nam trong va %d diem nam ngoai\n",count_i,count_o);
}
int doixung(xOy p1,xOy p2){
	if(p1.x+p2.x==0 && p1.y+p2.y==0){
        return 1;
    }
    return 0;
}
void timdiemdoixung(xOy *diem,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(doixung(*(diem+i),*(diem+j))){
				printf("Cap doi xung: [%.2f;%.2f] va [%.2f;%.2f]\n",(diem+i)->x,(diem+i)->y,(diem+j)->x,(diem+j)->y);
			}
		}
	}
	printf("\n");
}
main(){
	int n;
	xOy *diem;
	read_input(&diem,&n);
//	printf("\nTest : [%.2f;%.2f]",(diem+2)->x,(diem+2)->y);
	count(diem,n);
	timdiemdoixung(diem,n);
}
