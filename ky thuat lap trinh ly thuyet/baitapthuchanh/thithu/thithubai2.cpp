#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct Bongda{
	char doichunha;
	char doikhach;
	int diemdoinha;
	int diemdoikhach;
};
void nhap(Bongda **bd,int *n){
	char filename[100];
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",n);
	*bd = (Bongda*)malloc(*n*sizeof(Bongda));
	for(int i=0;i<*n;i++){
		fscanf(f,"%c ",&(*bd+i)->doichunha);
		fscanf(f,"%c ",&(*bd+i)->doikhach);
		fscanf(f,"%d ",&(*bd+i)->diemdoinha);
		fscanf(f,"%d ",&(*bd+i)->diemdoikhach);
	}
	fclose(f);
}
void xuat(Bongda *bd,int n){
	printf("DANH SACH TRAN BONG: \n");
	for(int i=0;i<n;i++){
		printf("DOI NHA: %c - DOI KHACH: %c - TI SO: %d - %d\n",(bd+i)->doichunha,(bd+i)->doikhach,(bd+i)->diemdoinha,(bd+i)->diemdoikhach);
	}
}
void tinhdiemdoibong(Bongda *bd,int n){
	int tong[4] = {0};
	char doithang[n];
	char doihoa1[n];
	char doihoa2[n];
	for(int i=0;i<n;i++){
		if((bd+i)->diemdoinha > (bd+i)->diemdoikhach){
			doithang[i] = (bd+i)->doichunha;
		}
		else if((bd+i)->diemdoinha < (bd+i)->diemdoikhach){
			doithang[i] = (bd+i)->doikhach;
		}
		else if((bd+i)->diemdoinha == (bd+i)->diemdoikhach){
			doihoa1[i] = (bd+i)->doichunha;
			doihoa2[i] = (bd+i)->doikhach;
 		}
	}
	for(int i=0;i<n;i++){
		//Thang
		if(doithang[i] == 'A'){
			tong[0] += 3;			
		}
		else if(doithang[i] == 'B'){
			tong[1] += 3;
		}
		else if(doithang[i] == 'C'){
			tong[2] += 3;
		}
		else if(doithang[i] == 'D'){
			tong[3] += 3;
		}
		//Hoa
		if(doihoa1[i] == 'A' && doihoa2[i] == 'B' || doihoa1[i] == 'B' && doihoa2[i] == 'A'){
			tong[0] +=1;
			tong[1] +=1;
		}
		else if(doihoa1[i] == 'C' && doihoa2[i] == 'D' || doihoa1[i] == 'D' && doihoa2[i] == 'C'){
			tong[2] +=1;
			tong[3] +=1;
		}
		else if(doihoa1[i] == 'A' && doihoa2[i] == 'C' || doihoa1[i] == 'C' && doihoa2[i] == 'A'){
			tong[0] +=1;
			tong[2] +=1;
		}
		else if(doihoa1[i] == 'B' && doihoa2[i] == 'D' || doihoa1[i] == 'D' && doihoa2[i] == 'B'){
			tong[1] +=1;
			tong[3] +=1;
		}
		else if(doihoa1[i] == 'A' && doihoa2[i] == 'D' || doihoa1[i] == 'D' && doihoa2[i] == 'A'){
			tong[0] +=1;
			tong[3] +=1;
		}
		else if(doihoa1[i] == 'B' && doihoa2[i] == 'C' || doihoa1[i] == 'C' && doihoa2[i] == 'B'){
			tong[1] +=1;
			tong[2] +=1;
		}
	}
	for(int i=0;i<4;i++){
		printf("So diem cua doi %c la: %d\n",'A'+i,tong[i]);
	}
}
//void print_file(Bongda **bd,int n){
//	FILE *f = fopen("output.txt" , "w");
//	int banthang[n];
//	int banthua[n];
//	for(int i=0;i<n;i++){
//		fprintf(f,"TEN DOI BONG: %c - So diem: %d - So ban thang: %d - So ban thua: %d\n",);
//	}
//	fclose(f);
//}
main(){
	int n;
	Bongda *bd;
	nhap(&bd,&n);
	xuat(bd,n);
	tinhdiemdoibong(bd,n);
}