#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct Thisinh{
	char ht[30];
	float diem;
	char truong;
};
void input(FILE **file,Thisinh **t,int *n){
	*file = fopen("inputb2.txt", "r");
	if(*file == NULL){
		printf("Error!");
		return;
	}
	fscanf(*file,"%d",n);
	getc(*file);
	*t = (Thisinh*)malloc(*n*sizeof(Thisinh));
	for(int i=0;i<*n;i++){
		fgets((*t+i)->ht,30,*file);
		(*t+i)->ht[strlen((*t+i)->ht)-1] = '\0';
		fscanf(*file,"%f",&(*t+i)->diem);
		fscanf(*file,"%c",&(*t+i)->truong);
	}
	fclose(*file);
}
void print(Thisinh *t,int n){
	for(int i=0;i<n;i++){
		printf("%s\t%.2f\t%c\n",(t+i)->ht,(t+i)->diem,(t+i)->truong);
	}
}
float *tongdiemcactruong(Thisinh *t,int n){
	float *diem = (float*)malloc(4);
	for(int i=0;i<4;i++){
		*(diem+i)=0;
	}
	for(int i=0;i<n;i++){
		if((t+i)->truong == 'A'){
			diem[0] += (t+i)->diem;
		}
		else if((t+i)->truong == 'B'){
			diem[1] += (t+i)->diem;
		}
		else if((t+i)->truong == 'C'){
			diem[2] += (t+i)->diem;
		}
		else if((t+i)->truong == 'D'){
			diem[3] += (t+i)->diem;
		}
	}
	return diem;
}
void inra(FILE **file,Thisinh *t,int n){
	*file = fopen("outputb2.txt", "w");
	float max = 0;
	for(int i=0;i<n;i++){
		if((t+i)->diem > max){
			max = (t+i)->diem;
		}
	}
	fprintf(*file,"Danh sach thi sinh co diem cao nhat la:\n");
	for(int i=0;i<n;i++){
		if((t+i)->diem == max){
			fprintf(*file,"10s | %10.2f | %10c\n",(t+i)->ht,(t+i)->diem,(t+i)->truong);
		}
	}
	fclose(*file);
}

main(){
	FILE *in, *out;
	int n;
	Thisinh *t;
	input(&in,&t,&n);
	print(t,n);
	float *diem = tongdiemcactruong(t,n);
	float max = diem[0];
	int kiemthu = 0;
	for(int i=0;i<4;i++){
		if(diem[i] > max){
			max = diem[i];
			kiemthu = i;
		}
	}
	printf("Truong co tong diem cao nhat la %c", 'A' + kiemthu);
	inra(&out,t,n);
		
}