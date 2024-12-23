#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct SV{
	char ht[30];
	int tuoi;
	char que[20];
	float dtp,dt;
}SV;
main(){
 //in
	FILE *f_in;
	f_in = fopen("in.txt","r");
	SV a;
	fgets(a.ht,30,f_in);
	a.ht[strlen(a.ht)-1] = '\0';
	fscanf(f_in,"%d",&a.tuoi);
	fgetc(f_in);
	fgets(a.que,20,f_in);
	a.que[strlen(a.que) - 1]= '\0';
	fscanf(f_in,"%f%f",&a.dtp,&a.dt);
	fclose(f_in);
	printf("%s - %d - %s - %f - %f\n",a.ht,a.tuoi, a.que,a.dtp,a.dt);
		
}