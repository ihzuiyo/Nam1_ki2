#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char name;
	char points;
	char gf;
	char ga;
}Team;
void read_input(Team *a,int n){
	for(int i=0;i<n;i++){
		(a+i)->name = 'A'+i;
		(a+i)->points = 0;
		(a+i)->gf = 0;
		(a+i)->ga = 0;
	}
	char filename[100];
	printf("Nhap ten file: ");
	scanf("%s",filename);
	FILE *f = fopen(filename , "r");
	int nb;
	fscanf(f,"%d ",&nb);
	for(int i=0;i<nb;i++){
		char t1,t2;
		int g1,g2;
		fscanf(f," %c %c %d %d",&t1,&t2,&g1,&g2);
		if(g1 > g2){
			(a+t1-'A')->points += 3;
		}
		else if(g1 < g2){
			(a+t2-'A')->points += 3;
		}
		else{
			(a+t1-'A')->points += 1;
			(a+t2-'A')->points += 1;
		}
		(a+t1-'A')->gf += g1;
		(a+t1-'A')->ga += g2;
		(a+t2-'A')->gf += g2;
		(a+t2-'A')->ga += g1;
	}
	fclose(f);
	printf("%c %d %d %d\n",a->name,a->points,a->gf,a->ga);
}
void print_output(Team *a,int n){
	FILE *f = fopen("outputc.txt", "w");
	fprintf(f,"%6s%10s%6s%6s\n", "Name", "Points", "GF", "GA");
	for(int i=0;i<n;i++){
		fprintf(f,"%6c%10d%6d%6d\n",(a+i)->name,(a+i)->points,(a+i)->gf,(a+i)->ga);
	}
	printf("Danh sach doi bong: \n");
	for(int i=0;i<n;i++){
		printf("%c %d %d %d\n",(a+i)->name,(a+i)->points,(a+i)->gf,(a+i)->ga);
	}
}
int cmp(const void *a,const void *b){
	Team *t1 = (Team*)a;
	Team *t2 = (Team*)b;
	if(t2->points != t1->points){
		return t2->points - t1->points;
	}
	else if((t2->gf - t2->ga) != (t1->gf - t1-> ga)){
		return (t2->gf - t2->ga) - (t1->gf - t1->ga);
	}
	else{
		return t2->gf - t1->gf;
	}
}
main(){
	Team *a;
	int n = 4;
	a = (Team*)malloc(n*sizeof(Team));
	read_input(a,n);
	qsort(a,n,sizeof(Team),cmp);
	print_output(a,n);
	printf("Doi bong dau bang la: %c, So diem: %d\n",a->name,a->points);
	
}