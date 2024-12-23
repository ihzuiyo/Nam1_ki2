#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct Bongda{
	char doinha;
	char doikhach;
	int diemdoinha;
	int diemdoikhach;
};
void nhap(Bongda **b,int *n){
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*b = (Bongda*)malloc(*n*sizeof(Bongda));
	for(int i=0;i<*n;i++){
		fscanf(f,"%c ",&(*b+i)->doinha);
		fscanf(f,"%c ",&(*b+i)->doikhach);
		fscanf(f,"%d ",&(*b+i)->diemdoinha);
		fscanf(f,"%d ",&(*b+i)->diemdoikhach);
	}
	fclose(f);
}
void xuat(Bongda *b,int n){
	printf("DANH SACH TRAN DAU: \n");
	for(int i=0;i<n;i++){
		printf("Tran %d:%c %d - %d %c\n",i+1,(b+i)->doinha,(b+i)->diemdoinha,(b+i)->diemdoikhach,(b+i)->doikhach);
	}
}
void doidandau(Bongda *b,int n){
	int tong[4] = {0};
	for(int i=0;i<n;i++){
		if((b+i)->diemdoinha > (b+i)->diemdoikhach){ // Đội trước thắng đội sau
			tong[(b+i)->doinha - 'A'] += 3;
		}
		else if((b+i)->diemdoinha < (b+i)->diemdoikhach){ // Đội trước thua đội sau
			tong[(b+i)->doikhach - 'A'] += 3;
		}
		else if((b+i)->diemdoinha == (b+i)->diemdoikhach){ // Hòa
			tong[(b+i)->doinha - 'A'] += 1;
			tong[(b+i)->doikhach - 'A'] += 1;
			
		}
	}
	int max = tong[0];
	for(int i=0;i<4;i++){
		if(tong[i] > max){
			max = tong[i];
		}
	}
	for(int i=0;i<4;i++){
		if(tong[i] == max){
			printf("Doi dang dan dau la doi %c voi so diem la %d\n",i+'A',max);
			return;
		}
	}
}
void tinhdiem(Bongda *b,int n,int sodiem[],int sobanthang[],int sobanthua[]){
	for(int i=0; i < n ; i++){
		if((b+i)->diemdoinha > (b+i)->diemdoikhach){
			sodiem[(b+i)->doinha - 'A'] += 3;
			sobanthang[(b+i)->doinha - 'A'] += (b+i)->diemdoinha;
			sobanthua[(b+i)->doinha - 'A'] += (b+i)->diemdoikhach;
			sobanthang[(b+i)->doikhach - 'A'] += (b+i)->diemdoikhach; //phải cộng cả đội thua để tính điểm đội thua
			sobanthua[(b+i)->doikhach - 'A'] += (b+i)->diemdoinha;
		}
		else if((b+i)->diemdoinha < (b+i)->diemdoikhach){
			sodiem[(b+i)->doikhach - 'A'] += 3;
			sobanthang[(b+i)->doikhach - 'A'] += (b+i)->diemdoikhach;
			sobanthua[(b+i)->doikhach - 'A'] += (b+i)->diemdoinha;
			sobanthang[(b+i)->doinha - 'A'] += (b+i)->diemdoinha; // tương tự
			sobanthua[(b+i)->doinha - 'A'] += (b+i)->diemdoikhach;	
		}
		else if((b+i)->diemdoinha == (b+i)->diemdoikhach){
			sodiem[(b+i)->doinha - 'A'] += 1; //Vì 2 đội hòa nên cộng 1 điểm cho cả hai đội
			sodiem[(b+i)->doikhach - 'A'] += 1;
			sobanthang[(b+i)->doikhach - 'A'] += (b+i)->diemdoikhach;
			sobanthua[(b+i)->doikhach - 'A'] += (b+i)->diemdoinha;
			sobanthang[(b+i)->doinha - 'A'] += (b+i)->diemdoinha; // tương tự
			sobanthua[(b+i)->doinha - 'A'] += (b+i)->diemdoikhach;
		}
	}
}
void print_file(Bongda *b,int n){
	int sodiem[4] = {0};
	int sobanthang[4] = {0};
	int sobanthua[4] = {0};
	tinhdiem(b,n,sodiem,sobanthang,sobanthua);
	FILE *f = fopen("output2.txt", "w");
	for(int i=0;i<4;i++){
		fprintf(f,"TEN DOI %c \t SO DIEM: %d \t SO BAN THANG: %d \t SO BAN THUA: %d\n",'A'+i,sodiem[i],sobanthang[i],sobanthua[i]);
	}                                                                                                       
	fclose(f);
}
main(){
	Bongda *b;
	int n;
	nhap(&b,&n);
	xuat(b,n);
	doidandau(b,n);
	print_file(b,n);
}