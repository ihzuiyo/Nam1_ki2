#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char hoten[100];
	float diem;
	char truong;
}Olympic;
void read_input(Olympic **sv,int *n){
	char filename[30];
	FILE *f = fopen("inputde2bai2.txt", "r");
	fscanf(f,"%d ",n);
	*sv = (Olympic*)malloc(*n*sizeof(Olympic));
	for(int i=0;i<*n;i++){
		fgets((*sv+i)->hoten,30,f);
		(*sv+i)->hoten[strlen((*sv+i)->hoten)-1] == '\0';
		fscanf(f,"%f ",&(*sv+i)->diem);
		fscanf(f,"%c ",&(*sv+i)->truong);
	}
	fclose(f);
}
void tongdiemcactruong(Olympic *sv,int n){
	float tong[4] = {0};
	for(int i=0;i<n;i++){
		tong[(sv+i)->truong - 'A'] += (sv+i)->diem;
	}
	printf("DIEM CUA CAC TRUONG LA: \n");
	for(int i=0;i<4;i++){
		printf("Truong %c: %.2f\n",'A'+i,tong[i]);
	}
	float max = tong[0];
	for(int i=0;i<4;i++){
		if(tong[i] > max){
			max = tong[i];
		}
	}
	printf("Truong co tong diem cao nhat la: ");
	for(int i=0;i<4;i++){
		if(tong[i] == max){
			printf("%c ",'A'+i);
			return;
		}
	}
	printf("\n");
}
void thisinhdiemcao(Olympic *sv,int n){
	FILE *f = fopen("outputde2bai2.txt", "w");
	float maxts = -1;
	for(int i=0;i<n;i++){
		if((sv+i)->diem > maxts){
			maxts = (sv+i)->diem;
		}
	}
	printf("\nDANH SACH THI SINH DIEM CAO:\n");
	for(int i=0;i<n;i++){
		if((sv+i)->diem == maxts){
			printf("Ho Ten SV: %s",(sv+i)->hoten);
			printf("Diem : %.2f\n",(sv+i)->diem);
			printf("Truong: %c\n",(sv+i)->truong);
		}
	}
	fprintf(f,"\nDANH SACH THI SINH DIEM CAO:\n");
	for(int i=0;i<n;i++){
		if((sv+i)->diem == maxts){
			fprintf(f,"Ho Ten SV: %s",(sv+i)->hoten);
			fprintf(f,"Diem : %.2f\n",(sv+i)->diem);
			fprintf(f,"Truong: %c\n",(sv+i)->truong);
		}
	}
	fclose(f);
	
}
main(){
	int n;
	Olympic *sv;
	read_input(&sv,&n);
	tongdiemcactruong(sv,n);
	thisinhdiemcao(sv,n);
}