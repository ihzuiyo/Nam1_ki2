#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char name;
	int score;
	int gs;
	int ga;
}Team;
void read_input(Team *t,int n){
	for(int i=0;i<n;i++){
		(t+i)->name = 'A'+i;
		(t+i)->score = 0;
		(t+i)->gs = 0;
		(t+i)->ga = 0;
	}
	int nb;
	char filename[100];
	printf("Nhap ten FILE: ");
	scanf("%s",filename);
	FILE *f = fopen(filename, "r");
	fscanf(f,"%d ",&nb);
	for(int i=0;i<nb;i++){
		char t1,t2;
		int d1,d2;
		fscanf(f," %c %c %d %d",&t1,&t2,&d1,&d2);
		if(d1 > d2){
			(t+t1-'A')->score += 3;
		}
		else if(d1 < d2){
			(t+t2-'A')->score += 3;
		}
		else{
			(t+t1-'A')->score += 1;
			(t+t2-'A')->score += 1;
		}
		(t+t1-'A')->gs += d1; //So ban thang cua doi 1 trong tran dau
		(t+t1-'A')->ga += d2; //So ban thua cua doi 1 trong tran dau
		(t+t2-'A')->gs += d2; //So ban thang cua doi 2 trong tran dau
		(t+t1-'A')->ga += d1; //So ban thua cua doi 2 trong tran dau
	}
	fclose(f);
}
int cmp(const void *a,const void *b){
	Team *a1 = (Team*)a;
	Team *a2 = (Team*)b;
	if(a2->score != a1->score){
		return a2->score - a1->score;
	}
	else if((a2->gs - a2->ga) != (a1->gs - a1->ga)){
		return (a2->gs - a2->ga) - (a1->gs - a1->ga);
	}
	else{
		return a2->gs - a1->gs;
	}
}
void write_output(Team *t,int n){
	FILE *f = fopen("outputthi2.txt", "w");
	fprintf(f,"%6s %6s %6s %6s\n","NAME","SCORE","GOAL_SCORE","GOAL_AWAY");
	for(int i=0;i<n;i++){
		fprintf(f,"%6c%6d%6d%10d\n",(t+i)->name,(t+i)->score,(t+i)->gs,(t+i)->ga);
	}
	fclose(f);
	printf("DANH SACH DOI BONG: \n");
	for(int i=0;i<n;i++){
		printf("%6c%6d%6d%6d\n",(t+i)->name,(t+i)->score,(t+i)->gs,(t+i)->ga);
	}
}
main(){
	Team *t;
	int n = 4;
	t = (Team*)malloc(n*sizeof(Team));
	read_input(t,n);
	qsort(t,n,sizeof(Team),cmp);
	write_output(t,n);
	printf("DOI DAN DAU LA: %c - DIEM SO: %d",t->name,t->score);
}